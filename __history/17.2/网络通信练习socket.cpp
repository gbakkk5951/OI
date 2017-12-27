#include<cstdio>
#include<winsock2.h>
#include<cstdlib>
#pragma  comment(lib,"ws2_32.lib")
#include<string.h>

int main()
{
	SOCKET a;
	a=socket(AF_INET,SOCK_STREAM,0);
}
