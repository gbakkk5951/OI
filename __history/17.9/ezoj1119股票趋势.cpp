using namespace std;
int main(){}
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
int base;

struct SubTree{
	int node[2055];
	int query(int s,int t){
		int ans=0;
		for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){
			if(~s&1)ans=max(ans,node[s^1]);
			if( t&1)ans=max(ans,node[t^1]);
		}
		return ans;
	}
	void change(int pos,int val){
		for(pos+=base;pos;pos>>=1){
			node[pos]=max(node[pos],val);
		}
	}
	void clear(){
		memset(node,0,sizeof(int)*(2*base+1));
	}
};

struct Tree{
	SubTree node[2055];
	int query(int x1,int x2,int y1,int y2){
		int ans=0;
		for(x1=x1+base-1,x2=x2+base+1;x1^x2^1;x1>>=1,x2>>=1){
			if(~x1&1)ans=max(ans,node[x1^1].query(y1,y2));
			if( x2&1)ans=max(ans,node[x2^1].query(y1,y2));
		}
		return ans;
	}
	void change(int x,int y,int val){
		for(x+=base;x;x>>=1){
			node[x].change(y,val);
		}
	}
	void clear(){
		int i;
		for(i=0;i<=base*2;i++){
			node[i].clear();
		}
	}
}tree;


struct _Main{
	
	
	
char a[1000],b[1000];
int limit[26];
int la,lb;
_Main(){
	int T;char alph;int gap;int ans;int dp;
	cin>>a>>b;
	cin>>T;
	int i,j,k;
	la=strlen(a);lb=strlen(b);
	for(j=max(la,lb),i=0;(1<<i)<(j+3);i++);
	base=(1<<i);
	while(T--){
		memset(limit,63,sizeof(limit));
		tree.clear();
		ans=0;
		while(1){
			cin>>alph;
			if(alph!='$'){
				cin>>gap;
				limit[alph-'A']=gap+1;
			}else{
				break;
			}
		}
		for(i=1;i<=la;i++){
			for(j=1;j<=lb;j++)if(a[i-1]==b[j-1]){
				alph=a[i-1]-'A';;
				dp=tree.query(max(1,i-limit[alph]),i-1,max(1,j-limit[alph]),j-1)+1;
				tree.change(i,j,dp);
				ans=max(ans,dp);
			}
		}
		printf("%d\n",ans);
	}
	
}	
	
	
	
	
	
	
	
}ezoj1119;


