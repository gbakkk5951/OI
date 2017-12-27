using namespace std;
int main(){}
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
#include<iostream>
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
void make(){
	int i,j,k;int I;int l,m;int n;int lim;
	int m1=1e6,m2=1e8;
	for(I=0;I<19;I++){
		file="minigame"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		printf("%d",I+2);
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<18;I++){
		cmd="std.exe > minigame"+to_string(I)+".out < minigame"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	srand(time(0));
	make();
	run();
}	
	
	
}Maker;
