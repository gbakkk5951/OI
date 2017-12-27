int main(){}
using namespace std;
#include<cstdio>
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<sstream>

struct _Main{
inline string to_string(int a){
	string ret;stringstream tmp;
	tmp<<a;
	tmp>>ret;
	return ret;
}
string in,out,cmd;
void make(){
	int I;int i,j,k,l;int a,b,c;int n,m;
	for(I=3;I<10;I++){
		out="prize"+to_string(I)+".in";
		freopen(out.c_str(),"w",stdout);
		if(I<5){
			n=5-rand()%5;
			m=1+rand()%20;
		}else{
			n=10-rand()%3;
			m=100-rand()%20;
			if(I==8)n=10;
		}
		cout<<n<<" "<<m<<endl;
		for(i=0;i<n;i++){
			l=1+rand()%100;
			if(I==8)l=100;
			for(j=0;j<l;j++){
				cout<<(char)('a'+rand()%4);
			}cout<<" ";
			if(I==8 && i==3)cout<<0<<endl;
			else if(rand()&1){
				cout<<-(rand()%1001)<<endl;
			}else{
				cout<< (rand()%1001)<<endl;
			}
		}
		
		fclose(stdout);
	}
	
	
}
void run(){
	int i;
	for(i=0;i<10;i++){
		cmd="std.exe > prize"+to_string(i)+".out < prize"+to_string(i)+".in";
		system(cmd.c_str());
	}
	
	
}

_Main(){
	srand(time(0));
	make();
	run();
}
	
	
	
	
}Maker;
