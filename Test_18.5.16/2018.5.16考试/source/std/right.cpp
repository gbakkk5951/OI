#include"algorithm"
#include"iostream"
#include"stdio.h"
#include"time.h"
#include"map"

using namespace std;

const int N=100005,S=200,T=N/S+5;

template<class I>
void gi(I&x){
	int f=1;char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;x=ch&15;
	for(ch=getchar();ch<='9'&&ch>='0';ch=getchar())x=x*10+(ch&15);x*=f;
}

int n,q,p,mod,a[N],up[T],bl[N],lm;
bool sum[T][2][N],to[T][2];

#define lowbit(x) ((x)&-(x))
void add(bool*w,int x){x++;while(x<=lm)w[x]^=1,x+=lowbit(x);}
int ask(bool*w,int x){int r=0;x++;while(x)r^=w[x],x-=lowbit(x);return r;}
void inc(int&u,int v){u+=v;u<mod?:u-=mod;}

void modify(int l,int r,int u){
	int b=bl[l],q;
	while(bl[l]==b&&l<=r){
		q=a[l]&1;to[b][q]^=1;
		add(sum[b][q],a[l]);
		inc(a[l],u);
		q=a[l]&1;to[b][q]^=1;
		add(sum[b][q],a[l]);
		l++;
	}
	b=bl[r];
	while(bl[r]==b&&l<=r){
		q=a[r]&1;to[b][q]^=1;
		add(sum[b][q],a[r]);
		inc(a[r],u);
		q=a[r]&1;to[b][q]^=1;
		add(sum[b][q],a[r]);
		r--;
	}
	if(l<=r)for(b=bl[l];b<=bl[r];b++)inc(up[b],u);
}

int ask(int l,int r){
	int b=bl[l],s1=0,s2=0,w,t;
	bool f1,f2,f3,f4,*x,*y;
	while(bl[l]==b&&l<=r){
		(w=a[l]+up[b])<mod?:w-=mod;
		s2^=w==p,s1^=w&1,l++;
	}
	b=bl[r];
	while(bl[r]==b&&l<=r){
		(w=a[r]+up[b])<mod?:w-=mod;
		s2^=w==p,s1^=w&1,r--;
	}
	if(l<=r){
		if(~p&1){
			for(b=bl[l];b<=bl[r];b++){
				w=mod-up[b]-1;
				x=sum[b][0],y=sum[b][1];
				for(f1=f2=0,t=w+1;t;t-=lowbit(t))
					f1^=y[t],f2^=x[t];
				f3=to[b][0];
				if(w&1)f4=f1^ask(y,w-1);
				else f4=x[w+1];
				s1^=f1^f2^f3,s2^=f4;
			}
		}else{
			for(b=bl[l];b<=bl[r];b++)s1^=to[b][~up[b]&1];
		}
	}
	if(p&1)return s1?1:0;
	return s1||s2;
}

int main(){
	freopen("right.in","r",stdin);
	freopen("right.out","w",stdout);
	gi(n),gi(q),gi(p);mod=p+1;lm=mod+1;
	for(int i=1;i<=n;i++){
		gi(a[i]);
		a[i]%=mod,bl[i]=i/S;
		to[bl[i]][a[i]&1]^=1;
		add(sum[bl[i]][a[i]&1],a[i]);
	}
	for(int i=1,o,l,r,u;i<=q;i++){
		gi(o),gi(l),gi(r);
		if(!o)gi(u),modify(l,r,u%mod);
		else putchar(ask(l,r)+48),putchar('\n');
	}
	return 0;
}
