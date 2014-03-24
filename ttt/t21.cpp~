#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int deconstruct_bnbt_torrent_http_path(const char* srcPath, char *torrent_hash)
{
	if(!torrent_hash)
		return -1;
	
	const char *p1 = srcPath;
	strncpy(torrent_hash, p1+strlen(srcPath)-40,  40);
	return 0;
}
int construct_bnbt_torrent_http_path(const char* Torrent_IP_Port_Hash, char *torrent_path)
{
	if(!Torrent_IP_Port_Hash)
	{
		printf("Torrent_IP_Port_Hash is empty!\n");
		return -1;
	}
	char bnbt_server_ip_port[200];memset(bnbt_server_ip_port, 0 , sizeof(bnbt_server_ip_port));
	char hash[40+1];memset(hash, 0 , sizeof(hash));
	
	const char *p_ip_port = strchr(Torrent_IP_Port_Hash,'@');
	
	if( p_ip_port !=NULL  )
	{		
		strncpy(bnbt_server_ip_port, Torrent_IP_Port_Hash ,strlen(Torrent_IP_Port_Hash) - 40-1);//'@'
		strncpy(hash, p_ip_port+1, 40 );//'@' + 1
	}
	
	strcat(torrent_path ,  "http://");
	strncat(torrent_path , bnbt_server_ip_port, strlen(bnbt_server_ip_port));
		
	strcat(torrent_path ,"/torrent.html?info_hash=");
	strncat(torrent_path ,hash, 40);		
	return 0;
}

int main(void)
{
	char hash[40+1];memset(hash, 0, sizeof(hash));
	deconstruct_bnbt_torrent_http_path("http://192.168.2.160:6969/stats.html?info_hash=5e6f3ccdd9caa5622d199c2aa269e060440d02a2",hash);
	printf("hash = %s\n",hash);

	char path[256];memset(path, 0, sizeof(path));
	construct_bnbt_torrent_http_path("192.168.2.160:6969@5e6f3ccdd9caa5622d199c2aa269e060440d02a2", path);
	printf("path = %s\n",path);
}
