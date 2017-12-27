
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;
set<char>heap;
char f[51];
char l[51];
char r[51];
char inp[51];
char n;
struct _Main{



_Main(){
	readin();
	dfs();
	output();
}

void readin(){
	char i;short in;
	n=read();	
	heap.insert(0); 
	for(i=1;i<=n;i++){
		heap.insert(i); 
		in=read();
		if(in<100){
			l[in]=i;
			f[i]=in;
		}else{
			in-=100;
			r[in]=i;
			f[i]=in;			
		}
	}
}

void del(int node){
	heap.erase(node);
	
	f[l[node]]=f[node];
	l[f[node]]=l[node];
	
	while(node){
	//	printf("while");
		swap(l[f[node]],r[f[node]]);
		node=f[node];
	}
	
	
}

void dfs(){
	char iter=n;
	int now;				
	do{
	now=*heap.begin() ;
	while(r[now]){
		now=l[now];
	}
	if(l[l[now]]|r[l[now]]){
		inp[iter]=now;
		del(now);
	}else{
		inp[iter]=l[now];
		del(l[now]);
	}
	}while(iter--);
}


void output(){
	int i;
	for(i=0;i<=n;i++){
		printf("%d ",inp[i]);
	}
	exit(0);
}
	
	
short read(){
	char t;short ans=0;
	while(!isdigit(t=getchar()));
	do{
		ans*=10;
		ans+=t-'0';
	}while(isdigit(t=getchar()));
	return ans;
}
	
}instance;int main(){}
