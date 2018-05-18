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
		file="prism"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		memset(gap,0,sizeof(gap));
		if(I<5){//随机森林 
			n=rand()%2000+1;
			block=rand()%n+1;
			e=n-block;
			for(i=1;i<block;i++){
				gap[i]=1;
			}
			for(i=2;i<n;i++){
				swap(gap[i],gap[lrand()%i+1]);
			}
			int lst=1;int test=0;
			for(i=1;i<=n;i++){
				if(i>lst){
					test++;
					printf("%d %d\n",lst+rand()%(i-lst),i);
				}
				if(gap[i]){
					lst=i+1;
				}
			}
			if(test!=e){
				cerr<<"wrong"<<endl;
			}
		}else if(I<10){//随机树 
			n=2000-rand()%300;
			e=n-1;
			for(i=2;i<=n;i++){
				printf("%d %d\n",lrand()%(i-1)+1,i);
			}
		}else if(I==10){//单点森林 
			n=rand()%2000+1;
			block=n;
			e=n-block;
			for(i=1;i<block;i++){
				gap[i]=1;
			}
			for(i=2;i<n;i++){
				swap(gap[i],gap[lrand()%i+1]);
			}
			int lst=1;int test=0;
			for(i=1;i<=n;i++){
				if(i>lst){
					test++;
					printf("%d %d\n",lst+rand()%(i-lst),i);
				}
				if(gap[i]){
					lst=i+1;
				}
			}
			if(test!=e){
				cerr<<"wrong"<<endl;
			}
		}else if(I<15){//菊花图 
			n=2000-rand()%300;
			e=n-1;
			printf("%d %d %d 0.00\n",n,m,e);
			for(i=2;i<=n;i++){
				printf("%d %d\n",i,1);
			}
		}else if(I<20){//菊花链 
			n=2000-rand()%300;
			if(I%5==0)n=2000;
			e=n-1;
			m=rand()%2;
			printf("%d %d %d 0.00\n",n,m,e);
			lim=800+rand()%300;
			for(i=2;i<=lim;i++){
				printf("%d %d\n",i,1);
			}
			for(i=lim+1;i<=n;i++){
				printf("%d %d\n",i,i-1);
			}			
		}else if(I<25){//链 
			n=2000-rand()%300;
			if(I%5==0)n=2000;
			e=n-1;
			m=rand()%2;
			printf("%d %d %d 0.00\n",n,m,e);			
			for(i=2;i<=n;i++){
				printf("%d %d\n",i,i-1);
			}			
		}

		
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<25;I++){
		cmd="std.exe > prism"+to_string(I)+".out < prism"+to_string(I)+".in";
		system(cmd.c_str());
	}
}
	
_Main(){
	getprime();
	srand(time(0));
//	make();
	run();
}	
	
	
}Maker;
