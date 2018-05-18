#include<bits/stdc++.h>
#define maxn 100010
#define maxp 105
#define mp make_pair
#define pb push_back
#define rep(x,a,b) for(int x=a;x<=b;++x)
using namespace std;

int a[maxn],n,q,p;
namespace podd{
	int to[maxn<<2],te[maxn<<2],tag[maxn<<2];
	void pushup(int x){
		to[x]=to[x<<1]^to[x<<1|1];
		te[x]=te[x<<1]^te[x<<1|1];
	}
	void pushdown(int x){
		if(!tag[x])
			return;
		swap(to[x<<1],te[x<<1]),swap(to[x<<1|1],te[x<<1|1]);
		tag[x<<1]^=1,tag[x<<1|1]^=1,tag[x]=0;
	}
	void build(int x,int l,int r){
		if(l==r){
			(a[l]&1?to[x]:te[x])=1;
			return;
		}
		int mid=l+r>>1;
		build(x<<1,l,mid),build(x<<1|1,mid+1,r);
		pushup(x);
	}
	void update(int x,int ql,int qr,int l,int r){
		if(ql<=l&&r<=qr){
			swap(to[x],te[x]),tag[x]^=1;
			return;
		}
		pushdown(x);
		int mid=l+r>>1;
		if(ql<=mid)
			update(x<<1,ql,qr,l,mid);
		if(qr>=mid+1)
			update(x<<1|1,ql,qr,mid+1,r);
		pushup(x);
	}
	int query(int x,int ql,int qr,int l,int r){
		if(ql<=l&&r<=qr)
			return to[x];
		int mid=l+r>>1,ret=0;
		if(ql<=mid)
			ret^=query(x<<1,ql,qr,l,mid);
		if(qr>=mid+1)
			ret^=query(x<<1|1,ql,qr,mid+1,r);
		return ret;
	}
	void solve(){
		build(1,1,n);
		rep(i,1,q){
			int op,l,r,x;
			scanf("%d",&op);
			if(!op){
				scanf("%d%d%d",&l,&r,&x);
				if(x&1)
					update(1,l,r,1,n);
			}
			else{
				scanf("%d%d",&l,&r);
				printf("%d\n",query(1,l,r,1,n));
			}
		}
	}
}
namespace nqsm{
	void solve(){
		rep(i,1,q){
			int op,l,r,x;
			scanf("%d",&op);
			if(!op){
				scanf("%d%d%d",&l,&r,&x);
				rep(j,l,r)
					a[j]=(a[j]+x)%(p+1);
			}
			else{
				int cnt[3]={0};
				scanf("%d%d",&l,&r);
				rep(j,l,r){
					if(p&a[j]&1)
						cnt[1]^=1;
					else if(~p&1){
						if(a[j]==p)
							cnt[2]^=1;
						else if(a[j]&1)
							cnt[1]^=1;
					}
				}
				printf("%d\n",cnt[1]|cnt[2]);
			}
		}
	}
}
namespace psm{
	int t[maxn<<2][maxp],tag[maxn<<2],bin[maxp];
	void pushup(int x){
		rep(i,0,p)
			t[x][i]=t[x<<1][i]^t[x<<1|1][i];
	}
	void pushdown(int x){
		if(!tag[x])
			return;
		tag[x<<1]=(tag[x<<1]+tag[x])%(p+1);
		tag[x<<1|1]=(tag[x<<1|1]+tag[x])%(p+1);
		rep(i,0,p)
			bin[(i+tag[x])%(p+1)]=t[x<<1][i];
		memcpy(t[x<<1],bin,sizeof(int)*(p+1));
		rep(i,0,p)
			bin[(i+tag[x])%(p+1)]=t[x<<1|1][i];
		memcpy(t[x<<1|1],bin,sizeof(int)*(p+1));
	}
	void build(int x,int l,int r){
		if(l==r){
			t[x][a[l]]=1;
			return;
		}
		int mid=l+r>>1;
		build(x<<1,l,mid),build(x<<1|1,mid+1,r);
		pushup(x);
	}
	void update(int x,int ql,int qr,int l,int r,int val){
		if(ql<=l&&r<=qr){
			rep(i,0,p)
				bin[(i+val)%(p+1)]=t[x][i];
			memcpy(t[x],bin,sizeof(int)*(p+1));
			tag[x]=(tag[x]+val)%(p+1);
			return;
		}
		pushdown(x);
		int mid=l+r>>1;
		if(ql<=mid)
			update(x<<1,ql,qr,l,mid,val);
		if(qr>=mid+1)
			update(x<<1|1,ql,qr,mid+1,r,val);
		pushup(x);
	}
	int query(int x,int ql,int qr,int l,int r,int tp){
		if(ql<=l&&r<=qr){
			if(!tp){
				int ret=0;
				for(int i=1;i<=p;i+=2)
					ret^=t[x][i];
				return ret;
			}
			else
				return t[x][p];
		}
		pushdown(x);
		int mid=l+r>>1,ret=0;
		if(ql<=mid)
			ret^=query(x<<1,ql,qr,l,mid,tp);
		if(qr>=mid+1)
			ret^=query(x<<1|1,ql,qr,mid+1,r,tp);
		return ret;
	}
	void solve(){
		build(1,1,n);
		rep(i,1,q){
			int op,l,r,x;
			scanf("%d",&op);
			if(!op){
				scanf("%d%d%d",&l,&r,&x),x%=p+1;
				update(1,l,r,1,n,x);
			}
			else{
				scanf("%d%d",&l,&r);
				if(p&1)
					printf("%d\n",query(1,l,r,1,n,1));
				else
					printf("%d\n",query(1,l,r,1,n,0)|query(1,l,r,1,n,1));
			}
		}
	}
}
namespace qiliao{
	void solve(){
		puts("不会不会不会");
	}
}
int main(){
	freopen("right.in","r",stdin);
	freopen("right.out","w",stdout);
	scanf("%d%d%d",&n,&q,&p);
	rep(i,1,n)
		scanf("%d",&a[i]),a[i]%=p+1;
	if(n<=5000&&q<=5000)
		nqsm::solve();
	else if(p&1)
		podd::solve();
	else if(p<=100)
		psm::solve();
	else
		qiliao::solve();
	return 0;
}
