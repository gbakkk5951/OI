using namespace std;
int main(){}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<fstream>

struct _Main{
int name[100010];	
struct Edge{
	int a,b,c;
}edge[200010];	
	
	int lim,alph;
template<typename Type>
	void shuffle(Type *beg,int size){
		int i;
		for(i=1;i<size;i++){
			swap(beg[rand()%(i+1)],beg[i]);
		}
	}
int prime[2000000];
int primecnt;bool vis[10000005];
void getprime(){
	int i,j;
	for(i=2;i<=10000000;i++){
		if(!vis[i]){
			prime[primecnt++]=i;
		}
		for(j=0;j<primecnt && i*prime[j] <=10000000;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
	
}
	
int lrand(){
	return (rand()<<16) | (rand()<<1) ^rand();	
}
long long llrand(){
	return (long long)((long long)lrand()<<32)|((long long )lrand()<<1)^rand();
}
string outfile,cmd,infile;
string to_string(int a){
	stringstream os;string ans;
	os<<a;
	os>>ans;
	return ans;
}
int randsym(){
	return (rand()&1)?-1:1;
}

string arr[100010];
void shuffleedge(Edge *beg,int n,int m){
	int i;
	for(i=1;i<=n;i++){
		name[i]=i;
	}
	shuffle(name+1,n);
	shuffle(beg,m);
	for(i=0;i<m;i++){
		if(rand()&1)swap(beg[i].a,beg[i].b);
		beg[i].a=name[beg[i].a];
		beg[i].b=name[beg[i].b];
	}
}
void inline add (int a,int b,int c,int &idx){
	edge[idx].a=a;
	edge[idx].b=b;
	edge[idx].c=c;
	idx++;
}
int arr1[400010],arr2[400010];
char type[4000010];
int mod=1e5+1;


//////////////
string problemname="data";
int beg = 0
,   end = 1
,   exbeg = 0
,   exend = 0
;
//////////////

void make(){
	int I;
	int i,j,k;
	int A,B,C;
	int N,M,Q,K;
	int t;
	for(I=beg;I<end;I++){
		outfile=problemname+to_string(I)+".in";
		cerr<<"Make "<<outfile<<endl;
		ofstream output(outfile.c_str());
        N = M = 100000 ;
        output << N << " " << M <<endl;
        for (i = 1; i <= N; i++){
            output << 524288 << " " ;
        }
        output << endl;
        for (i = 1; i <= M; i++) {
            A = lrand() % N + 1;
            B = lrand() % N + 1;
            if (A > B) {
                swap(A, B);
            }
            output << A << " " << B << endl;
        }
		EndFor:
		output.close();
	}
	
	
	for(I=exbeg;I<exend;I++){
		outfile=problemname+"_ex"+to_string(I)+".in";
		cerr<<"Make "<<outfile<<endl;
		ofstream output(outfile.c_str());
		memset(type,0,sizeof(type));
		
		
		output.close();
	}	
	
	
}
void run(){
	int I;
    float time_a, time_b;
	for(I=beg;I<end;I++){
		cmd="std.exe > "+problemname+to_string(I)+".out < "+problemname+to_string(I)+".in";
		cerr<<"Run: "<<cmd<<endl;
		time_a = clock();
		system(cmd.c_str());
		time_b = clock();
		cerr<<"time : "<<time_b - time_a<<" ms"<<endl;
        /*
		cmd="brute.exe > brute"+to_string(I)+".out < "+problemname+to_string(I)+".in";
		system(cmd.c_str());
		cmd="fc brute"+to_string(I)+".out "+problemname+to_string(I)+".out";
		if(system(cmd.c_str())){
			system("pause");
		}
		*/
	}
	
	for(I=exbeg;I<exend;I++){
		cmd="std.exe > "+problemname+"_ex"+to_string(I)+".out < "+problemname+"_ex"+to_string(I)+".in";
		cerr<<"Run: "<<cmd<<endl;
		system(cmd.c_str());
		/*
		cmd="brute.exe > brute_ex"+to_string(I)+".out < "+problemname+"_ex"+to_string(I)+".in";
		system(cmd.c_str());
		cmd="fc brute_ex"+to_string(I)+".out "+problemname+"_ex"+to_string(I)+".out";
		if(system(cmd.c_str())){
			system("pause");
		}
		*/
	}
	
}
	
_Main(){
	getprime();
	srand(time(0));
	
	make();
	run();		


}	
	
	
}Maker;
