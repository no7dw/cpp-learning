#include <stdlib.h>

int main(void)
{
	system("ifconfig eth0 > /tmp/hdd/root/ip");
	system("route -n > /tmp/hdd/root/gw");
}
