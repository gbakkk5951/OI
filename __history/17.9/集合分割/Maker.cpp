#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
char out[20],in[20];
int arr[2005];
const int mod = 1e6;
int lrand(){
	return (rand()<<15)|rand();
}



void make(){
	int i,j,k;int I,J,K;
	int n,m;
	for(I=0;I<20;I++){
		if(I==1)continue;
		sprintf(out,"set%d.in",I);
		freopen(out,"w",stdout);
		if(I<5)n=10;
		else if(I<10)n=800-rand()%300;
		else if(I<15)n=2000-rand()%179;
		else if(I>=15)n=2000;
		
		m=rand()%(n-1)+1;
		if(I==12)m=50+rand()%300;
		if(I==14)m=0;
		if(I==9)m=n;
		if(m>1000)m=rand()%1000+1;
		if(m==0)m=1;
		i=0;
		if(I%6==0){
			for(i=0;(i*2)<n-m && i+1<n && i<50;i+=2){
				arr[i]=arr[i+1]=lrand()%mod;
			}
		}
		for(;i<n;i++){
			arr[i]=lrand()%mod;
		}
		for(i=1;i<n;i++){
			
			swap(arr[i],arr[rand()%i]);
		}
		printf("%d %d\n",n,m);
		for(i=0;i<n;i++){
			if(arr[i]==0)arr[i]=1;
			printf("%d ",arr[i]);
		}
		fclose(stdout);
	}
	
	
	
}
char cmd[100];
void run(){
	int I;
	for(I=0;I<20;I++){
		sprintf(in,"set%d.in",I);
		sprintf(out,"set%d.out",I);
		sprintf(cmd,"std.exe > %s < %s",out,in);
		system(cmd);
		
	}
}


int main(){
	srand(time(0));
	make();
	run();
	
}
