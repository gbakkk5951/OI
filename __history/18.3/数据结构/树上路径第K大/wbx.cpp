#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int head[80010],nxt[160010],whr[160010],in[80010],size[80010],wson[80010],fa[80010],cnt=1;
int root[400010],dfn[80010],top[80010],deep[80010],inf=1061109567,n,m;
struct node{
	int son[2],fa,val,size,cnt;
}tree[9900000];
void add(int a,int b){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	head[a]=cnt++;
	return;
}
void update(int pos){tree[pos].size=tree[pos].cnt+tree[tree[pos].son[0]].size+tree[tree[pos].son[1]].size;}
void rotate(int pos){
	int fa=tree[pos].fa,ff=tree[fa].fa,t=(tree[fa].son[1]==pos);
	tree[fa].son[t]=tree[pos].son[t^1];
	if(tree[fa].son[t]) tree[tree[fa].son[t]].fa=fa;
	tree[pos].son[t^1]=fa;
	tree[fa].fa=pos;
	tree[pos].fa=ff;
	if(ff) tree[ff].son[tree[ff].son[1]==fa]=pos;
	update(fa);update(pos);
	return;
}
void splay(int pos,int rt){
	for(int fa;(fa=tree[pos].fa);rotate(pos)){
		int ff=tree[fa].fa;
		if(ff){
			if((tree[ff].son[0]==fa&&tree[fa].son[0]==pos)||(tree[ff].son[1]==fa&&tree[fa].son[1]==pos)) rotate(fa);
			else rotate(pos);
		}
	}
	root[rt]=pos;
	return;
}
int find(int val,int rt){
	int pos=root[rt];
	if(tree[pos].val==val) return pos;
	while(tree[pos].son[tree[pos].val<val]){
		pos=tree[pos].son[tree[pos].val<val];
		if(tree[pos].val==val) return pos;
	}return 0;
}
void insert(int val,int rt){
	int pos=root[rt],fa;
	while(pos&&tree[pos].val!=val) fa=pos,pos=tree[pos].son[tree[pos].val<val];
	if(pos) tree[pos].cnt++;
	else{
		pos=cnt++;
		tree[pos].cnt=tree[pos].size=1;
		tree[pos].fa=fa;
		tree[pos].val=val;
		tree[fa].son[tree[fa].val<val]=pos;
	}
	splay(pos,rt);
	return;
}
void del(int pos,int rt){
	splay(pos,rt);
	if(tree[pos].cnt>1){
		tree[pos].cnt--;
		tree[pos].size--;
		return;
	}
	if(tree[pos].son[0]==0||tree[pos].son[1]==0){
		root[rt]=tree[pos].son[0]+tree[pos].son[1];
		tree[root[rt]].fa=0;
		return;
	}
	int tmp=tree[pos].son[0];
	while(tree[tmp].son[1]) tmp=tree[tmp].son[1];
	splay(tmp,rt);
	tree[tmp].son[1]=tree[pos].son[1];
	if(tree[tmp].son[1]) tree[tree[tmp].son[1]].fa=tmp;
	update(tmp);
}
int qrank(int val,int rt){
	int pos=root[rt],ret=0;
	while(pos){
		if(val<=tree[pos].val){
			ret+=tree[tree[pos].son[1]].size+tree[pos].cnt;
			pos=tree[pos].son[0];
		}
		else pos=tree[pos].son[1];
	}
	return ret-1;
}
void dfs1(int pos){
	size[pos]=1;
	deep[pos]=deep[fa[pos]]+1;
	for(int i=head[pos];i;i=nxt[i]){
		int t=whr[i];
		if(t==fa[pos]) continue;
		fa[t]=pos;dfs1(t);
		size[pos]+=size[t];
		if(size[t]>size[wson[pos]]) wson[pos]=t;
	}
	return;
}
void dfs2(int pos){
	dfn[pos]=++cnt;
	if(wson[pos]){
		top[wson[pos]]=top[pos];
		dfs2(wson[pos]);
	}
	for(int i=head[pos];i;i=nxt[i]){
		int t=whr[i];
		if(t!=fa[pos]&&t!=wson[pos]){
			top[t]=t;
			dfs2(t);
		}
	}
	return;
}
int st,ed,val;
void yu(int l,int r,int pos){
	root[pos]=cnt;
	tree[cnt].size=tree[cnt].cnt=1;
	tree[cnt++].val=inf;
	insert(-inf,pos);
	if(l==r) return;
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	yu(l,mid,lson);
	yu(mid+1,r,rson);
	return;
}
void build(int l,int r,int pos){
	insert(val,pos);
	if(l==r) return;
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(st<=mid) build(l,mid,lson);
	else build(mid+1,r,rson);
	return;
}
void change(int l,int r,int pos){
	int tmp=find(val,pos);
	del(tmp,pos);
	if(l==r) return;
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(st<=mid) change(l,mid,lson);
	else change(mid+1,r,rson);
	return;
}
int sfind(int l,int r,int pos){
	if(st<=l&&r<=ed) return qrank(val,pos);
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(st<=mid&&mid<ed) return sfind(l,mid,lson)+sfind(mid+1,r,rson);
	if(st<=mid) return sfind(l,mid,lson);
	else return sfind(mid+1,r,rson);
}
bool check(int a,int b,int mid,int k){
	int num=0;val=mid;
	while(top[a]!=top[b]){
		if(deep[top[a]]>deep[top[b]]) swap(a,b);
		st=dfn[top[b]],ed=dfn[b],b=top[b],b=fa[b];
		num+=sfind(1,n,1);
	}
	if(deep[a]>deep[b]) swap(a,b);
	st=dfn[a],ed=dfn[b];
	num+=sfind(1,n,1);
	if(num>=k) return true;
	return false;
}
int main()
{
	int i,a,b,k,l,r,mid,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&in[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs1(1);
	cnt=0;
	top[1]=1;
	dfs2(1);
	cnt=1;
	yu(1,n,1);
	for(i=1;i<=n;i++){
		st=dfn[i],val=in[i];
		build(1,n,1);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&k,&a,&b);
		if(k==0){
			st=dfn[a],val=in[a];
			change(1,n,1);
			val=in[a]=b;
			build(1,n,1);
		}
		else{
			l=0,r=10000001,ans=-1;
			while(l<r){
				mid=(l+r)/2;
				if(check(a,b,mid,k)) ans=mid,l=mid+1;
				else r=mid;
			}
			if(ans==-1) printf("invalid request!\n");
			else printf("%d\n",ans);
		}
	}
	return 0;
}
