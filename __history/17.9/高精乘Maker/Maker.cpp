#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
int main(){};
char p1[]="高精度乘法.exe > ";
char p2[]=" < ";
char str[200];
struct _Main{


char Input[50],Output[50];

_Main(){
	srand(time(0));
	int i,j,k;int I;
	
	for(I=1;I<=20;I++){
		sprintf(Input,"FFT%d.in",I-1);
		sprintf(Output,"FFT%d.out",I-1);
		freopen(Input,"w",stdout);
		putchar('1'+rand()%9);
		for(i=1;i<100000;i++){
			putchar('0'+rand()%10);
		}putchar('\n');
		putchar('1'+rand()%9);
		for(i=1;i<100000;i++){
			putchar('0'+rand()%10);
		}
		fclose(stdout);
		memset(str,0,sizeof(str));
		strcat(str,p1);strcat(str,Output);strcat(str,p2);strcat(str,Input);
		system(str);		
	}

	
}

	
	
}Maker;
