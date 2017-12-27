int main(){}
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<ctime>
#include<sstream>
#include<algorithm>

struct _Main{
string to_string(int a){
	string tmp;
	stringstream s;
	s<<a;
	s>>tmp;
	return tmp;
}	
string word[5000];
string in,out,cmd;
void make(){
	int i,j,k;int I;
	int a,b,c;int n;
	int len;  int l;
	for(I=0;I<10;I++){
		
		out="book"+to_string(I)+".in";
		freopen(out.c_str() ,"w",stdout);
		if(I==1){
			cout<<"1"<<endl<<"sb"<<endl;
			cout<<'b';
			for(i=1;i<50000;i++){
				cout<<'s';
			}
			for(i=0;i<49999;i++){
				cout<<'b';
			}
			cout<<'s';
			cout<<endl;	
			continue;
		}
		if(I<5){
			n=10;
			len=3000;
		}else{
			n=5000;
			len=100000;
		}
		
		if(n==10)l=100;
		else l=16;
		for(i=0,j=4;i<n;i++){
			if(n==10 &&i==5){
				l=5;j=3;
			}else if(n==10 && i==7){
				l=3;j=2;
			}else if(n==10 && i==9){
				l=1;j=1;
			}else if(n==10 && i==10){
				l=250;j=0;
			}
			
			if(i==(5-j)*1000){
				l-=3;j--;
			}
			word[i]=(char)'a'+j;
			for(k=1;k<l;k++){
				word[i]+=(char)(j+(rand()%(26-j))+'a');
			}
		}
		sort(word,word+n);
		n=unique(word,word+n)-word;
		cout<<n<<endl;
		for(i=0;i<n;i++)cout<<word[i]<<endl;
		int rem=len;int lim=45;
		if(I==7)lim=30;
		if(I==8)lim=6;
		while(rem>0){
			if(rand()%50<lim && word[a=rand()%n].length()<=rem){
				cout<<word[a];
				rem-=word[a].length();
			}
			else{
				for(i=0,j=rand()%min(rem,30)+1;i<j;i++){
					cout<<(char)(rand()%26+'a');
				}
				rem-=j;
			}
		}
		cout<<endl;
		
		
		
		fclose(stdout);
	}
	
	
	
}	
	
void run(){
	int i;
	for(i=0;i<=10;i++){
		out="book"+to_string(i)+".out";
		in="book"+to_string(i)+".in";
		cmd="std > "+out+" < "+in;
		system(cmd.c_str() );
	}
	
	
	
}	
_Main(){
	srand(time(0));
	std::ios::sync_with_stdio(false);
//	make();
	run();
}	
	
}Maker;
