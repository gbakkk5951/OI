using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>

struct _Main{
void make(){
	int i,j,k;int n,need;int I,J,K;
	for(I=4;I<20;I++){
		sprintf(out,"loop%d.in",I);
		freopen(out,"w",stdout);
		if(I<5)n=5;
		else if(I<10)n=18;
		else if(I<20)n=100;
		need=1+rand()%n;
		
		if(I==19 || I==16)need=n;
		num[0]=rand()%9+1+'0';
		for(i=1;i<n;i++){
			num[i]=rand()%10+'0';
		}num[n]='\0';
		printf("%s %d",num,need);
		fclose(stdout);
	}
	
	
	
	
}
void run(){
	int I;
	for(I=0;I<20;I++){
		sprintf(in,"loop%d.in",I);
		sprintf(out,"loop%d.out",I);
		sprintf(cmd,"std.exe > %s < %s",out,in);
		system(cmd);
	}
	
	
	
}
	
char num[510];
char cmd[100],in[20],out[20];

_Main(){
	srand(time(0));
	run();
	
	
	
	
}


	
}Maker;
