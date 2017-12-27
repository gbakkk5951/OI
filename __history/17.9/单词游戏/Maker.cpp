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
	int lim,alph;
template<typename Type>
	void shuffle(Type *beg,int size){
		int i;
		for(i=1;i<size;i++){
			swap(beg[rand()%(i+1)],beg[i]);
		}
	}
int prime[200];
int cnt;bool vis[200];
void getprime(){
	int i,j;
	for(i=2;i<=150;i++){
		if(!vis[i]){
			prime[cnt++]=i;
		}
		for(j=0;j<cnt && i*prime[j] <=150;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
	
}
	
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
string arr[100010];
string random_word(int len,char head=0,char tail=0){
	string a="";
	int i;
	if(len==1 && head){
		return a=head;
	}else if(head){
		len--;
		a=head;
	}
	if(tail){
		len--;
	}
	for(i=0;i<len;i++){
		if(rand()&1)a+=(char)('a'+rand()%alph);
		else a+=(char)('A'+rand()%alph);
	}
	if(tail)a+=(char)tail;
	return a;
}
void make(){
	int i,j,k;int I;int l,m;int n;int g;


	for(I=0;I<25;I++){
		file="wordgame"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);

		if(I<5){
			n=10;lim=4;alph=4;
		}else if(I<10){
			n=1000+(rand()%500-250);
			lim=15;alph=26;
		}else if(I<25){
			n=100000-(rand()&1?0:rand()%2500);
			lim=15;alph=26;
		}
		if(I%10==0){//随机 
			for(i=0;i<n;i++){
				arr[i]=random_word(rand()%lim+1);
			}
		}else if(I%3==0){//回路 
			arr[0]=random_word(rand()%lim+1);
			for(i=1;i<n-1;i++){
				arr[i]=random_word(rand()%lim+1,*(arr[i-1].end()-1));
			}
			arr[i]=random_word(rand()%(lim-1)+2,*(arr[i-1].end()-1),arr[0][0]);
			shuffle(arr,n);
		}else {//路径 
			arr[0]=random_word(rand()%lim+1);
			for(i=1;i<n;i++){
				arr[i]=random_word(rand()%lim+1,*(arr[i-1].end()-1));
			}		
			shuffle(arr,n);
		}
		cout<<n<<endl;
		for(i=0;i<n;i++){
			cout<<arr[i]<<endl;
		}
		
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<25;I++){
		cmd="std.exe > wordgame"+to_string(I)+".out < wordgame"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	getprime();
	srand(time(0));
	make();
	run();
}	
	
	
}Maker;
