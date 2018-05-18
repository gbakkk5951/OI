using namespace std;
int main(){}
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
string ToString(int a){
	stringstream os;
	string ret;
	os<<a;
	os>>ret;
	return ret;
}
struct _Main{
void run(){
	int i;
	for(i=0;i<12;i++){
		in="info"+ToString(i)+".in";
		out="info"+ToString(i)+".out";
		cmd="std.exe > "+out+" < "+in;
		system(cmd.c_str() );
	}
	
}	
string in,out,cmd;
void make(){
	int i,j,k;int l,m,n;
	for(i=0;i<11;i++){
		out="info"+ToString(i)+".in";
		freopen(out.c_str() ,"w",stdout);
		
		if(i==0){
			n=4;
			cout<<n<<endl;
			for(j=0;j<4;j++){
				cout<<(char)('A'+j)<<endl;
			}
			for(k=0;k<1000;k++){
				cout<<(char)('A'+rand()%4);
			}cout<<endl;
		}else if(i<5){
			n=rand()%20+1;
			cout<<n<<endl;
			for(j=0;j<n;j++){
				l=rand()%10+1;
				for(k=0;k<l;k++){
					cout<<(char)('A'+rand()%4);
				}cout<<endl;
			}
			for(j=0;j<300;j++){
				cout<<(char)('A'+rand()%4);
			}cout<<endl;
		}else if(i<10){
			n=50;
			cout<<n<<endl;
			for(j=0;j<n;j++){
				l=rand()%20+1;
				for(k=0;k<l;k++){
					cout<<(char)('A'+rand()%4) ;
				}cout<<endl;
			}
			for(j=0;j<1000;j++){
				cout<<(char)('A'+rand()%4);
			}cout<<endl;
			
		}else{
			n=50;
			cout<<n<<endl;
			for(j=0;j<n;j++){
				l=20;
				for(k=0;k<l;k++){
					cout<<(char)('A'+rand()%4) ;
				}cout<<endl;
			}
			for(j=0;j<1000;j++){
				cout<<(char)('A'+rand()%4);
			}cout<<endl;			
			
		}
		
		
		fclose(stdout);
		
	}
	
} 	
	
	
_Main(){
	srand(time(0));
//	make();
	run();
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}Maker;
