#include<bits/stdc++.h>
#define maxn 65600
#define ll long long
using namespace std;

ll gcd(ll x,ll y){
	if(!x||!y)
		return x|y;
	return x<y?gcd(x,y%x):gcd(y,x%y);
}
struct frac{
	ll n,d;
	void red(){
		ll _gcd=gcd(abs(n),abs(d));
		n/=_gcd,d/=_gcd;
		if(d<0)
			n=-n,d=-d;
	}
	frac(ll _n=0,ll _d=1){
		n=_n,d=_d;
	}
	frac operator =(ll x)const{
		return frac(x,1);
	}
	frac operator +(const frac &rhs)const{
		frac ret=frac(n*rhs.d+d*rhs.n,d*rhs.d);
		ret.red();
		return ret;
	}
	frac operator -(const frac &rhs)const{
		frac ret=frac(n*rhs.d-d*rhs.n,d*rhs.d);
		ret.red();
		return ret;
	}
	frac operator *(const frac &rhs)const{
		frac ret=frac(n*rhs.n,d*rhs.d);
		ret.red();
		return ret;
	}
	frac operator /(const frac &rhs)const{
		frac ret=frac(n*rhs.d,d*rhs.n);
		ret.red();
		return ret;
	}
	bool operator ==(const frac &rhs)const{
		return n==rhs.n&&d==rhs.d;
	}
	bool operator <(const frac &rhs)const{
		if(n*rhs.n<0)
			return n<0;
		return n*rhs.d<d*rhs.n;
	}
};
frac ca,cb;
frac abs(frac x){
	return frac(abs(x.n),abs(x.d));
}
struct pnt{
	frac x,y;
	pnt(frac _x=frac(),frac _y=frac()){
		x=_x,y=_y;
	}
};
struct edge{
	int u,v;
	frac a,b;
	bool operator <(const edge &rhs)const{
		return rhs.a*ca+rhs.b*cb<a*ca+b*cb;
	}
}es[maxn];
int fa[maxn],sz[maxn],n,m,E;
ll sqr(ll x){
	return x*x;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(sz[x]>sz[y])
		swap(x,y);
	fa[x]=y,sz[y]+=sz[x];
}
pnt calc(frac _ca,frac _cb){
	ca=_ca,cb=_cb;
	sort(es+1,es+m+1);
	frac ansa=frac(),ansb=frac();
	for(int i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		if(find(es[i].u)==find(es[i].v))
			continue;
		merge(find(es[i].u),find(es[i].v));
		ansa=ansa+es[i].a,ansb=ansb+es[i].b;
	}
	return pnt(ansa,ansb);
}
frac solve(pnt L,pnt R){
	pnt MID=calc(L.x-R.x,R.y-L.y);
	if((MID.x==L.x&&MID.y==L.y)||(MID.x==R.x&&MID.y==R.y)){
		frac ansL=L.x*L.x+L.y,ansR=R.x*R.x+R.y;
		return ansL<ansR?ansR:ansL;
	}
	frac ansL=solve(L,MID),ansR=solve(MID,R);
	return ansL<ansR?ansR:ansL;
}
int main(){
	freopen("mvst.in","r",stdin);
	freopen("mvst.out","w",stdout);
	ll x;
	scanf("%d%d",&n,&m),E=n-1;
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&es[i].u,&es[i].v,&x),es[i].a=frac(x,1),es[i].b=frac(-1LL*E*sqr(x),1);
	pnt L,R;
	L=calc(0,1),R=calc(1,0);
	frac ans=solve(L,R);
	ans.d*=-sqr(E),ans.red();
	printf("%lld/%lld\n",ans.n,ans.d);
	return 0;
}
