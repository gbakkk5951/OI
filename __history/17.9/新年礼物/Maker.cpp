using namespace  std;
int main(){}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
struct _Main{
string out,in,tmp;
string cmd;
string output;
string buf;
string to_string(int a){
	string tmp;
	stringstream io;
	io<<a;
	io>>tmp;
	return tmp;
}
void run(){
	int i;
	for(i=0;i<11;i++){
		out="gift"+to_string(i)+".out";
		in="gift"+to_string(i)+".in";
		cmd="std.exe > "+out+" < "+in;
		system(cmd.c_str());
	}
	
}


void make(){
	int i,j,k;int rem;int I,J,K;int n;
	for(I=7;I<7+1;I++){
		out="gift"+to_string(I)+".in";
		output="";buf="";
		freopen(out.c_str() ,"w",stdout);
		n=0;
		if(I<3)rem=500;
		else rem=2000000;
		
		if(I<3){
			while(rem>0){
				k=rand()%min(rem,20)+1;
				for(i=0;i<k;i++){
					buf+= rand()%2 +'a';
				}buf+='\n';
				rem-=k;
				n++;
			}
			cout<<n<<endl<<buf<<endl;				
		}else if(I==3){
			while(rem>0){
				k=+1;
				for(i=0;i<k;i++){
					buf+= rand()%26 +'a';
				}buf+='\n';
				rem-=k;
				n++;
			}
			cout<<n<<endl<<buf<<endl;				
			
		}
		else if(I==4){
			while(rem>0){
				k=rand()%min(rem,4)+1;
				for(i=0;i<k;i++){
					buf+= rand()%2 +'a';
				}buf+='\n';
				rem-=k;
				n++;
			}
			cout<<n<<endl<<buf<<endl;			
		}else if(I==5){
			while(rem>0){
				k=rand()%min(rem,50000)+1;
				for(i=0;i<k;i++){
					buf+= rand()%2 +'a';
				}buf+='\n';
				rem-=k;
				n++;
			}
			cout<<n<<endl<<buf<<endl;
		}else if(I==6){
			for(i=0;i<1000;i++){
				output=output+"A";
			}
			n=2000;cout<<n<<endl;
			for(j=0;j<2000;j++){
				cout<<output<<endl;
			}
			
		}
		else if(I==7){
			n=1;
			for(i=0;i<rem;i++){
				output+= (rand()&1)?'a'+rand()%26:'A'+rand()%26;
			}
			cout<<n<<output<<endl;
		}else if(I==8){
			for(j=0;j<5;j++){
				output+="XYZZYX";
			}
			K=1;
			for(i=0;rem>=output.length();i++){	
				rem-=output.length();
				buf+=output+"\n";
				n++;
				if(i%K==0)for(K++,j=0;j<min(K,5);j++){
					output+="XYZZYX";
				}
			}
			cout<<n<<"\n"<<buf<<endl;
		}else if(I==9){
			for(j=0;j<1;j++){
				output+="XYZZYX";
			}
			K=5;
			for(i=0;rem>=output.length();i++){	
				rem-=output.length();
				buf+=output+"\n";
				n++;
				if(i%K==0)for(K+=5,j=0;j<max(K,3);j++){
					output+="XYZZYX";
				}
			}
			cout<<n<<"\n"<<buf<<endl;			
			
		}else if(I==10){
			for(i=0;i<500000;i++){
				buf=buf+'A';
			}

			cout<<4<<endl<<buf<<endl<<buf<<endl<<buf<<endl<<buf<<endl;
		}
			
		
		
		
		fclose(stdout);
	}
	
	
	
	
}



_Main(){
	std::ios::sync_with_stdio(false);
	make();
	run();
}
	

}Maker;
