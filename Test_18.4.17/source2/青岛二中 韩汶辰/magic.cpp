#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=400100;
ll jc[N],sum[N],mi[100],res[10][N],c[N];
int pr[100],cnt=0,n;
ll ksm(ll x,int y,int m)
{
	ll re=1;
	while(y)
	{
		if(y&1)re=(re*x)%m;
		x=(x*x)%m;y>>=1;
	}
	return re;
}
void calc(int p,int m,int t,int i)
{
	int j;ll x;
	jc[0]=1;sum[0]=0;
	mi[0]=1;
	for(j=1;j<=t;j++)mi[j]=mi[j-1]*p;
	for(j=1;j<n;j++)
	{
		x=j;sum[j]=sum[j-1];
		while(x%p==0)x/=p,sum[j]++;
		jc[j]=(jc[j-1]*x)%m;
	}
	for(j=0;j<n;j++)
	{
		if(sum[n-1]-sum[j]-sum[n-1-j]>=t)res[i][j]=0;
		else res[i][j]=((jc[n-1]*ksm(jc[j],m/p*(p-1)-1,m)*ksm(jc[n-1-j],m/p*(p-1)-1,m))%m*mi[sum[n-1]-sum[j]-sum[n-1-j]])%m;
	}
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1;y=0;return;
	}
	exgcd(b,a%b,x,y);
	ll t=x;
	x=y;y=t-(a/b)*y;
}
void crt(int i,int cnt)
{
	ll a=res[1][i],m=pr[1],x,y,mm;
	for(int j=2;j<=cnt;j++)
	{
		exgcd(m,pr[j],x,y);
		mm=m;m*=pr[j];
		x=((x*(res[j][i]-a))%m+m)%m;
		a=(a+x*mm)%m;
	}
	c[i]=a;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int i,j,k,num,mod,m,x;
	scanf("%d%d",&n,&m);
	cnt=0;mod=m;
	for(i=2;i*i<=m;i++)
	   if(m%i==0)
	   {
	   	   pr[++cnt]=1;num=0;
	   	   while(m%i==0)m/=i,pr[cnt]*=i,num++;
	   	   calc(i,pr[cnt],num,cnt);
	   }
	if(m!=1)calc(m,m,1,++cnt),pr[cnt]=m;
	for(i=0;i<n;i++)crt(i,cnt);
//	for(i=0;i<n;i++)cout<<i<<":"<<c[i]<<endl;
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans=(ans+(ll)x*c[i-1])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
