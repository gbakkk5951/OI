using namespace std;
int main(){}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

struct _Main{
bool small;	
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
int gap[2005];
void make(){
	int i,j,k;int I;int l,m;int n;int lim;int g;
	int hp,hpmx,atk,atkmx,hpadd;int block;int e;

	for(I=0;I<25;I++){
		file="grid"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		if(I<5){//随机树 
			if(I&1)n=300;
			else n=300-rand()%130;
			if(small)n=6+rand()%2;
			if(I%3!=1){
				m=2;
			}else{
				m=3+lrand()%(n-2);
			}
			n=7;m=2;
			printf("%d %d %d\n",n,m,I==3?n-m+1:lrand()%(n-m+1)+1);
			for(i=2;i<=n;i++){
				printf("%d %d %d\n",lrand()%(i-1)+1,i,I==3?(int) 1e5-rand()%1000:lrand()%((int)1e5+1));
			}
		}else if(I<10){//菊花图 
			if(!I&1)n=300;
			else n=300-rand()%130;
			if(small)n=6+rand()%2;
			if(I%3!=1){
				m=2;
			}else{
				m=3+lrand()%(n-2);
			}			
			printf("%d %d %d\n",n,m,I==6?n-m+1:lrand()%(n-m+1)+1);
			for(i=2;i<=n;i++){
				printf("%d %d %d\n",i,1,I==6?(int) 1e5-rand()%1000:lrand()%((int)1e5+1));
			}
		}else if(I<15){//菊花链 
			if(!I&1)n=300;
			else n=300-rand()%130;
			if(small)n=6+rand()%2;
			if(I%3!=1){
				m=2;
			}else{
				m=3+lrand()%(n-2);
			}	
			printf("%d %d %d\n",n,m,I==12?n-m+1:lrand()%(n-m+1)+1);
			lim=n/2+rand()%(n/4);
			for(i=2;i<=lim;i++){
				printf("%d %d %d\n",i,1,I==12? (int)1e5-rand()%1000:lrand()%((int)1e5+1));
			}
			for(i=lim+1;i<=n;i++){
				printf("%d %d %d\n",i,i-1,I==12?(int) 1e5-rand()%1000:lrand()%((int)1e5+1));
			}
		}else if(I<20){//链 
			if(!I&1)n=300;
			else n=300-rand()%130;
			
			if(small)n=6+rand()%2;
			if(I%3!=1){
				m=2;
			}else{
				m=3+lrand()%(n-2);
			}
			printf("%d %d %d\n",n,m,I==18?n-m+1:lrand()%(n-m+1)+1);
			for(i=2;i<=n;i++){
				printf("%d %d %d\n",i,i-1,I==18?(int) 1e5-rand()%1000:lrand()%((int)1e5+1));
			}
		}else if(I<25){//随机树 
			if(I&1)n=300;
			else n=300-rand()%130;
			if(small)n=6+rand()%2;
			
			if(I%3!=1){
				m=2;
			}else{
				m=3+lrand()%(n-2);
			}
			printf("%d %d %d\n",n,m,I==23?n-m+1:lrand()%(n-m+1)+1);
			for(i=2;i<=n;i++){
				printf("%d %d %d\n",lrand()%(i-1)+1,i,I==23?(int) 1e5-rand()%1000:lrand()%((int)1e5+1));
			}			
		}
		fclose(stdout);
	}
	
	
	
}
int totcnt;
void run(){
	int I;
	cmd="output"+to_string(totcnt/25)+".res";
	freopen(cmd.c_str(),"w",stdout);
	for(I=0;I<25;I++){
		
		cerr<<"["<<I+totcnt<<"]"<<endl;
		
		cmd="std.exe > grid"+to_string(I)+".out < grid"+to_string(I)+".in";
		system(cmd.c_str());		
		cmd="lyd.exe > lyd"+to_string(I)+".out < grid"+to_string(I)+".in";
		system(cmd.c_str());
		cmd="fc lyd"+to_string(I)+".out  grid"+to_string(I)+".out";
		system(cmd.c_str());
	}
	cerr<<"请按任意键继续. . . "<<endl;
	totcnt+=25;
}
	
_Main(){
	getprime();
small=false;
srand(time(0));
while(1){
	make();
	run();	
	getchar();
}
	

}	
	
	
}Maker;
