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
	for(I=1;I<15;I++){
		file="num"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		if(I==9){
			n=100000;m=lrand()%((int)1e9)+1;
		}else if(I<5){
			n=10+rand()%3;m=lrand()%10000+1;
		}else if(I<10){
			n=100-rand()%17;m=lrand()%((int)1e9)+1;
		}else if(I<15){
			n=1+rand()%17;m=lrand()%500+1;
		}
		cout<<n<<" "<<m<<endl;
		for(i=0;i<n;i++){
			cout<<rand()%100+1<<" ";
		}cout<<endl;
		
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<15;I++){
		cmd="std.exe > num"+to_string(I)+".out < num"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	srand(time(0));
//	make();
	run();
}	
	
	
}Maker;
