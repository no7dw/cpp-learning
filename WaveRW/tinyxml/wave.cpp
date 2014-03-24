#include "wave.h"


static const int tagRIFF_FOURCC = 0x46464952;
static const int tagWAVE_FOURCC = 0x45564157;
static const int tagfmt_FOURCC = 0x20746d66;
static const int tagdata_FOURCC = 0x61746164;                            

void OnGain(void *buf, unsigned size_buf, unsigned igain);

 int SearchChunk(FILE *fp, int FOURCC_Chunk)
{
        int *pFOURCC;
        int ReadLen;
        char Buffer[100];

        fseek(fp, 0, SEEK_SET);
        ReadLen = fread(Buffer, sizeof(char), 100, fp);
        for (int i = 0; i < ReadLen - 4; i++) {
                pFOURCC = (int *) (&Buffer[i]);
                if (*pFOURCC == FOURCC_Chunk) {
                        return i;
                }
        }   

        return (-1);
}


 bool GenWaveFileInSec( const char *szWaveFileName, const char *szPCMFileName, int start_sec, int end_sec)
{
	short BitsPerSample;
	short Channels;
	int SamplesPerSec;
	int Indel;
	short *szBuffer;
	int szBufferSize;

	FILE *pFile = fopen(szWaveFileName, "r");
	if (pFile == NULL) {
		printf("[%s,%s,%d] Open Wave file failed.\n",__FILE__,__func__,__LINE__);
		return false;
	}
	//printf("szWaveFileName = %s\n", szWaveFileName);

	if (SearchChunk(pFile, tagRIFF_FOURCC) < 0 || SearchChunk(pFile, tagWAVE_FOURCC) < 0) {
		fclose(pFile);
		return false;
	}

	//定位wave资源"fmt"标志
	Indel = SearchChunk(pFile, tagfmt_FOURCC);

	//获取wave资源声道数目
	fseek(pFile, Indel + 10, SEEK_SET);
	fread(&Channels, sizeof(Channels), 1, pFile);

	//获取wave资源采样频率
	fseek(pFile, Indel + 12, SEEK_SET);
	fread(&SamplesPerSec, sizeof(SamplesPerSec), 1, pFile);
	//printf("\n%d\t", SamplesPerSec);

	//获取wave资源采样精度
	fseek(pFile, Indel + 22, SEEK_SET);
	fread(&BitsPerSample, sizeof(BitsPerSample), 1, pFile);
	//printf("%d\t", BitsPerSample);

	//定位wave资源"data"标志
	Indel = SearchChunk(pFile, tagdata_FOURCC);
	fseek(pFile, Indel + 4, SEEK_SET);
	fread(&szBufferSize, sizeof(szBufferSize), 1, pFile);
	//printf("%d\t", szBufferSize);

	//szBufferSize = szBufferSize / 2;//仅双声道需要
	//printf("%d\n", szBufferSize);


	
	//long long read_size = SamplesPerSec * (end_sec - start_sec ) * BitsPerSample * Channels/8000;//读取的大小	//BUG 溢出 会是负数
	
	long long read_size = SamplesPerSec/1000 * (end_sec - start_sec ) * BitsPerSample * Channels/8;//读取的大小	//FIXME SamplesPerSec 先 /1000
	printf("read_size = %d\n", read_size);
 	szBufferSize = read_size;	
		
	long long read_pos = SamplesPerSec/1000 * start_sec  * BitsPerSample * Channels/8;//读取的开始位置
	printf("read_pos = %d\n", read_pos);

	szBuffer = (short *) malloc(szBufferSize);

	if (szBuffer == NULL) {
		fclose(pFile);
		printf("[%s,%s,%d] malloc szbuffer failed.\n",__FILE__,__func__,__LINE__);
		return false;
	}
	
	fseek(pFile, Indel + 8 + read_pos , SEEK_SET);//设定偏移量
	for (int i = 0; i < szBufferSize / sizeof(short); i++) {
		fread(&szBuffer[i], 2, 1, pFile);
	//	fseek(pFile, 2, SEEK_CUR);//仅双声道需要
	}
	
	fclose(pFile);

	//OnGain(szBuffer, szBufferSize,3);//降溢 
		
	FILE *ppFile = fopen(szPCMFileName, "w+");
	fwrite(szBuffer, szBufferSize, 1, ppFile);
	fclose(ppFile);

	free(szBuffer);

	return true;
}


 void OnGain(void *buf, unsigned size_buf, unsigned igain)
{
        int i;
        short *buff = (short *) buf;

        if (igain > 4) {
                igain = 4;
        }

        for (i = 0; i < size_buf / sizeof(short); ++i) {
                if (*(buff + i) < 0) {
                        *(buff + i) = (*(buff + i) << 0x1) >> (igain + 1) | 0x1 << 15;
                } else {
                        *(buff + i) >>= igain;
                }
        }
}
