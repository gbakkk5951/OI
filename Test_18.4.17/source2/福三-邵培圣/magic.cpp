#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#define il inline
#define re register
using namespace std;
const int N=1000001;
int n,m,a[N],c[1001][1001],p[N],q[N];
typedef long long ll;
il int read(){
	int hs=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		hs=(hs<<3)+(hs<<1)+c-'0';
		c=getchar();
	}
	return hs;
}
il void init(){
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%m;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans=(ans+(ll)c[n-1][i]*a[i+1])%m;
	cout<<ans;
}
il int ksm(int base,int pow,int mod){
	int ans=1;
	for(;pow;pow>>=1){
		if(pow&1) ans=(ll)ans*base%mod;
		base=(ll)base*base%mod;
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<=1000) init();
	return 0;
}

