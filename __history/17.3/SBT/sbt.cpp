#include<cstdio>
using namespace std;
struct node{
	int size,val;
	node *l,*r;
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
int successor(int val,node *t=root){	
	if(t==null){
		return val;
	}
	if(t->val<=val){
		return successor(val,t->r);
	}else{
		int r=successor(val,t->l);
		if(r==val){
			return t->val;
		}else{
			return r;
		}
	}
}
int predecessor(int val,node *t=root){
	if(t==null){
		return val;
	}
	if(t->val>=val){
		return predecessor(val,t->l);
	}else{
		int r=predecessor(val,t->r);
		if(r==val){
			return t->val;
		}else{
			return r;
		}
	}
}
bool find(int val){
	node *a=root;
	while(a!=null){
		if(a->val==val){
			return true;
		}if(a->val<val){
			a=a->r;
		}else{
			a=a->l;
		}
	}
	return false;
}
int rank(int val,node *&t=root){
	if(t==null)
	return 1;
	if(t->val<val){
		return t->l->size+rank(val,t->r)+1;
	}
	return rank(val,t->l);
}
}tree;
int read(){
	char in;
	int ans=0;
	int f=1;
	while((in=getchar())>'9'||in<'0'){
		if(in=='-'){
			f=-1;
			break;
		}
	}
	if(in!='-'){
		ans+=in-'0';
	}
	while((in=getchar())<='9'&&in>='0'){
		ans*=10;
		ans+=in-'0';
	}
	return ans*f;
}
int main(){
int n,m,i,j;



n=read();
for(m=0;m<n;m++){
	i=read();j=read();
	switch(i){
		case 1:{
			tree.insert(j);
			break;
		}
		case 2:{
			tree.del(j);
			break;
		}
		case 3:{
			printf("%d\n",tree.rank(j));
			break;
		}
		case 4:{
			printf("%d\n",tree.select(j));
			break;
		}
		case 5:{
			printf("%d\n",tree.predecessor(j) );
			break;
		}
		case 6:{
			printf("%d\n",tree.successor(j));
			break;
		}
	}
}

}
