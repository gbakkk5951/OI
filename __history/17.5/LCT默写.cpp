#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cctype>
const int node_size=64;
using namespace std;
struct node;
node * null;
struct st_ini_1{

st_ini_1(){
	null=(node *)malloc(node_size);
}

}st_ini_1_instance;


struct node{
	node *s[2],*fa;
	node(){
		s[0]=null;
		s[1]=null;
		fa=null;
	}
	int size/*,add,sum,val*/;
	char rsig;
}pos[200010];



struct st_Main{
int inline min(int a,int b){
	return (a+b-i_abs(a-b))>>1;
}

int inline max(int a,int b){
	return (a+b+i_abs(a-b))>>1;
}

int inline i_abs(int a){
	return a>>31^((a>>31)+a);
}	
void inline refresh(node *nd){
	nd->size=nd->s[0]->size+nd->s[1]->size+1;
//	nd->sum=nd->s[0]->sum+nd->s[1]->sum+nd->val;
}
void rotate(node *nd,char son){
//	printf("in _rotate\n");
	node *y=nd->s[son];
	nd->s[son]=y->s[son^1];
	y->s[son^1]->fa=nd;
	null->fa=null;
	if(nd->fa->s[0]==nd){
		nd->fa->s[0]=y;
	}else if(nd->fa->s[1]==nd){
		nd->fa->s[1]=y;
	}
	y->s[son^1]=nd;
	y->fa=nd->fa;
	nd->fa=y;
	refresh(nd);
	refresh(y);
//	printf("out _rotate\n");
}
	
void down_to(node *nd){
	if(nd->fa->s[0]==nd || nd->fa->s[1]==nd){
		down_to(nd->fa);
	}spread(nd);
}
void spread(node *nd){
/*	if(nd->add){	
		if(nd->s[0]!=null){
			nd->s[0]->val+=nd->add;
			nd->s[0]->add+=nd->add;
		}
		if(nd->s[1]!=null){
			nd->s[1]->val+=nd->add;
			nd->s[1]->add+=nd->add;
		}
		nd->add=0;
	}
*/	if(nd->rsig){
		swap(nd->s[0],nd->s[1]);
		nd->s[0]->rsig ^=1;
		nd->s[1]->rsig ^=1;
		nd->rsig =0;
	}
}	
void splay(node *nd){
	down_to(nd);
	node *fa,*fafa;
	while(1){
		fa=nd->fa;
		fafa=fa->fa;
		if(fa->s[0]==nd){
			if(fafa->s[0]==fa){
				rotate(fafa,0);
			}
			rotate(fa,0);
		}else if(fa->s[1]==nd){
			if(fafa->s[1]==fa){
				rotate(fafa,1);
			}
			rotate(fa,1);
		}else return;
	}
}
void access(node *nd){
//	printf("access");
	node *y=null;
	while(nd!=null){
//		printf("splay");
		splay(nd);
//		printf("sf\n");
		nd->s[1]=y;
		y=nd;
		nd=nd->fa;
	}
//	printf("access_out");
}
void inline move_to_root(node *nd){
	access(nd);
	splay(nd);
	nd->rsig=1;
}
void inline link(node *nd_a,node *nd_b){
//	printf("link");
	move_to_root(nd_a);
	nd_a->fa=nd_b;
}
void inline cut(node *nd_a,node *nd_b){
	move_to_root(nd_a);
	access(nd_b);
	splay(nd_b);
	nd_a->fa=null;
	nd_b->s[0]=null;
}	
int query_size(node* nd_a,node *nd_b){
	move_to_root(nd_a);
	access(nd_b);
	splay(nd_b);
	return nd_b->s[0]->size+1;
}
/*
int query_sum(node* nd_a,node *nd_b){
	move_to_root(nd_a);
	access(nd_b);
	splay(nd_b);
	return nd_b->s[0]->sum+nd_b->val;
}	*/

void st_Main_ini(){
	null->s[0]=null;
	null->s[1]=null;
	null->fa=null;
	null->size=0;
//	null->sum=0;
//	null->val=0;
//	null->add=0;
	null->rsig=0;
}
	
int k[200010];
int n;	
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
st_Main(){
	st_Main_ini();
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
			printf("%d\n",query_size(pos+b,pos+n)-1);
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

}st_Main_instance;int main(){}
