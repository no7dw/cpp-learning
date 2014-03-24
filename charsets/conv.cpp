/* f.cpp : 代码转换示例C++程序 */
#include <iconv.h>
#include <iostream>
#include <string.h>
#define OUTLEN 255

using namespace std;

// 代码转换操作类
class CodeConverter {
private:
iconv_t cd;
public:
// 构造
CodeConverter(const char *from_charset,const char *to_charset) 
{
	cd = iconv_open(to_charset,from_charset);
}

// 析构
~CodeConverter() 
{
	iconv_close(cd);
}

// 转换输出
int convert(char *inbuf,int inlen,char *outbuf,int outlen) 
	{
		char **pin = &inbuf;
		char **pout = &outbuf;

		memset(outbuf,0,outlen);
		return iconv(cd,pin,(size_t *)&inlen,pout,(size_t *)&outlen);
	}
};

int main(int argc, char **argv)
{
	char *in_gb2312 = "正在安装";
	char out[OUTLEN];

	// utf-8-->gb2312
	CodeConverter cc = CodeConverter("utf-8","gbk");
	char *in_utf8[5] =   {"01 26涓","02 瀹跺涵鎴愬憳", "03 姘存灉","04 鏁板瓧1鍒","05 浜斿畼"};
	
	for(int i=0;i<5;i++)
	{
		cc.convert(in_utf8[i],strlen(in_utf8[i]),out,OUTLEN);
		cout << "utf-8-->gbk in=" << in_utf8[i] << ",out=" << out << endl;
	}
	// gb2312-->utf-8
	CodeConverter cc2 = CodeConverter("gbk","utf-8");
	for(int i=0;i<5;i++)
	{
		//cc2.convert(in_gb2312,strlen(in_gb2312),out,OUTLEN);
		cc2.convert(in_utf8[i],strlen(in_utf8[i]),out,OUTLEN);
		cout << "gbk-->utf-8 in=" << in_utf8[i] << ",out=" << out << endl;
	}
	
}
