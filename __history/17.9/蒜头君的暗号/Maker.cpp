using namespace std;
int main(){}
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
struct _Main{
	
int prime[200];
int cnt;bool vis[200];
void getprime(){
	int i,j;
	for(i=2;i<=150;i++){
		if(!vis[i]){
			prime[cnt++]=i;
		}
		for(j=0;j<cnt && i*prime[j] <=150;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
	
}
	
int lrand(){
	return (rand()<<15) | rand();	
}
string file,cmd;
string to_string(int a){
	stringstream os;string ans;
	os<<a;
	os>>ans;
	return ans;
}

int arr[200];
int str[200];
void make(){
	int i,j,k;int I;int l,m;int n;int lim;int g;


	for(I=1;I<20;I++){
		file="info"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		if(I<8){
			n=10;g=50+lrand()%30;
		}else if(I<13){
			n=30;g=100+lrand()%50;
		}else if(I<20){
			n=200;g=(1e8)-lrand()%700;
		}
		if(I<17){
			for(i=1;i<=n;i++){
				arr[i]=i;
			}
			for(i=2;i<=n;i++){
				swap(arr[lrand()%i+1],arr[i]);
			}
		}else{
			j=0;
			for(i=1;i+prime[j]<=n;i+=prime[j],j++){
				for(k=1;k<prime[j];k++){
					arr[i+k-1]=i+k;
				}
				arr[i+prime[j]-1]=i;
			}
			for(j=i;i<=n;i++){
				arr[i]=i;
			}
			for(i=j+1;i<=n;i++){
				swap(arr[i],arr[j+rand()%(i-j+1)]);
			}
		}
		printf("%d %d\n",n,g);
		for(i=1;i<n;i++){
			printf("%d ",arr[i]);
		}printf("%d\n",arr[n]);
		if(I<13){
			lim=n;
		}else{
			lim=n-rand()%17;
		}
		for(i=1;i<=lim;i++){
			if(rand()%10==0){
				putchar(' ');
			}else{
				if(rand()&1){
					putchar('a'+rand()%26);
				}else{
					putchar('A'+rand()%26);
				}
			}
		}
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<20;I++){
		cmd="std.exe > info"+to_string(I)+".out < info"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	getprime();
	srand(time(0));
	make();
	run();
}	
	
	
}Maker;
