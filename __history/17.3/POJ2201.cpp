#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
struct node{
	int xi,yi;
	node *l,*r,*f;
}tree[50010],null,*rt;
using namespace std;
struct _main{
int un[50010];
int in[50010];
int i2[50010];
int xi[50010];
int ansl[50010];
int ansr[50010];
int ansf[50010];
int n;
stack<node *>st;
_main(){
null.xi=-1;
null.yi=-2147483648;
scanf("%d",&n);
int i,j,k;
for(i=0;i<n;i++){
	scanf("%d%d",&in[i],&i2[i]);
	un[i]=in[i];
}
sort(un,un+n);
printf("YES\n");
for(i=0;i<n;i++){
	xi[i]=upper_bound(un,un+n,in[i])-un-1;
}
for(i=0;i<n;i++){
	un[xi[i]]=i;
}
insert();
dfs();
for(i=0;i<n;i++){
	printf("%d %d %d\n",ansf[i]+1,ansl[i]+1,ansr[i]+1);
}
}
void insert(){
	int i,j,k,l,r;
	st.push(&tree[0]);
	node *now,*kd;
	tree[0].xi=un[0];
	tree[0].yi=i2[tree[0].xi];
	tree[0].f=&null;
	tree[0].l=&null;
	tree[0].r=&null;
	rt=&tree[0];
	for(i=1;i<n;i++){
		now=&tree[i];
		tree[i].xi=un[i];
		tree[i].yi=i2[tree[i].xi];
		tree[i].f=&null;
		tree[i].l=&null;
		tree[i].r=&null;
		kd=st.top();
		if(kd->yi<now->yi){
			kd->r=now;
			now->f=kd;
			st.push(now);
			continue;
		}
		while(kd->yi>now->yi&&kd->f->yi>now->yi){
		st.pop();
		kd=kd->f;
		}
		st.pop();
		now->f=kd->f;
		now->f->r=now;
		now->l=kd;
		kd->f=now;
		if(st.empty() ){
			rt=now;
		}
		st.push(now);
	}
}
void dfs(node *now=rt){
	if(now->l!=&null){
	ansl[now->xi]=now->l->xi;	
	dfs(now->l);
	}else ansl[now->xi]=-1;
	if(now->r!=&null){
		dfs(now->r);
		ansr[now->xi]=now->r->xi;					
	}else ansr[now->xi]=-1;
	if(now->f!=&null){
		ansf[now->xi]=now->f->xi;
	}else ansf[now->xi]=-1;
}
}instance;int main(){} 
