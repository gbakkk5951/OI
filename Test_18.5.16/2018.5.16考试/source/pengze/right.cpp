#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define si scanf
#define so printf
#define N 100100
#define M 
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
int ln[N];
namespace oddp
{
	#define ls (o<<1)
	#define rs (ls|1)
	int l[N*4],r[N*4];
	int cnt[N*4][2],pl[N*4];
	void build(int o,int ll,int rr)
	{
		l[o]=ll,r[o]=rr;
		pl[o]=0;
		if(ll==rr)
		{
			cnt[o][ln[ll]&1]=1;
			return;
		}
		int mid=(ll+rr)>>1;
		build(ls,ll,mid);
		build(rs,mid+1,rr);
		cnt[o][0]=cnt[ls][0]+cnt[rs][0];
		cnt[o][1]=cnt[ls][1]+cnt[rs][1];
	}
	inline void update(int o,int pls)
	{
		if(pls&1)
		{
			pl[o]^=1;
			swap(cnt[o][0],cnt[o][1]);
		}
	}
	inline void pass(int o)
	{
		if(l[o]!=r[o])
		{
			update(ls,pl[o]);
			update(rs,pl[o]);
		}
		pl[o]=0;
	}
	void add(int o,int ll,int rr,int pls)
	{
		if(ll<=l[o]&&r[o]<=rr)
		{
			update(o,pls);
			return;
		}
		int mid=(l[o]+r[o])>>1;
		pass(o);
		if(ll<=mid)
			add(ls,ll,rr,pls);
		if(mid+1<=rr)
			add(rs,ll,rr,pls);
		cnt[o][0]=cnt[ls][0]+cnt[rs][0];
		cnt[o][1]=cnt[ls][1]+cnt[rs][1];
	}
	void ask(int o,int ll,int rr,int* ans)
	{
		if(ll<=l[o]&&r[o]<=rr)
		{
			ans[0]+=cnt[o][0],ans[1]+=cnt[o][1];
			return;
		}
		pass(o);
		int mid=(l[o]+r[o])>>1;
		if(ll<=mid)
			ask(ls,ll,rr,ans);
		if(mid+1<=rr)
			ask(rs,ll,rr,ans);
	}
}
int n,nq,p;
int main()
{
	
	freopen("right.in","r",stdin);
	freopen("right.out","w",stdout);
	rd(n),rd(nq),rd(p);
	for(int i=1;i<=n;++i)
		rd(ln[i]);
	if(p&1)
	{
		oddp::build(1,1,n);
		int ans[2],op,l,r;
		long long x;
		for(int qq=1;qq<=nq;++qq)
		{
			rd(op);
			if(op==0)
			{
				rd(l),rd(r),rd(x);
				x&=1;
				oddp::add(1,l,r,x);
			}
			else
			{
				rd(l),rd(r);
				ans[0]=ans[1]=0;
				oddp::ask(1,l,r,ans);
				so("%d\n",ans[1]&1);
			}
		}
	}
	else
	{
		++p;
		for(int i=1;i<=n;++i)
			++ln[i];
		int ans[3],op,l,r;
		long long x;
		for(int qq=1;qq<=nq;++qq)
		{
			rd(op);
			if(op==0)
			{
				rd(l),rd(r),rd(x);
				x%=p;
				for(int i=l;i<=r;++i)
				{
					ln[i]+=x;
					if(ln[i]>=p)
						ln[i]-=p;
				}
			}
			else
			{
				rd(l),rd(r);
				ans[0]=ans[1]=ans[2]=0;
				for(int i=l;i<=r;++i)
					if(ln[i]==0)
						++ans[2];
					else
						++ans[ln[i]&1];
				so("%d\n",(int)((ans[1]&1)||(ans[2]&1)));
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
