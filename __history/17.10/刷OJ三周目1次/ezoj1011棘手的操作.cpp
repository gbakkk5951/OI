using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<stack>
int n;
struct HeapNode{
	HeapNode *f,*l,*r,*qj;
	int val;int sig;int npl;
	void add (int v){
		val+=v;
		qj->val=val;
	}
}heap[600010],*root;
stack<HeapNode *>stk;

struct _Main{
void inline pushdown(HeapNode *a){
	if(a->sig){
		if(a->l){
			a->l->sig+=a->sig;
			a->l->add(a->sig);
		}
		if(a->r){
			a->r->sig+=a->sig;
			a->r->add(a->sig);
		}
		a->sig=0;
	}
}
void getsig(HeapNode *a){
	stk.push(a);
	do{
		a=a->f;
		stk.push(a);
	}while(a->f!=a);
	while(stk.size()){
		pushdown(stk.top());
		stk.pop();
	}
}
HeapNode *getfa(HeapNode *a){
	if(a->f!=a){
		a->npl = a->r?a->r->npl +1:0;
		return getfa(a->f);	
	}
	a->npl = a->r?a->r->npl +1:0;
	return a;
}

HeapNode * merge(HeapNode *a,HeapNode *b){
	if(a==0)return b;
	if(b==0)return a;
	if(a->val<b->val)swap(a,b);
	pushdown(a);
	a->r=merge(a->r,b);
	a->r->f=a;
	if(a->l==0 || a->l->npl<a->r->npl)swap(a->l,a->r);
	a->npl = a->r?a->r->npl +1:0;
	return a;
}
HeapNode *del(HeapNode *a){
	getsig(a);
	HeapNode *son=merge(a->l,a->r);
	if(a->f!=a){
		if(a->f->l==a){
			a->f->l=son;
		}else{
			a->f->r=son;
		}
		if(son)son->f=a->f;
		son=a->f;
	}else{
		if(son)son->f=son;
	}
	a->f=a;a->l=a->r=0;a->npl =0;
	return son?getfa(son):0;
}	
	
	
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}a*=f;
	}
int q;	
int add;
char cmd[10];
_Main(){
	int i,j,k;int a,b,c;
	HeapNode *fa,*fb;HeapNode *x,*y,*z;
	read(n);
	for(i=1;i<=n;i++){
		heap[i].qj=&heap[i+n];
		read(a);heap[i].add(a);
		heap[i].f=&heap[i];heap[i+n].f=&heap[i+n];
		root=merge(root,&heap[i+n]);
	}
	read(q);
	for(i=0;i<q;i++){
		scanf("%s",cmd);
		switch(cmd[0]){
			case 'U':{
				read(a);read(b);
				fa=getfa(&heap[a]);fb=getfa(&heap[b]);
				if(fa!=fb){
					x=merge(fa,fb);
					if(x==fa){
						root=del(fb->qj);
					}else{
						root=del(fa->qj);
					}
				}
				break;
			}
			case 'A':{
				switch(cmd[1]){
					case '1':{
						read(a);read(b);x=&heap[a];
						z=getfa(x);
						x->add(b);
						y=del(x);
						y=merge(x,y);
						if(y!=z || y==x){
							root=del(z->qj);
							root=merge(y->qj,root);
						}
						break;
					}
					case '2':{
						read(a);read(b);x=getfa(&heap[a]);
						x->add(b);x->sig +=b;
						root=del(x->qj);
						root=merge(root,x->qj);
						break;
					}
					case '3':{
						read(a);
						add+=a;
						break;
					}
				}
				break;
			}
			case 'F':{
				switch(cmd[1]){
					case '1':{
						read(a);x=&heap[a];
						getsig(x);
						printf("%d\n",x->val+add);
						break;
					}
					case '2':{
						read(a);x=getfa(&heap[a]);
						printf("%d\n",x->val+add);
						break;
					}					
					case '3':{
						printf("%d\n",root->val+add);
						break;
					}					
					
				}				
				
				break;
			}
			
			
			
			
			
		}
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
}	
	
	
}ezoj1011;
