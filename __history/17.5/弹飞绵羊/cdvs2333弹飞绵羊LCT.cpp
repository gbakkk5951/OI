#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
struct node;
///////////////////////////////
node *null;
struct null_ini{
	null_ini(){
		null=(node *)malloc(20);
	}
}null_ini_Instance;

struct node{
	node * ls, * rs, * fa;
	int siz;
	char sig;	
	node(){
		ls=null;
		rs=null;
		fa=null;
	}
}pos[200010];
int k[200010];
int n;	



///////////////////////////////
struct _Main{
	
int read(){
	int ans;
	char t;
	while(!isdigit( t =getchar()));
	ans=t-'0';
	while( isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}	

int inline min(int a,int b){
	return (a+b-i_abs(a-b))>>1;
}

int inline max(int a,int b){
	return (a+b+i_abs(a-b))>>1;
}

int inline i_abs(int a){
	return a>>31^((a>>31)+a);
}

void inline left_rotate(node *a){
	node *y=a->rs;
	a->rs=y->ls;
	y->ls->fa=a;
	null->fa=null;
	if(a==a->fa->ls){
		a->fa->ls=y;
	}else if(a==a->fa->rs){
		a->fa->rs=y;
	}
	y->fa=a->fa;
	a->fa=y;
	y->ls=a;
	a->siz=a->ls->siz+a->rs->siz+1;
	y->siz=y->ls->siz+y->rs->siz+1;
}

void inline right_rotate(node *a){
	node *y=a->ls;
	a->ls=y->rs;
	y->rs->fa=a;
	null->fa=null;
	if(a==a->fa->ls){
		a->fa->ls=y;
	}else if(a==a->fa->rs){
		a->fa->rs=y;
	}
	y->fa=a->fa;
	a->fa=y;
	y->rs=a;
	a->siz=a->ls->siz+a->rs->siz+1;
	y->siz=y->ls->siz+y->rs->siz+1;
}

void push_up(node *a){
	if(a==a->fa->ls||a==a->fa->rs){
		push_up(a->fa);
	}push_down(a);
}
void inline push_down(node *a){
	if(a->sig){
		swap(a->ls,a->rs);
		a->ls->sig^=1;
		a->rs->sig^=1;
		a->sig = 0;
	}
}
void splay(node *a){

	push_up(a);
	while(1){
		if(a->fa->ls==a){
			if(a->fa->fa->ls==a->fa){
				right_rotate(a->fa->fa);
			}
			right_rotate(a->fa);
		}else if(a->fa->rs==a){
			if(a->fa->fa->rs==a->fa){
				left_rotate(a->fa->fa);
			}
			left_rotate(a->fa);			
		}else return;

	}
}

void access(node *a){

	node *y=null;
	while(a!=null){
		splay(a);
		a->rs=y;
		y=a;
		a=a->fa;
	}
}

void inline move_to_root(node *a){
	access(a);
	splay(a);
	a->sig^=1;
}
void inline link(node *a,node *b){
	move_to_root(a);
	a->fa=b;
	
}
void inline cut (node *a,node *b){
	move_to_root(a);
	access(b);
	splay(b);
	a->fa=null;
	b->ls=null;
}
int query(node *a){
	move_to_root(pos+n);
	access(a);
	splay(a);
	return a->ls->siz;
}
void _Main_ini(){
	null->ls=null;
	null->rs=null;
	null->fa=null;
	null->sig =0;
	null->siz =0;
}
_Main(){
	_Main_ini();
	n=read();
	int i,a,b,c,q,l,m;
	for(i=0;i<n;i++){
		k[i]=read();
		if(i+k[i]>=n){
			link(pos+n,pos+i);
		}else{
			link(pos+i+k[i],pos+i);
		}
	}
	q=read();
	for(i=0;i<q;i++){
		a=read();
		b=read();
		if(a==1){
			printf("%d\n",query(pos+b));
		}else{
			c=read();
			l=min(n,k[b]+b);
			m=min(n,c+b);
			k[b]=c;
			if(l!=m){
				cut(pos+b,pos+l);
				link(pos+b,pos+m);
			}
		}
	}
}	
}cdvs2333_lct;int main(){}
