

//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
const int ch_top=2e7;
char ch[ch_top],*now_r=ch-1;
#define c (*now_r)
#define gc (*++now_r)
int read()
{
    while(gc<'-');
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}
#undef gc
#undef c

namespace QUERY2
{
ll solve(int *a,int n)
{
	ll s=a[1];int as=a[1];
	rep(i,2,n){s+=a[i];as&=a[i];}
	return s+as;
}
};

namespace SPECIAL
{
const int N=5e5+5;
int a[N];
int ql[N],qr[N],cnt[N],q1[N],q[N];
struct Query
{
	int l,r,id;
};
Query query[N];
int ans[N];
int mx,mxi;
#define add(x) if(++cnt[x]>mx){mx=cnt[x];mxi=x;} else if(cnt[x]==mx&&x<mxi)mxi=x;
void main()
{
	int n=read(),m=read();
	rep(i,1,n)a[i]=read();
	rep(i,1,m)
	{
		ql[i]=read();
		++cnt[qr[i]=read()];
	}
	rep(i,1,n)cnt[i]+=cnt[i-1];
	rep(i,1,m)q1[cnt[qr[i]]--]=i;
	rep(i,1,n)cnt[i]=0;

	rep(i,1,m)++cnt[ql[i]];
	rep(i,1,n)cnt[i]+=cnt[i-1];
	per(i,m,1)q[cnt[ql[q1[i]]]--]=q1[i];
	rep(i,1,n)cnt[i]=0;

	for(int l=1;l<=m;)
	{
		int r=l;
		int nl=ql[q[l]],nr=qr[q[l]];
		mx=mxi=0;
		rep(i,nl,nr)add(a[i])
		ans[q[l]]=mxi;
		while(r<m&&ql[q[r+1]]<=nl)
		{
			++r;
			int tl=ql[q[r]],tr=qr[q[r]];
			while(nl>tl){--nl;add(a[nl])}
			while(nr<tr){++nr;add(a[nr])}
			ans[q[r]]=mxi;
		}
		rep(i,nl,nr)cnt[a[i]]=0;
		l=r+1;
	}

	rep(i,1,m)printf("%d ",ans[i]);
	puts("");
	printf("%lld\n",QUERY2::solve(ans,m));
}
};
namespace MO
{
const int N=5e4+5,L=256;
int a[N],cnt[N];
struct Query
{
	int l,r,id;
};
bool r_xiao(const Query &a,const Query &b)
{
	return a.r<b.r;
}
vector<Query>lk[N/L+5];
int ans[N];
int mx,mxi;
void main()
{
	int n=read(),m=read();
	rep(i,1,n)a[i]=read();
	rep(i,1,m)
	{
		int ql=read(),qr=read();
		if(qr-ql<=L)
		{
			mx=mxi=0;
			rep(i,ql,qr)add(a[i]);
			ans[i]=mxi;
			rep(i,ql,qr)cnt[a[i]]=0;
		}
		else
		{
			lk[(ql-1)/L].pb((Query){ql,qr,i});
		}
	}
	rep(i,0,(n-1)/L)
	{
		sort(lk[i].begin(),lk[i].end(),r_xiao);
		int nl=(i+1)*L,nr=nl-1;
		mx=mxi=0;
		for(auto q:lk[i])
		{
			while(nr<q.r){++nr;add(a[nr])}
			int nmx=mx,nmxi=mxi;
			int i=q.l;
			while(i<nl)
			{
				if(++cnt[a[i]]>nmx){nmx=cnt[a[i]];nmxi=a[i];}
				else
				if(cnt[a[i]]==nmx&&a[i]<nmxi)nmxi=a[i];
				++i;
			}
			ans[q.id]=nmxi;
			while(i>q.l)--cnt[a[--i]];
		}
		rep(i,nl,nr)cnt[a[i]]=0;
	}

	rep(i,1,m)printf("%d ",ans[i]);
	puts("");
	printf("%lld\n",QUERY2::solve(ans,m));
}
};

int main()
{
	freopen("hack_0.in","r",stdin);freopen("1.out","w",stdout);
	fread(ch,1,ch_top,stdin);
	int type=read();
	if(type>=7)SPECIAL::main();
	else MO::main();
}

