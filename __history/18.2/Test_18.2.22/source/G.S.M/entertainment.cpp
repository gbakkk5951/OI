#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1005;
int n,k,ms,me,v[maxn],w[maxn],dp[maxn][maxn];
int dfn[15];
int ans,f;
inline int read(){
	char ch='*';
	while(!isdigit(ch=getchar()));
	int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num;
}
void check(int x){
	int tmp=x;
	for(int i=1;i<=n;i++){
		dfn[i]=x&1;
		x>>=1;
	}
	int cnt1=0,cnt2=0,val=0;
	for(int i=1;i<=n-k+1;i++){
		cnt1=0,cnt2=0;
		for(int j=1;j<=k;j++){
			if(dfn[i+j-1]) cnt1++;
			else cnt2++;
		}
		if(cnt1<ms||cnt2<me) return ;
	}
	for(int i=1;i<=n;i++) if(dfn[i]) val+=v[i];else val+=w[i];
	if(val>ans) ans=val,f=tmp;
}
int main(){
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	n=read();k=read(),ms=read(),me=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<=n;i++) w[i]=read();
 	for(int i=0;i<1<<n;i++){
		check(i);
	}
	cout<<ans<<endl;
}
