#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
struct _Main{
int org[1000010];	
int lt[1000017];	
int rt[1000012];
int cl[1000073];	
int temp[1000009];
int n,m;
int read(){
	char t;int ans=0;
	while(!isdigit(t=getchar()));
	do{
		ans*=10;
		ans+=t-'0';
	}while(isdigit(t=getchar()));
	return ans;
}
bool check(int po){
	int i,j;
	memset(temp,0,sizeof(temp));
	for(i=1;i<=po;i++){
		temp[lt[i]]-=cl[i];
		temp[rt[i]+1]+=cl[i];
	}
	long long now=0;
	for(i=1;i<=n;i++){
		now+=temp[i];
		if(org[i]+now<0){
			return false;
		}
	}
	return true;
}
int binary(){
	int l=1,r=m;
	while(l^r){
		if(check((l+r)>>1)){
			l=((l+r)>>1)+1;
		}else{
			r=(l+r)>>1;
		}
	}
	if(l!=m){
		printf("-1\n%d",l);
	}else {
		putchar('0');
	}
}	
_Main(){
	int i,j;
	n=read();
	m=read();
	for(i=1;i<=n;i++){
		org[i]=read();
	}
	for(i=1;i<=m;i++){
		cl[i]=read();
		lt[i]=read();
		rt[i]=read();
	}
	binary();
}	
	
	
	
	
	
}cdvs1217;int main(){}
