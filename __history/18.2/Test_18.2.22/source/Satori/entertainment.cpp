#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int n,k,a,b;
long long va[1010],vb[1010],ans=0ll;
long long jisuan(int s){
	bool xa[26];
	int i,na=0,nb=0;
	long long ret=0ll;
	for(i=0;i<n;i++){
		xa[i+1]=(s&(1<<i));
		if(xa[i+1]) ret+=va[i+1];
		else ret+=vb[i+1];
	}
	for(i=1;i<=k;i++){
		if(xa[i]) na++;
		else nb++;
	}
	if(na<a||nb<b) return -1ll;
	for(i=k+1;i<=n;i++){
		if(xa[i-k]) na--;
		else nb--;
		if(xa[i]) na++;
		else nb++;
		if(na<a||nb<b) return -1ll;
	}
	return ret;
}
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	int i,s,m;
	scanf("%d%d%d%d",&n,&k,&a,&b);
	for(i=1;i<=n;i++) scanf("%lld",&va[i]);
	for(i=1;i<=n;i++) scanf("%lld",&vb[i]);
	if(n<=25){
		m=1<<n;
		for(s=0;s<m;s++){
			ans=max(ans,jisuan(s));
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
