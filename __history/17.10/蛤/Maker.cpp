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

int arr[2][50005];
void make(){
	int i,j,k;int I;int l,m;int n;int lim;


	for(I=10;I<11;I++){
		file="frog"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		printf("%d %d\n",10000,lrand()%(int)(1e8)+1);
		for(i=0;i<10000;i++){
			printf("%d ",lrand()%(int)(1e8)+1);
		}
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=10;I<11;I++){
		cmd="std.exe > frog"+to_string(I)+".out < frog"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	srand(time(0));
	make();
	run();
}	
	
	
}Maker;
