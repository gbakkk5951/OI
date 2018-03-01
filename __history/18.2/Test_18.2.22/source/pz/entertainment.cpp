#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define si scanf
#define so printf
#define N 1100
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0;
	char tmp=getchar();
	if(tmp==EOF)
		return 0;
	if(tmp=='-')
		mns=1;
	while(tmp<'0'||tmp>'9')
	{
		tmp=getchar();
		if(tmp==EOF)
			return 0;
		if(tmp=='-')
			mns=1;
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=r*10+tmp-'0';
		tmp=getchar();
	}
	if(mns)
		r=-r;
	return 1;
}
int n,k,m[2];
long long c[N][2];
int ln[N];
long long ans;
void dfs(int now,long long hp)
{
	if(now>n)
	{
		ans=max(ans,hp);
		return ;
	}
	int cnt[2];
	
	ln[now]=0;
	if(now>=k)
	{
		cnt[0]=cnt[1]=0;
		for(int i=now-k+1;i<=now;++i)
			++cnt[ln[i]];
		if(cnt[0]<m[0]||cnt[1]<m[1])
			return;
	}
	dfs(now+1,hp+c[now][0]);
	
	ln[now]=1;
	if(now>=k)
	{
		cnt[0]=cnt[1]=0;
		for(int i=now-k+1;i<=now;++i)
			++cnt[ln[i]];
		if(cnt[0]<m[0]||cnt[1]<m[1])
			return;
	}
	dfs(now+1,hp+c[now][1]);
}
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	rd(n),rd(k),rd(m[0]),rd(m[1]);
	for(int i=0;i<=1;++i)
	for(int j=1;j<=n;++j)
		rd(c[j][i]);
	dfs(1,0);
	so("%lld\n",ans);
	return 0;
}
