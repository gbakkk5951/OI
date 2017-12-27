#include<cstdio>
#include<WinSock2.h>
#include<windows.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;
int main()
{LoadLibrary("C:\\WINDOWS\\system32\\ws2_32.dll");
    	SOCKET a,b;
	a=socket(AF_INET,SOCK_STREAM,0);
	b=socket(2,2,0);
	printf("%d %d",(int)a,(int)b);
    getchar();
}
