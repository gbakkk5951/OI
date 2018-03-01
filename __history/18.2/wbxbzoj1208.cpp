#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int fa,son[2],size;
	long long val;
}tree[80010];
int root,cnt;
long long inf=4611686014132420609ll;
void update(int pos){tree[pos].size=tree[tree[pos].son[0]].size+tree[tree[pos].son[1]].size+1;}
void rotate(int pos){
	int fa=tree[pos].fa,ff=tree[fa].fa,t=(tree[fa].son[1]==pos);
	tree[fa].son[t]=tree[pos].son[t^1];
	if(tree[fa].son[t]) tree[tree[fa].son[t]].fa=fa;
	tree[pos].son[t^1]=fa;
	tree[fa].fa=pos;
	tree[pos].fa=ff;
	if(ff)tree[ff].son[tree[ff].son[1]==fa]=pos;
	update(fa);
	update(pos);
	return;
}

void splay(int pos){
	for(int fa;(fa=tree[pos].fa);rotate(pos)){
		int ff=tree[fa].fa;
		if(ff){
			if((tree[ff].son[0]==fa&&tree[fa].son[0]==pos)||(tree[ff].son[1]==fa&&tree[fa].son[1]==pos)) rotate(fa);
			else rotate(pos);
		}
	}
	root=pos;
}
void insert(long long val){
	int pos=root,fa;
	while(pos){
		fa=pos;
		pos=tree[pos].son[tree[pos].val<val];
	}
	pos=++cnt;
	tree[pos].fa=fa;
	tree[pos].size=1;
	tree[pos].val=val;
	tree[fa].son[tree[fa].val<val]=pos;
	splay(pos);
	return;
}
void yu(){
	root=cnt=1;
	tree[1].size=1;
	tree[1].val=-inf;
	insert(inf);
	return;
}
long long qian(long long val){
	int pos=root;
	long long ret=-inf;
	while(tree[pos].son[tree[pos].val<val]){
		if(tree[pos].val<val) ret=tree[pos].val;
		pos=tree[pos].son[tree[pos].val<val];
	}if(tree[pos].val<val) ret=tree[pos].val;
	return ret;
}
long long hou(long long val){
	long long ret=inf;
	int pos=root;
	while(tree[pos].son[tree[pos].val<=val]){
		if(tree[pos].val>val) ret=tree[pos].val;
		pos=tree[pos].son[tree[pos].val<=val];
	}if(tree[pos].val>val) ret=tree[pos].val;
	return ret;
}
int find(long long val){
	int pos=root;
	if(tree[pos].val==val) return pos;
	while(tree[pos].son[tree[pos].val<val]){
		pos=tree[pos].son[tree[pos].val<val];
		if(tree[pos].val==val) return pos;
	}
	return 0;
}
void del(int pos){
	splay(pos);
	if(tree[pos].son[0]*tree[pos].son[1]==0){
		root=tree[pos].son[0]+tree[pos].son[1];
		tree[root].fa=0;
		return;
	}
	int tmp=tree[pos].son[0];
	while(tree[tmp].son[1]) tmp=tree[tmp].son[1];
	splay(tmp);
	tree[tmp].son[1]=tree[pos].son[1];
	tree[tree[pos].son[1]].fa=tmp;
	update(tmp);
	return;
}
int main()
{
	int n,t,p;
	long long ans=0ll,a,q,h,imod=1000000ll;
	yu();
	scanf("%d",&n);
	while(n--){
		scanf("%d%lld",&t,&a);
		if(t){
			if(tree[root].size==2) continue;
			p=find(a);
			if(p){
				del(p);
				continue;
			}
			q=qian(a);
			h=hou(a);
			if(h-a<a-q) del(find(h)),ans+=(h-a)%imod;
			else del(find(q)),ans+=(a-q)%imod;
			ans%=imod;
		}
		else insert(a);
	}
	printf("%lld",ans);
}

