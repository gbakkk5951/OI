#include<cstdio>
int main(){}
using namespace std;
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<ctime>
#include<cstdlib>

struct _Main{
void run(){
	int i;
	for(i=0;i<13;i++){
		in="pen"+to_string(i)+".in";
		out="pen"+to_string(i)+".out";
		cmd="std.exe > "+out+" < "+in;
		system(cmd.c_str());
	}
	
	
}

string out,in,cmd;
string to_string(int a){
	stringstream os;
	string ret;
	os<<a;
	os>>ret;
	return ret;
}
string tmp;
void make(){
	
	int I,i,j,k,l,m,n;
	for(I=2;I<13;I++){
		out="pen"+to_string(I)+".in";
		freopen(out.c_str() ,"w",stdout);
		if(I==3)m=1;
		else if(I<5)m=70-rand()%50;
		else if(I<10)m=100-rand()%3;
		else if(I==10)m=9;
		else if(I==11)m=17;
		else m=100-rand()%23;
		if(I<5){
			n=10;
		}else if(I<13){
			if(rand()&1)
			n=60;
			else n=60-rand()%13;
		}
		if(I==12)n=17;
		if(I<5){
			l=20;
		}else if(I<13){
			l=60;
		}
		cout<<n<<" "<<m<<endl;
		if(I==3){
			cout<<"AGVXZ"<<endl;
		}else if(I==7){
			tmp="AFDJOIRQ";
			for(i=0;i<n;i++){
				tmp+=(char)(rand()%26+'A');
				cout<<tmp<<endl;
			}
		}else if(I==5){
			for(i=0;i<n;i++){
				tmp=(char)(rand()%26+'A')+tmp;
				cout<<tmp<<endl;
			}			
		}else{
			for(i=0;i<n;i++){
				k=rand()%l+1;
				for(j=0;j<k;j++){
					cout<<(char)(rand()%26+'A');
				}cout<<endl;
			}			
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
