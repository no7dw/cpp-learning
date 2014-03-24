#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

static const int tagRIFF_FOURCC = 0x46464952;
static const int tagWAVE_FOURCC = 0x45564157;
static const int tagfmt_FOURCC = 0x20746d66;
static const int tagdata_FOURCC = 0x61746164;                            

static int SearchChunk(FILE *fp, int FOURCC_Chunk)
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


static bool GenWaveFileInSec( const char *szWaveFileName, const char *szPCMFileName, float start_sec, float end_sec)
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
	printf("szWaveFileName = %s\n", szWaveFileName);

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
	printf("%d\n", SamplesPerSec);

	//获取wave资源采样精度
	fseek(pFile, Indel + 22, SEEK_SET);
	fread(&BitsPerSample, sizeof(BitsPerSample), 1, pFile);
	printf("%d\n", BitsPerSample);

	//定位wave资源"data"标志
	Indel = SearchChunk(pFile, tagdata_FOURCC);
	fseek(pFile, Indel + 4, SEEK_SET);
	fread(&szBufferSize, sizeof(szBufferSize), 1, pFile);
	printf("%d\n", szBufferSize);

	szBufferSize = szBufferSize / 2;
	printf("%d\n", szBufferSize);

	int read_size = SamplesPerSec * (end_sec - start_sec ) * BitsPerSample * Channels/8;//读取的大小
	printf("read_size = %d\n",read_size);
 	szBufferSize = read_size;	

	int read_pos = SamplesPerSec * start_sec * BitsPerSample * Channels/8;//读取的开始位置
	printf("read_pos = %d\n",read_pos);

	szBuffer = (short *) malloc(szBufferSize);

	if (szBuffer == NULL) {
		fclose(pFile);
		printf("[%s,%s,%d] malloc szbuffer failed.\n",__FILE__,__func__,__LINE__);
		return false;
	}
	
	fseek(pFile, Indel + 8 + read_pos , SEEK_SET);//设定偏移量
	for (int i = 0; i < szBufferSize / sizeof(short); i++) {
		fread(&szBuffer[i], 2, 1, pFile);
	//	fseek(pFile, 2, SEEK_CUR);//双声道
	}

	fclose(pFile);

	FILE *ppFile = fopen(szPCMFileName, "w+");
	fwrite(szBuffer, szBufferSize, 1, ppFile);
	fclose(ppFile);

	free(szBuffer);

	return true;
}

int main(int argc , char **argv)
{
	if(argc<4){
		printf("genwave source_wave_file target_pcm_file start_sec end_sec\n");
		return -1;
	}
	float start_sec = atof(argv[3]);
	float end_sec = atof(argv[4]);
	GenWaveFileInSec(argv[1],argv[2] , start_sec , end_sec);
	
	return 0;
}
