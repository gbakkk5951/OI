using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>

struct _Main{
	
	
int n;
int head[6010];
int nxt[6010];
int son[6010];	
int happy[6010];
bool master[6010];
int dp[2][6010];	//1参加，0不参加； 
int idx;	
	
int inline abs(int a){
	return a>>31^((a>>31)+a);
}	
int inline max(int a,int b){
	return ((a+b)+abs(a-b))>>1;
}	
template<typename Type1>
void read(Type1 &a){
	char t,f=1;
	while(!isdigit(t=getchar())){
		if(t=='-'){
			f=-1;
		}
	}
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
	a=a*f;
}

_Main(){
	memset(master,true,sizeof(master));
	read(n);
	int i;
	int f,s;
	for(i=1;i<=n;i++){
		read(happy[i]);		
	}
	for(i=1;i<=n-1;i++){
		idx++;
		read(s);read(f);
		nxt[idx]=head[f];
		head[f]=idx;
		son[idx]=s;
		master[s]=false;
	}
	for(i=1;i<=n;i++){
		if(master[i]){
			getans(i);
			printf("%d\n",max(dp[0][i],dp[1][i]));		
			return;
		}
	}
	
}
void getans(int node){
	int i,j;
	dp[1][node]=happy[node];
	for(i=head[node];i;i=nxt[i]){
		getans(son[i]);
		dp[1][node]+=dp[0][son[i]];
		dp[0][node]+=max(dp[0][son[i]],dp[1][son[i]]);
	}
}


	
	
	
	
	
	
}cdvs1380;
