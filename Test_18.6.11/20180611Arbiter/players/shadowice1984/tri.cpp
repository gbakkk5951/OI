#include<cstdio>
#include<algorithm>
using namespace std;const int N=3*1e5+10;const int U=3*1e5;typedef long long ll;const ll mod=1e9+7;
int n;int m;int zhi[N];int book[N];int phi[N];int ct;int T;const ll inv6=166666668LL;
ll sum[N];ll cn3;ll ret;
int main()
{
	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);
	phi[1]=1;
	for(int i=2;i<=U;i++)
	{
		if(book[i]==false){zhi[++ct]=i;phi[i]=i-1;}
		for(int j=1;j<=ct&&i*zhi[j]<=U;j++)
		{
			book[i*zhi[j]]=true;
			if(i%zhi[j]==0){phi[i*zhi[j]]=phi[i]*zhi[j];break;}
			phi[i*zhi[j]]=phi[i]*phi[zhi[j]];
		}
	}for(int i=1;i<=U;i++)sum[i]=(sum[i-1]+i)%mod;
	while(1)
	{
		scanf("%d%d",&n,&m);if(n==0&&m==0)return 0;
		for(int d=1;d<=min(n,m);d++)
		{
			ll ret1=0;for(int j=d;j<=n;j+=d)ret1+=n-j+1;ret1%=mod;
			ll ret2=0;for(int j=d;j<=m;j+=d)ret2+=m-j+1;ret2%=mod;
			(ret+=phi[d]*ret1%mod*ret2)%mod;
		}
		(ret+=mod-sum[n]*sum[m]%mod)%=mod;ret=2*ret%mod;
		ret+=(n+1)*(m+1)%mod*(m*(m-1)%mod+n*(n-1)%mod)*inv6%mod;
		cn3=(n+1)*(m+1);cn3=cn3*(cn3-1)%mod*(cn3-2)%mod*inv6%mod;
		printf("%lld\n",(cn3+mod-ret)%mod);ret=0;
	}fclose(stdin);fclose(stdout);return 0;
}
