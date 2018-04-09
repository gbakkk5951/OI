#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int lson,rson,val;
}tree[10 * 1600000];
int head[80010],nxt[160010],whr[160010],cnt=1,in[80010],uni[80010],bz[80010][17],deep[80010];
int fa[80010],siz[80010],root[80010],st,n,m,tot;
char s[5];
void add(int a,int b){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	head[a]=cnt++;
	return;
}
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void insert(int l,int r,int pos,int las){
	tree[pos].val=tree[las].val+1;
	if(l==r) return;
	int mid=(l+r)/2;
	if(st<=mid){
		tree[pos].rson=tree[las].rson;
		if(tree[pos].lson==0) tree[pos].lson=++tot;
		insert(l,mid,tree[pos].lson,tree[las].lson);
	}
	else{
		tree[pos].lson=tree[las].lson;
		if(tree[pos].rson==0) tree[pos].rson=++tot;
		insert(mid+1,r,tree[pos].rson,tree[las].rson);
	}
	return;
}
void dfs(int pos,int las){
	int i,t;
	st=lower_bound(uni+1,uni+m+1,in[pos])-uni;
	insert(1,m,root[pos],root[las]);
	deep[pos]=deep[las]+1;
	bz[pos][0]=las;
	for(i=1;i<=16;i++) bz[pos][i]=bz[bz[pos][i-1]][i-1];
	for(i=head[pos];i;i=nxt[i]){
		t=whr[i];
		if(whr[i]!=las) dfs(t,pos);
	}
	return;
}
int find(int l,int r,int r1,int r2,int r3,int r4,int k){
	if(l==r) return l;
	int mid=(l+r)/2,lv=tree[tree[r1].lson].val+tree[tree[r2].lson].val-tree[tree[r3].lson].val-tree[tree[r4].lson].val;
	if(lv>=k) return find(l,mid,tree[r1].lson,tree[r2].lson,tree[r3].lson,tree[r4].lson,k);
	return find(mid+1,r,tree[r1].rson,tree[r2].rson,tree[r3].rson,tree[r4].rson,k-lv);
}
int getlca(int a,int b){
	if(deep[a]<deep[b]) swap(a,b);
	for(int i=16;i>=0;i--) if(deep[bz[a][i]]>=deep[b]) a=bz[a][i];
	if(a==b) return a;
	for(int i=16;i>=0;i--) if(bz[a][i]!=bz[b][i]) a=bz[a][i],b=bz[b][i];
	return bz[a][0];
}
int main()
{
	int q,a,b,lca,k,i,ans=0;
	scanf("%d%d%d%d",&i,&n,&m,&q);tot=n;
	for(i=1;i<=n;i++) fa[i]=i,root[i]=i,siz[i]=1;
	for(i=1;i<=n;i++) scanf("%d",&in[i]),uni[i]=in[i];
	for(i=1;i<=m;i++) scanf("%d%d",&a,&b),siz[find(b)]+=siz[find(a)],fa[find(a)]=find(b),add(a,b),add(b,a);
	sort(uni+1,uni+n+1);m=unique(uni+1,uni+n+1)-uni-1;
	for(i=1;i<=n;i++) if(find(i)==i) dfs(i,0);
	for(i=1;i<=q;i++){
		scanf("%s%d%d",s,&a,&b);
		a=a^ans,b=b^ans;
		if(s[0]=='Q'){
			scanf("%d",&k);k=k^ans;
			lca=getlca(a,b);
			ans=find(1,m,root[a],root[b],root[lca],root[bz[lca][0]],k);
			printf("%d\n",uni[ans]);
			ans=uni[ans];
		}
		else{
			if(siz[find(a)]>siz[find(b)]) swap(a,b);
			siz[find(b)]+=siz[find(a)];
			fa[find(a)]=find(b);
			add(a,b),add(b,a);
			dfs(a,b);
		}
	}
	cerr<<tot<<endl;
	return 0;
}

