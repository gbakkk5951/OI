#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int id,val;
	friend bool operator <(const node &a,const node &b){
		return a.val<b.val;
	}
}in[20010];
struct seg{int lson,rson,sum,ll,rr;}tree[400010];
int q[4],root[20010],st,ed,n,ans,fz,cnt=1;
void merge(seg &pos,seg &lson,seg &rson){
	pos.ll=max(lson.ll,lson.sum+rson.ll);
	pos.rr=max(rson.rr,rson.sum+lson.rr);
	pos.sum=lson.sum+rson.sum;
	return;
}
void build(int l,int r,int pos){
	tree[pos].ll=tree[pos].rr=tree[pos].sum=r-l+1;
	if(l==r) return;
	int mid=(l+r)/2;
	tree[pos].lson=++cnt;
	tree[pos].rson=++cnt;
	build(l,mid,tree[pos].lson);
	build(mid+1,r,tree[pos].rson);
	return;
}
void insert(int l,int r,int pos,int las){
	if(l==r){
		tree[pos].ll=tree[pos].rr=tree[pos].sum=-1;
		return;
	}
	int mid=(l+r)/2;
	if(st<=mid){
		tree[pos].lson=++cnt;
		tree[pos].rson=tree[las].rson;
		insert(l,mid,tree[pos].lson,tree[las].lson);
	}
	else{
		tree[pos].rson=++cnt;
		tree[pos].lson=tree[las].lson;
		insert(mid+1,r,tree[pos].rson,tree[las].rson);
	}
	merge(tree[pos],tree[tree[pos].lson],tree[tree[pos].rson]);
	return;
}
int find(int l,int r,int pos){
	if(st<=l&&r<=ed) return tree[pos].sum;
	int mid=(l+r)/2;
	if(ed<=mid) return find(l,mid,tree[pos].lson);
	if(mid<st) return find(mid+1,r,tree[pos].rson);
	return find(l,mid,tree[pos].lson)+find(mid+1,r,tree[pos].rson);
}
void findl(int l,int r,int pos){
	 if(st<=l&&r<=ed){
	 	ans=max(ans,fz+tree[pos].rr);
	 	fz+=tree[pos].sum;
	 	return;
	 }
	 int mid=(l+r)/2;
	 if(mid<ed) findl(mid+1,r,tree[pos].rson);
	 if(st<=mid) findl(l,mid,tree[pos].lson);
	 return;
}
void findr(int l,int r,int pos){
	if(st<=l&&r<=ed){
		ans=max(ans,fz+tree[pos].ll);
		fz+=tree[pos].sum;
		return;
	}
	int mid=(l+r)/2;
	if(st<=mid) findr(l,mid,tree[pos].lson);
	if(mid<ed) findr(mid+1,r,tree[pos].rson);
	return;
}
int erfen(){
	int l=0,r=n+1,mid,val;
	while(l<r){
		mid=(l+r)/2;
		st=q[1],ed=q[2];
		if(st<=ed) val=find(1,n,root[mid]);
		else val=0;
		st=q[0],ed=q[1]-1,ans=fz=0;
		if(st<=ed) findl(1,n,root[mid]);
		val+=ans;
		st=q[2]+1,ed=q[3],ans=fz=0;
		if(st<=ed) findr(1,n,root[mid]);
		val+=ans;
		if(val>=0) l=mid+1;
		else r=mid;
	}
	printf("%d\n",in[l].val);
	return in[l].val;
}
int main()
{
	int m,i,las=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&in[i].val);
		in[i].id=i;
	}
	sort(in+1,in+n+1);
	root[0]=1;
	build(1,n,1);
	for(i=1;i<=n;i++){
		root[i]=++cnt;
		st=in[i].id;
		insert(1,n,root[i],root[i-1]);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d",&q[0],&q[1],&q[2],&q[3]);
		q[0]=(q[0]+las)%n+1,q[1]=(q[1]+las)%n+1;
		q[2]=(q[2]+las)%n+1,q[3]=(q[3]+las)%n+1;
		sort(q,q+4);
		las=erfen();
	}
	return 0;
}

