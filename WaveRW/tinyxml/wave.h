#ifndef __WAVE_H
#define __WAVE_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

                        
 ///@Summary: 从文件中查找指定的标记
 ///@Return: 返回偏移量
 int SearchChunk(FILE *fp, int FOURCC_Chunk);
 
 ///@Summary: 根据wav文件与指定的时间段 产生指定部分的pcm文件
 ///@Param ：1 源wav文件 路径
 ///@Param ：2 生成pcm文件路径
 ///@Param ：3 开始时间点(毫秒)
 ///@Param ：4 结束时间点(毫秒)
 ///@Return: 成功返回true
 bool GenWaveFileInSec( const char *szWaveFileName, const char *szPCMFileName, int start_sec, int end_sec);


#endif