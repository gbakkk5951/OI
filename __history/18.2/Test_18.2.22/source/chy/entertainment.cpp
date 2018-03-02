//by sdfzchy
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int inf=(1<<30);
inline LL in()
{
	char ch=getchar();
	LL f=1,tmp=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {tmp=(tmp<<1)+(tmp<<3)+(ch-'0');ch=getchar();}
	return tmp*f;
}

const int N=1010;
int n,k,A,B;
LL a[N],b[N],f[20][1<<21],cnt[1<<21];

int gi(int x)
{
	int ret=0;
	while(x) ret++,x-=x&(-x);
	return ret;
}

bool check(int x)
{
	int o[30],c=0,t=0;
	memset(o,0,sizeof(o));
	while(x) o[++c]=x&1,x>>=1;
	for(int i=1;i<k;i++) t+=o[i];
	for(int i=k;i<=n;i++)
	{
		t+=o[i]; t-=o[i-k];
		if(t>=A&&k-t>=B) continue;
		else return 0;
	}
	return 1;
}

LL calc(int x)
{
	LL ret=0;
	for(int i=1;i<=n;i++) ret+=(x&(1<<(i-1)))?b[i]:a[i];
	return ret;
}


int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	n=in(),k=in(),A=in(),B=in();
	for(int i=1;i<=n;i++) a[i]=in();
	for(int i=1;i<=n;i++) b[i]=in();
	if(n<=20)
	{
		LL ans=-(1ll<<60);
		for(int i=0;i<(1<<n);i++)
			if(check(i))
				ans=max(ans,calc(i));
		cout<<ans<<endl;
	}
	else
	{
		LL ans=0;
		for(int i=1;i<=n;i++) ans+=max(a[i],b[i]);
		cout<<ans<<endl;
	}
	return 0;
}

