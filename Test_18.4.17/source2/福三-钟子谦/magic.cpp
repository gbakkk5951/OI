#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 1555555
const int M=524288;
static int n,a[SZ],tag[SZ],*ps,qw[SZ],ln=0,orz[SZ];
static char ch,B[1<<15],*S=B,*T=B;
static bool np[SZ];static ll K;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
inline int F(){register int aa,bb;
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
#define gi F()
int main()
{
	FO(magic)
	for(int i=0;i<M+M;i++) tag[i]=1;
	n=gi-1,K=gi; int hf=n/2;
	for(int i=0;i<=n;i++) a[i]=gi;
	for(int p=2;p<=n;p++)
	{
		if(np[p]) continue;
		for(int j=p+p;j<=n;j+=p)
			np[j]=1;
		ln=0;
		for(int w=0;w<=n;w+=p)
			qw[++ln]=w,qw[++ln]=w?(w-1):0,
			qw[++ln]=n-w,qw[++ln]=w?(n-w+1):n;
		qw[++ln]=n+1;
		sort(qw+1,qw+1+ln);
		int ww=0,gg=n;
		while(gg) ww+=gg/p, gg/=p;
		for(int i=1;i<ln;i++)
		{
			if(qw[i]==qw[i+1]||qw[i]>hf) continue;
			int w=ww,g=qw[i];
			while(g) w-=g/p, g/=p;
			g=n-qw[i];
			while(g) w-=g/p, g/=p;
			ll k=1,P=p;
			while(w)
			{
				if(w&1) k=k*P%K;
				P=P*P%K; w>>=1;
			}
			for(int l=M+qw[i],r=M+1+qw[i+1];
			l^r^1;l>>=1,r>>=1)
			{
				if(~l&1) tag[l^1]=(ll)tag[l^1]*k%K;
				if(r&1) tag[r^1]=(ll)tag[r^1]*k%K;
			}
		}
	}
	for(int i=1;i<M;i++)
		(tag[i]!=1)?(tag[i+i]=(ll)tag[i+i]*tag[i]%K,
		tag[i+i+1]=(ll)tag[i+i+1]*tag[i]%K):0;
	ll ans=0; ps=tag+M+1;
	for(int i=hf+1;i<=n;i++) ps[i]=ps[n-i];
	for(int i=0;i<=n;i++)
		ans=(ans+(ll)ps[i]*a[i]%K)%K;
	ans=(ans%K+K)%K;
	printf("%lld\n",ans);
}

