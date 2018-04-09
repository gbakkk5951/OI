#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int fa,son[2],siz,val,lazy;
	char pri;
}tree[250010];
int root,cnt,inf=1061109567;
char s[250010];
void update(int pos){tree[pos].siz=tree[tree[pos].son[0]].siz+tree[tree[pos].son[1]].siz+1;}
void pushdown(int pos){
	if(tree[pos].lazy){
		tree[tree[pos].son[0]].lazy+=tree[pos].lazy;
		tree[tree[pos].son[1]].lazy+=tree[pos].lazy;
		tree[tree[pos].son[0]].val+=tree[pos].lazy;
		tree[tree[pos].son[1]].val+=tree[pos].lazy;
		tree[pos].lazy=0;
	}
}
void rotate(int pos){
	int fa=tree[pos].fa,ff=tree[fa].fa,t=(tree[fa].son[1]==pos);
	pushdown(fa),pushdown(pos);
	tree[fa].son[t]=tree[pos].son[t^1];
	if(tree[fa].son[t]) tree[tree[fa].son[t]].fa=fa;
	tree[pos].son[t^1]=fa;
	tree[fa].fa=pos;
	tree[pos].fa=ff;
	if(ff) tree[ff].son[tree[ff].son[1]==fa]=pos;
	update(fa),update(pos);
	return;
}
void splay(int pos){
	pushdown(pos);
	for(int fa=tree[pos].fa,ff;(fa=tree[pos].fa);rotate(pos)){
		ff=tree[fa].fa;
		if(ff){
			if((tree[fa].son[0]==pos&&tree[ff].son[0]==fa)||(tree[fa].son[1]==pos||tree[ff].son[1]==fa)) rotate(fa);
			else rotate(pos);
		}
	}root=pos;
}
void insert(int val,char in){
	int pos=root,fa;
	while(pos){
		pushdown(pos);fa=pos;
		pos=tree[pos].son[tree[pos].val<val];
	}
	pos=++cnt;
	tree[fa].son[tree[fa].val<val]=pos;
	tree[pos].fa=fa;
	tree[pos].pri=in;
	tree[pos].val=val;
	tree[pos].siz=1;
	splay(pos);
}
void yu(){
	root=cnt=tree[1].siz=1;
	tree[1].val=inf;
	insert(-inf,0);
}
int find(int val){
	int pos=root;
	if(tree[pos].val==val) return pos;
	while(tree[pos].son[tree[pos].val<val]){
		pushdown(pos);
		pos=tree[pos].son[tree[pos].val<val];
		if(tree[pos].val==val) return pos;
	}return 0;
}
int main()
{
	int i,l,r,pos,len;
	yu();
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++) insert(i,s[i]);
	while(scanf("%s",s)!=EOF){
		if(s[0]=='E') break;
		if(s[0]=='I'){
			scanf("%s%d",s,&l);
			len=strlen(s);
			splay(find(l-1));
			tree[tree[root].son[1]].lazy+=len;
			tree[tree[root].son[1]].val+=len;
			for(i=0;i<len;i++) insert(i+l,s[i]);
		}
		else{
			scanf("%d%d",&l,&r);
			for(i=l;i<=r;i++) pos=find(i),printf("%c",tree[pos].pri);
			printf("\n");
		}
	}
	return 0;
}

