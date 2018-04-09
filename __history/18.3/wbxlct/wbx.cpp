#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
struct node{
	int son[2],fa;
	bool flag;
}tree[10010];
char in[10],s;
stack<int>sta;
int read(){
	int ret=0;
	char c=getchar();
	while(c<'0'||'9'<c) c=getchar();
	while('0'<=c&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret;
}
bool isroot(int pos){return tree[tree[pos].fa].son[0]!=pos&&tree[tree[pos].fa].son[1]!=pos;}
void pushdown(int pos){
	if(tree[pos].flag){
		swap(tree[tree[pos].son[0]].son[0],tree[tree[pos].son[0]].son[1]);
		swap(tree[tree[pos].son[1]].son[0],tree[tree[pos].son[1]].son[1]);
		tree[tree[pos].son[1]].flag^=1,tree[tree[pos].son[0]].flag^=1;
		tree[pos].flag=false;
	}
	return;
}

void rotate(int pos){
	int fa=tree[pos].fa,ff=tree[fa].fa,t=(tree[fa].son[1]==pos);
	
	if(isroot(fa)) tree[ff].son[tree[ff].son[1]==fa]=pos;
	printf("t = %d\n", t);
	tree[fa].son[t]=tree[pos].son[t^1];
	if(tree[fa].son[t]) tree[tree[fa].son[t]].fa=fa;
	tree[pos].son[t^1]=fa;
	tree[fa].fa=pos;
	tree[pos].fa=ff;
	
	return;
}
/*
void rotate(int x)
{
    int y=tree[x].fa,z=tree[y].fa;
	int pos = x == tree[y].son[1];
//	l,pos ^ 1;
//    if(tree[y].son[0]==x)pos=0;else pos=1;pos ^ 1=pos^1;
    if(!isroot(y))
    {
        if(tree[z].son[0]==y)tree[z].son[0]=x;else tree[z].son[1]=x;
    }
    tree[x].fa=z;tree[y].fa=x;tree[tree[x].son[pos ^ 1]].fa=y;
    tree[y].son[pos]=tree[x].son[pos ^ 1];
	tree[x].son[pos ^ 1]=y;
}
*/
void splay(int pos){
	sta.push(pos);
	for(int i=pos;isroot(i)==false;i=tree[i].fa) sta.push(tree[i].fa);
	while(!sta.empty()) pushdown(sta.top()),sta.pop();
	for(int fa,ff;isroot(pos)==false;rotate(pos)){
		
		fa=tree[pos].fa,ff=tree[fa].fa;
		if(isroot(fa)==false){
			if((tree[ff].son[0]==fa&&tree[fa].son[0]==pos)||(tree[ff].son[1]==fa&&tree[fa].son[1]==pos)) rotate(fa);
			else rotate(pos);
		}
	}
	return;
}
void access(int pos){
	int t=0;
	while(pos){
		
		splay(pos);
		tree[pos].son[1]=t;
		t=pos,pos=tree[pos].fa;
	}
	return;
}
void makeroot(int pos){
	access(pos),splay(pos);
	swap(tree[pos].son[0],tree[pos].son[1]);
	tree[pos].flag^=1;
	return;
}
void link(int x,int y){
	makeroot(x);
	tree[x].fa=y;
//	splay(x);
	return;
}
void cut(int x,int y){
	makeroot(x),access(y),splay(y);
	tree[y].son[0]=tree[x].fa=0;
	return;
}
int main()
{
	freopen("data0.in", "r", stdin);
	int n,q,i,a,b;
	scanf("%d%d",&n,&q);
	for(i=1;i<=q;i++){
		cerr<<"i = " <<i<<endl;
		scanf("%s",in);
		a=read(),b=read();
		if(in[0]=='C') link(a,b);
		else if(in[0]=='D') cut(a,b);
		else{
			access(a),splay(a);
			while(tree[a].son[0]) /*rintf("s %d = %d\n", a, tree[a].son[0]),*/ a=tree[a].son[0];
			access(b);splay(b);
			while(tree[b].son[0]) b=tree[b].son[0];
			if(a==b) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

