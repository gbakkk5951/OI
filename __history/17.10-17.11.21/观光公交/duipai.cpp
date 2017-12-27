#include<windows.h>
#include<stdio.h>
int main()
{
	int cnt=1;
	while(1)
	{
		printf("#%d:\n",cnt++);
		system("maker.exe > in.txt");
		system("std.exe < in.txt > std.txt");
		system("ezoj1152观光公交.exe < in.txt > bus.txt");
		if(system("fc std.txt bus.txt")){printf("WA!!!\n");system("pause");}
	}
	return 0;
}
