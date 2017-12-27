int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<stack>
#include<iostream>

struct HeapNode{
	HeapNode *f,*l,*r,*qj;
	int val,sig,npl;
}heap[600010],*root;
int add;
struct _Main{
HeapNode *getfa(HeapNode *a){
	while(a->f!=a)a=a->f;
	return a;
}
void inline pushdown(HeapNode *a){
	if(a->sig){
		if(a->l){
			a->l->sig+=a->sig;
			a->l->val+=a->sig;
		}
		if(a->r){
			a->r->sig+=a->sig;
			a->r->val+=a->sig;
		}
		a->sig=0;		
	}
}
stack<HeapNode *>stk;
void getsig(HeapNode *a){
	do{
		a=a->f;
		stk.push(a);
	}while(a!=a->f);
	while(!stk.empty()){
		pushdown(stk.top());
		stk.pop();
	}
}
HeapNode * merge(HeapNode *a,HeapNode *b){
	if(a==0)return b;
	if(b==0)return a;
	if(a->val<b->val){
		swap(a,b);
	}
	pushdown(a);
	a->r=merge(a->r,b);
	a->r->f=a;
	if(a->l == 0 || a->l->npl<a->r->npl ){
		swap(a->l,a->r);
	}a->npl=a->r?a->r->npl+1:0;
	return a;
}
HeapNode *del(HeapNode *a){
	
	HeapNode *temp=0;
	pushdown(a);
	temp=merge(a->l,a->r);
	if(temp) temp->f=temp;
	if(a->f!=a){
		if(a->f->l==a){
			a->f->l=temp;
		}else if(a->f->r==a) {
			a->f->r=temp;
		}
		if(temp)temp->f=a->f;
		temp=getfa(a->f);
	}
	a->l=a->r=0;a->f=a;a->npl=0;
	
	return temp;
}
template<typename Type>
void read(Type &a){
	char t,f=1;
	while(!isdigit(t=getchar())){
		if(t=='-') f=-1;
	}
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}a*=f;
}


char cmd[100];
int n,q;
_Main(){
	int i,j;int a,b;HeapNode *fa,*fb,*fc;
	read(n);
	for(i=1;i<=n;i++){
		heap[i].qj=&heap[i+n];
		read(heap[i].val);heap[i].qj->val=heap[i].val;
		heap[i].f=&heap[i];heap[i].qj->f =heap[i].qj;
	}
	root=0;
	for(i=1;i<=n;i++){
		root=merge(root,heap[i].qj);
	}

	read(q);
	for(i=0;i<q;i++){

		scanf("%s",cmd);

		
		switch(cmd[0]){
			case'U':{
				read(a);read(b);
				fa=getfa(&heap[a]);fb=getfa(&heap[b]);
				if(fa!=fb){
					fc=merge(fa,fb);
					if(fc==fa){
						root=del(fb->qj);
					}else{
						root=del(fa->qj);
					}
				}
				break;
			}
			case'F':{
				switch(cmd[1]){
					case'1':{
						read(a);
						getsig(&heap[a]);
						printf("%d\n",heap[a].val+add);
						break;
					}
					case'2':{
						read(a);
						fa=getfa(&heap[a]);
						printf("%d\n",fa->val+add);
						break;
					}
					case'3':{
						printf("%d\n",root->val+add);
						break;
					}
				}
				
				break;
			}
			case'A':{
				switch(cmd[1]){
					case'1':{
						read(a);read(b);
						getsig(&heap[a]);
						fb=getfa(&heap[a]);
						
						heap[a].qj->val=(heap[a].val+=b);
						fa=del(&heap[a]);
						fa=merge(fa,&heap[a]);
						fa->f=fa;
						fa->qj->val=fa->val;
						if(fa!=fb || (fa==&heap[a]) ){
							root=del(fb->qj);
							root=merge(root,fa->qj);	
						}
						break;
					}
					case'2':{
						read(a);read(b);
						fa=getfa(&heap[a]);
						fa->val +=b;fa->sig +=b;
						fa->qj->val=fa->val;
						root=del(fa->qj);
						root=merge(root,fa->qj);
						break;
					}
					case'3':{
						read(a);
						add+=a;		
						break;
					}			
				}
				break;	
			}
		}
		
	}
	
}	
	
	
	
	
	
}ezoi1011;
