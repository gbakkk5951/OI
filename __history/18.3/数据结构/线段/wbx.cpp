#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int st,ed,cnt,ans,imod=39989;
double mx,hi[40000];
struct node{
	int x,y,xx,yy;
	double k,b;
	void read(){
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		x=(x+ans-1)%imod+1;
		xx=(xx+ans-1)%imod+1;
		y=(y+ans-1)%1000000000+1;
		yy=(yy+ans-1)%1000000000+1;
		if(x>xx) swap(x,xx),swap(y,yy);
		if(x!=xx){
			k=double(yy-y)/(double)(xx-x);
			b=(double)y-k*(double)x;
		}
		else if(y>yy) swap(y,yy);
	}
	double f(double pos){return k*pos+b;}
	
}in[100010];
int tree[160000],id[40000];
void find(int l,int r,int pos){
	if(tree[pos]){
		if(in[tree[pos]].f(st)>mx){
			mx=in[tree[pos]].f(st);
			ans=tree[pos];
		}
		else if(in[tree[pos]].f(st)==mx){
			ans=min(ans,tree[pos]);
		}
	}
	if(l==r){
		if(mx<hi[st]) ans=id[st];
		else if(mx==hi[st]) ans=min(ans,id[st]);
		return;
	}
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(st<=mid) find(l,mid,lson);
	else find(mid+1,r,rson);
	return;
}
void insert(int l,int r,int pos){
	if(st<=l&&r<=ed){
		if(tree[pos]==0){
			tree[pos]=cnt;
			return;
		}
		double l1=in[cnt].f(l),l2=in[tree[pos]].f(l),r1=in[cnt].f(r),r2=in[tree[pos]].f(r);
		int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
		if(l1>l2&&r1>r2){tree[pos]=cnt;return;}
		if(l1<=l2&&r1<=r2) return;
		insert(l,mid,lson);
		insert(mid+1,r,rson);
		return;
	}
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(st<=mid) insert(l,mid,lson);
	if(mid<ed) insert(mid+1,r,rson);
	return;
}
int main()
{
//	freopen("rg.out", "w", stdout);
//	print(1, 1, imod);
//	freopen("seg0.in", "r", stdin);
	int n,i,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
//		if (i % 100 == 0)cerr<<"i = "<< i << endl;
		scanf("%d",&t);
		if(t==0){
			scanf("%d",&st);
			st=(st+ans-1)%imod+1;
			mx=-1000.0,ans=0;
			find(1,imod,1);
			printf("%d\n",ans);
		}
		else{
			in[++cnt].read();
			st=in[cnt].x,ed=in[cnt].xx;
			if(st==ed){
				if(hi[st]<in[cnt].yy){
					hi[st]=in[cnt].yy;
					id[st]=cnt;
				}
			}
			else insert(1,imod,1);
		}
	}
}

