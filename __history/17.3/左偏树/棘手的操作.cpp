#include<cstdio>
#include<set>
#include<algorithm>
#include<cstdlib>
using namespace std;
int sum;
int tot;

struct node{
	int size,val;
	node *l,*r;
	int cnt;
};
node *root;
node *null;
struct sbt{
private:
void left_rotate(node *&t){
	node *r=t->r;
	t->r=r->l;
	r->l=t;
	r->size=t->size;
	t->size=t->l->size+t->r->size+1;
	t=r;
}
void right_rotate(node *&t){
	node *l=t->l;
	t->l=l->r;
	l->r=t;
	l->size=t->size;
	t->size=t->l->size+t->r->size+1;
	t=l;
}
void  maintain(node *&t,bool right){
if(!right){
	if(t->l->l->size>t->r->size){
		
		right_rotate(t);
	}else if(t->l->r->size>t->r->size){
		left_rotate(t->l);
		right_rotate(t);
	}else return;
}else{
	if(t->r->r->size>t->l->size){
		left_rotate(t);
	}else if(t->r->l->size>t->l->size){
		right_rotate(t->r);
		left_rotate(t);
	}else return;
}
maintain(t->l,false);
maintain(t->r,true);
maintain(t,true);
maintain(t,false);
}
public:
sbt(){
	null=new node();
	null->l=null;
	null->r=null;
	null->val=0;
	root=null;
}
int del(int val,node *&t=root){
	int r;
	t->size--;
	if(val==t->val||val<t->val&&t->l==null||val>t->val&&t->r==null){
		r=t->val;
		if(t->l==null){
		if(t->r==null){
			delete t;
			t=null;
		}else t=t->r;
		}else if(t->r==null){
			t=t->l;
		}else{
			t->val=del(val+1,t->l);
		}
		return r;
	}
	else{
		if(val<t->val){
			return del(val,t->l);
		}else{
			return del(val,t->r);
		}
	}
}
void insert(int val,node *&t=root){
	if(t==null){
		t=new node();
		t->l=null;
		t->r=null;
		t->val=val;
		t->size=1;
	}
	else{
		t->size++;
		if(val<t->val){
			insert(val,t->l);
		}else{
			insert(val,t->r);
		}
		maintain(t,val>=t->val);
	}
}
int select(int k,node *t=root){
	int r=t->l->size+1;
	if(r==k){
		return t->val;
	}if(t->l->size>=k){
		return select(k,t->l);
	}else{
		return select(k-r,t->r);
	}
}

}tree;


struct _node{
	int l,r,val,lz,f,dis;

}heap[300005];
int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void spread(int nd){
	if(!nd)return;
	heap[heap[nd].l].val+=heap[nd].lz;
	heap[heap[nd].l].lz+=heap[nd].lz;
	heap[heap[nd].r].val+=heap[nd].lz;
	heap[heap[nd].r].lz+=heap[nd].lz;	
	heap[nd].lz=0;
}
int merge(int a,int b){

	if(!a)return b;
	if(!b)return a;
	
	spread(a);spread(b);
	if(heap[a].val<heap[b].val){
		swap(a,b);
	}
	heap[a].r=merge(heap[a].r,b);
	heap[heap[a].r].f=a;
	if(heap[heap[a].l].dis<heap[heap[a].r].dis){
		swap(heap[a].l,heap[a].r);
	}
	if(heap[a].l&&heap[a].r)
	heap[a].dis=heap[heap[a].r].dis+1;
	else{
		heap[a].dis=0;
	}
	return a;	
}


void up(int nd){

if(heap[nd].f!=nd){
	up(heap[nd].f);
}
spread(nd);
}
int getf(int nd){
	
	while(heap[nd].f!=nd)
	{
	nd=heap[nd].f;
	}return nd;
}
int n,q;
struct begin{
begin(){
	int fj,fk;
	int i,j,k,t1,t2;
	char temp[10];
	heap[0].dis=-1;
	n=read();
	for(i=1;i<=n;i++){
		heap[i].val=read();
		heap[i].f=i;
		tree.insert(heap[i].val);
	}
	q=read();
	for(i=0;i<q;i++){
		scanf("%s",temp);
		if(temp[0]=='A'){
			switch(temp[1]){
				case '1':{
					j=read();k=read();
					up(j);
					spread(j);
					fj=getf(j);
					tree.del(heap[fj].val);
					heap[heap[j].f].dis=0;										
					t1=merge(heap[j].r,heap[j].l);				
					if(heap[heap[j].f].l==j){
						heap[heap[j].f].l=t1;
						heap[t1].f=heap[j].f;
					}
					else
					if(heap[heap[j].f].r==j){
						heap[heap[j].f].r=t1;
						heap[t1].f=heap[j].f;
					}else heap[t1].f=t1;					
					heap[j].f=j;
					heap[j].l=0;
					heap[j].r=0;
					heap[j].val+=k;
					if(fj!=j)
					t1=merge(fj,j);	
					else t1=merge(t1,j);
					tree.insert(heap[t1].val);
					break;
				}
				case '2':{
					j=read();k=read();
					fj=getf(j);
					tree.del(heap[fj].val);					
					heap[fj].val+=k;
					heap[fj].lz+=k;					
					spread(fj);					
					tree.insert(heap[fj].val);
					break;
				}
				case '3':{
					j=read();
					sum+=j;
					break;
				}
			}
		}else
		if(temp[0]=='F'){
			switch(temp[1]){
				case '1':{
					j=read();
					up(j);
					printf("%d\n",sum+heap[j].val);
					break;
				}
				case '2':{
					j=read();
					printf("%d\n",sum+heap[getf(j)].val);
					break;
				}
				case '3':{
					printf("%d\n",sum+tree.select(root->size));
					break;
				}
			}
			
		}else
	 	if(temp[0]=='U'){
			j=read();k=read();
			fj=getf(j);fk=getf(k);
			if(fj==fk)
			continue;
			if(heap[fj].val<heap[fk].val)
			tree.del(heap[fj].val);
			else
			tree.del(heap[fk].val);
			j=merge(fj,fk);
		}
	}

}	
}instance;int main(){}
