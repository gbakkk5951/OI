using namespace std;
int main(){}
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
const long long mod = 1e18;
struct _Main{
long long lrand(){
	return ((long long)rand()<<47LL) | ((long long)rand()<<32LL) | ((long long)rand()<<17LL) |((long long)rand()<<2LL)^rand();	
}
string file,cmd;
string to_string(int a){
	stringstream os;string ans;
	os<<a;
	os>>ans;
	return ans;
}

int arr[2][50005];
void make(){
	int i,j,k;int I;int l,m;int n;int lim;
	int t;long long t1,t2,t3;

	for(I=0;I<10;I++){
		file="keypool"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		if(I<5)n=50;
		else if(I<7)n=300;
		else if(I<10)n=1000;
		printf("%d\n",n);
		for(i=0;i<n;i++){
			if(I<3){
				t1=1+lrand()%(long long)(1e5);
				t2=1+lrand()%(long long)(1e5);
				if(t1>t2)swap(t1,t2);					
			}
			else if(I<5){
				t1=1+lrand()%(long long)(1e9);
				t2=1+lrand()%(long long)(1e9);
				if(t1>t2)swap(t1,t2);
			}else{
				t1=1+lrand()%(long long)mod;
				t2=1+lrand()%(long long)mod;
				if(t1>t2)swap(t1,t2);				
			}
			if(i>=1000-50){
				t3=2+lrand()%99999;
			}else{
				if(rand()%3000<=60)t3=2;
				else t3=2+lrand()%999;
			}printf("%lld %lld %lld\n",t1,t2,t3);
		}
		
		
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<10;I++){
		cmd="std.exe > keypool"+to_string(I)+".out < keypool"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	srand(time(0));
	make();
	run();
}	
	
	
}Maker;
