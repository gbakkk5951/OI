#include<bits/stdc++.h>
#define maxn 100010
#define ll long long
#define rep(x,a,b) for(int x=(a),_x_=(b);x<=_x_;++x)
#define per(x,a,b) for(int x=(a),_x_=(b);x>=_x_;--x)
using namespace std;

int val[maxn],n,q;
const ll p=1e9+9;
struct Mat{
	ll a,b,c,d,e,f;
	Mat(ll _a=0,ll _b=0,ll _c=0,ll _d=0,ll _e=0,ll _f=0){
		a=_a,b=_b,c=_c,d=_d,e=_e,f=_f;
	}
	inline friend Mat operator *(const Mat &x,const Mat &y){
		return Mat((x.a*y.a+x.d*y.b)%p,(x.b*y.a+x.e*y.b)%p,(x.c*y.a+x.f*y.b+y.c)%p,
				   (x.a*y.d+x.d*y.e)%p,(x.b*y.d+x.e*y.e)%p,(x.c*y.d+x.f*y.e+y.f)%p);
	}
	inline Mat& operator *=(const Mat &x){
		return (*this)=(*this)*x;
	}
}t[maxn<<2];
inline void read(int &x){
	char ch=x=0;
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=x*10+ch-'0',ch=getchar();
}
inline ll pw(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)
			ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret;
}
inline void pushup(int x){
	t[x]=t[x<<1|1]*t[x<<1];
}
void build(int x,int l,int r){
	if(l==r){
		t[x]=Mat(val[l],p-(val[l]-1)*pw(n-l+1,p-2)%p,p-val[l],val[l],(p+1-(val[l]-1)*pw(n-l+1,p-2)%p)%p,p-val[l]);
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int pos,Mat Mt){
	if(l==r){
		t[x]=Mt;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid)
		update(x<<1,l,mid,pos,Mt);
	else
		update(x<<1|1,mid+1,r,pos,Mt);
	pushup(x);
}
Mat query(int x,int ql,int qr,int l,int r){
	if(ql<=l&&r<=qr)
		return t[x];
	int mid=l+r>>1;
	Mat ret=Mat(1,0,0,0,1,0);
	if(qr>=mid+1)
		ret*=query(x<<1|1,ql,qr,mid+1,r);
	if(ql<=mid)
		ret*=query(x<<1,ql,qr,l,mid);
	return ret;
}
ll query(int pos){
	if(pos==n)
		return 0;
	Mat Mt=query(1,pos+1,n,1,n);
	return p-Mt.c*pw((Mt.a+Mt.b)%p,p-2)%p;
}
int main(){
	read(n),read(q);
	rep(i,1,n)
		read(val[i]);
	build(1,1,n);
	rep(i,1,q){
		int op,x,y;
		read(op);
		if(op==1)
			read(x),printf("%lld\n",query(x));
		if(op==2)
			read(x),read(y),val[x]=y,update(1,1,n,x,Mat(y,p-(y-1)*pw(n-x+1,p-2)%p,p-y,y,(p+1-(y-1)*pw(n-x+1,p-2)%p)%p,p-y));
	}
	return 0;
}
