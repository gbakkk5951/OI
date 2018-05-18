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

int fact[10];

void revcantor(int val,char *matrix){
	int i,j,n,d;char vis=0;
	for(i=0;i<8;i++){
		n=val%fact[8-i]/fact[8-i-1];
		for(j=0,d=0;j<8;j++)if(!(vis&(1<<j))){
			if(d==n){
				break;
			}d++;
		}vis|=(1<<j);
		matrix[i]=j+'1';
	}matrix[8]='\0';
}
void make(){
	int i,j,k;int I;int l,m;int n;int lim;char matrix[10];
	int mod;
	fact[0]=1;
	for(i=1;i<=8;i++){
		fact[i]=fact[i-1]*i;
	}mod=fact[8];

	for(I=0;I<15;I++){
		file="matrix"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		revcantor(lrand()%mod,matrix);
		puts(matrix);
		revcantor(lrand()%mod,matrix);
		puts(matrix);		
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<15;I++){
		cmd="std.exe > matrix"+to_string(I)+".out < matrix"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	srand(time(0));
	make();
	run();
}	
	
	
}Maker;
