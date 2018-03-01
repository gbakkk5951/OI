using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<cmath>
namespace Protector{


const int inf=0x3f3f3f3f;
const int skipnodepoolsize = 2000000;
const int skiplistpoolsize = 132000;
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
		a*=f;
	}
struct	SkipNode{
	int val,size;
	SkipNode *l,*r,*u,*d;
}skipnodepool[skipnodepoolsize+5];
int skipnodepoolidx;
queue<SkipNode *>q;

inline SkipNode * NewSkipNode(){
	if(!q.empty()){
		SkipNode * ret = q.front();
		q.pop();
		return ret;
	}else if(skipnodepoolidx<skipnodepoolsize){
		return &skipnodepool[skipnodepoolidx++];
	}else {
		return new SkipNode;
	}
}


struct SkipList{
	SkipNode *L[10],*R[10],*now[10];
	int mxh;
	void build(int _mxh){
		int i;
		mxh=_mxh;
		for(i=0;i<mxh;i++){
			L[i]=NewSkipNode();
			R[i]=NewSkipNode();
			L[i]->r=R[i];R[i]->l=L[i];
			L[i]->val=-inf;R[i]->val=inf;
			if(i) {
				L[i]->d=L[i-1];
				L[i-1]->u=L[i];
				R[i]->d=R[i-1];
				R[i-1]->u=R[i];						
			}
		}
		
	}
	void inline ininow(){
		memcpy(now,L,sizeof(L));
	}
	int lowerfind(int val){ // <= max
		int i,size=0;
		ininow();
		for(i=mxh-1;i>=0;i--){
			while(now[i]->r->val <= val){
				size+=now[i]->size;
				now[i]=now[i]->r;
			}
			if(i) now[i-1]=now[i]->d;			
		}
		return size;
	}
	int upperfind(int val){// >= min
		int i,size=0;
		ininow();
		for(i=mxh-1;i>=0;i--){
			while(now[i]->r->val < val){
				size+=now[i]->size;
				now[i]=now[i]->r;
			}
			if(i) now[i-1]=now[i]->d;			
		}
		size++;
		now[0]=now[0]->r;
		for(i=1;i<mxh;i++){
			if(now[i-1]->u){
				now[i]=now[i-1]->u;
			}else{
				break;
			}
		}
		return size;
	}
	int inline predecessor(int val){
		lowerfind(val-1);
		return now[0]->val;
	}
	int inline successor(int val){
		upperfind(val+1);
		return now[0]->val;
	}

	void inline dislink(SkipNode *nd){
		nd->l->r=nd->r;
		nd->r->l=nd->l;

	}
	void clearnode(SkipNode *nd){
		nd->u=nd->d=nd->l=nd->r=0;
		q.push(nd);		
	}
	void erase(SkipNode *nd){
		getleft(nd);
		SkipNode *tmp;
		while(nd){
			dislink(nd);
			tmp=nd->u;
			clearnode(nd);
			nd=tmp;
		}
		int i;
		for(i=0;i<mxh;i++){
			getsize(now[i]);
		}
	}
	void inline link(SkipNode *nd,SkipNode *left){
		nd->l=left;
		nd->r=left->r;
		nd->l->r=nd;
		nd->r->l=nd;
	}
	void insert(int val){
		SkipNode *nd;
		nd=NewSkipNode();
		nd->val=val;
		link(nd,now[0]);
		getsize(nd);
		int i;
		for(i=1;i<mxh && (rand()&3)==1;i++){
			nd->u=NewSkipNode();
			nd->u->d=nd;
			nd=nd->u;
			nd->val=val;
			link(nd,now[i]);
			getsize(nd);
		}
		for(i=0;i<mxh;i++){
			getsize(now[i]);
		}
	}
	void getleft(SkipNode *nd){
		now[0]=nd->l;
		int i;
		SkipNode *tmp=now[0];
		for(i=1;i<mxh;i++){
			while(!tmp->u){
				tmp=tmp->l;
			}
			tmp=now[i]=tmp->u;
		}
	}
	void getsize(SkipNode *nd){
		if(!nd->d){
			nd->size=1;
			return ;
		}
		SkipNode *tmp=nd->d->r;
		nd->size=nd->d->size;
		while(!tmp->u){
			nd->size+=tmp->size;
			tmp=tmp->r;
		}
	}
}skiplistpool[skiplistpoolsize+5];


int skiplistpoolidx;
inline SkipList * NewSkipList(int mxh){
	SkipList *ret;
	if(skiplistpoolidx < skiplistpoolsize){
		ret = &skiplistpool[skiplistpoolidx++];
	}else {
		ret = new SkipList;
	}
	ret->build(min(max(mxh,1),10));
	return ret;
}

int base;
int n,arr[70000];
struct SegmentTree{
	SkipList *node[132000];
	void build(){
		int i,j,k,t;
		int p;
		for(j=1,p=1;j<=base;j<<=1,p++){
			for(i=1,t=base/j;i<=base&&i<=n;i+=j,t++){
				node[t]=NewSkipList((p+1)>>1);
				for(k=1;k<=j;k++){
					node[t]->lowerfind(arr[k+i-1]);
					node[t]->insert(arr[k+i-1]);
				}
			}
		}
		
	}
	
	int getrank(int l,int r,int val,int nd=1,int nl=1,int nr=base){		
		if(l>nr || r<nl)return 0; 
		if(l<=nl && r>=nr) return node[nd]->upperfind(val)-(nd!=1);
		return getrank(l,r,val,nd<<1,nl,(nl+nr)>>1)
			   +getrank(l,r,val,nd<<1|1,(nl+nr>>1)+1,nr)+(nd==1);
	}
	int getval(int l,int r,int rank){
		int bl,br,mid;
		bl=-inf;
		br=inf;
		while(bl<br){
			mid=(bl+br>>1);
			int tst;
			if((tst=getrank(l,r,mid+1))<=rank){
				bl=mid+1;
			}else{
				br=mid;
			}
		}
		return bl;
	}
	
	void change(int pos,int val,int nd=1,int nl=1,int nr=base){
		if(nl<=pos && nr>=pos){
			node[nd]->lowerfind(arr[pos]); 
			node[nd]->erase(node[nd]->now[0]);
			node[nd]->lowerfind(val);
			node[nd]->insert(val);
			if(nl!=nr){
				change(pos,val,nd<<1,nl,(nr+nl)>>1);
				change(pos,val,nd<<1|1,((nr+nl)>>1)+1,nr);
			}
		}
	}
	int predecessor(int l,int r,int val,int nd=1,int nl=1,int nr=base){
		if(l<=nl && r>=nr){
			return node[nd]->predecessor(val);
		}else if(l>nr || r <nl){
			return -inf;
		}else {
			return max(predecessor(l,r,val,nd<<1,nl,(nl+nr)>>1),
					   predecessor(l,r,val,nd<<1|1,(nl+nr>>1)+1,nr)
					   );
		}
		
	}
	int successor  (int l,int r,int val,int nd=1,int nl=1,int nr=base){
		if(l<=nl && r>=nr){
			return node[nd]->successor(val);
		}else if(l>nr || r <nl){
			return inf;
		}else {
			return min(successor(l,r,val,nd<<1,nl,(nl+nr)>>1),
					   successor(l,r,val,nd<<1|1,(nl+nr>>1)+1,nr)
					   );
		}		
	}
}tree;



struct _Main{
	_Main(){
		int Q,Qn;
		int i,j,k;
		int a,b,c,d,e;
		int Qtype;
		srand(2333);
		read(n);read(Qn);
		for(base=1;base<n;base<<=1);
		for(i=1;i<=n;i++)read(arr[i]);
		
		tree.build();
		
		for(Q=1;Q<=Qn;Q++){
			read(Qtype);
			switch ( Qtype ) {
				case 1:{
					read(a);read(b);read(c);
					printf("%d\n",tree.getrank(a,b,c));
					break;
				}
				case 2:{
					read(a);read(b);read(c);
					printf("%d\n",tree.getval(a,b,c));
					break;
				} 
				case 3:{
					read(a);read(b);
					tree.change(a,b);
					arr[a]=b;
					break;
				}
				case 4:{
					read(a);read(b);read(c);
					printf("%d\n",tree.predecessor(a,b,c));					
					break;
				}
				case 5:{
					read(a);read(b);read(c);
					printf("%d\n",tree.successor(a,b,c));						
					break;
				}
			}
			
		}
		
	}

		
	
	
	
}ezoj1000;	

}

/*
优化空间复杂度从nlogn->n 
发现不可能，但可以减少 

*/

