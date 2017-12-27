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
	for(I=0;I<12;I++){
		file="chilie"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		if(I<5){
			n=3000-rand()%43;k=2+rand()%20;
			lim=40000;
		}else if(I<10){
			lim=1e9;
			n=100000-rand()%450;k=50-rand()%13;
		}else if(I==10){
			n=100000;k=50;lim=1e9;
		}else if(I==11){
			n=100000;k=1;lim=1e9;
		}
		cout<<n<<" "<<k<<endl;
		for(i=0;i<n;i++){
			cout<<lrand()%lim<<" ";
		}
		
		
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<12;I++){
		cmd="std.exe > chilie"+to_string(I)+".out < chilie"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	srand(time(0));
//	make();
	run();
}	
	
	
}Maker;
