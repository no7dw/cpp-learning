#include <string.h>
#include <stdio.h>
#include <assert.h>
char *strcpy2(char *dest, const char* src)
{
	assert(src!= NULL);
	char *s = dest;
	s = dest;
	while(   (*s++ = *src++) != '\0');
	return dest;
}

char *strchr2(const char*s, int c)
{
	const char ch = c;
	for( ;*s!=ch ;s++)
		if(*s == '\0')
			return NULL;
	return (char*)s;
}
char *strstr2(const char*s1, const char*s2)
{
	if(*s2 == '\0')
		return (char*)s1;

	for( ; (s1 =strchr(s1, *s2))!=NULL  ;s1++ )
	{
		const char *sc1, *sc2;
		for(sc1= s1,sc2 = s2; ;)
			if(*++sc2 =='\0' )
				return (char*)s1;
			else if( *++sc1 != *sc2 )
				break;
			
	}
}
int main(void)
{
	char str[10] = "abcdefg";
	char dest[20] ;memset(dest, 0,sizeof(dest) );
	strcpy2(dest, str );
	printf("src %s\t", str);
	printf("dest %s \n", dest);

	char c ='d';
	printf("strchr %s %c %s\n", str, c, strchr2(str, c));
	
	const char* cc ="de";
	printf("strchr %s %s %s\n", str, cc, strstr2(str, cc));
}
