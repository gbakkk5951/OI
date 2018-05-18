#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node;

node *null=(node *)malloc(16);
int read(){
	int ret=0,f=1;
	char t;
	while((t=getchar())<'0'||t>'9'){if(t=='-'){f=-1;}}
	ret=t-'0';
	while((t=getchar())>='0'&&t<='9'){ret*=10;ret+=t-'0';}
	return ret*f;
}
struct node{
node(){
	f=this;l=null;r=null;
}
node *f,*l,*r;
int val;
 
}*root=(node*)null;



void left_rotate(node *a,node *&rt=root){
	node *b;
	b=a->r;
	a->r=b->l;
	b->l->f=a;
	if(a->f==a){
		a->f=b;
		b->f=b;
		rt=b;
	}else{
	if(a==a->f->l){
		a->f->l=b;
	}else{
		a->f->r=b;
	}
	b->f=a->f;
	a->f=b;
	}
	b->l=a;
}
void right_rotate(node *a,node *&rt=root){
	node *b;
	b=a->l;
	a->l=b->r;
	b->r->f=a;
	if(a->f==a){
		a->f=b;
		b->f=b;
		rt=b;
	}else{
	if(a==a->f->l){
		a->f->l=b;
	}else{
		a->f->r=b;
	}
	b->f=a->f;
	a->f=b;
	}
	b->r=a;
}
void splay(node *x,node *&rt=root){
	if(x->f==x){
	rt=x;
	return;	
	}
	//case 1
	if(x->f==rt){
		if(x==x->f->l){
			right_rotate(x->f);
		}else{
			left_rotate(x->f);
		}
		return;
	}
	//case 2-1
	if(x->f->l==x&&x->f->f->l==x->f){
		right_rotate(x->f);//***** 
		right_rotate(x->f);	
		splay(x,rt);	
		return;
	}
	//case 2-2	
	if(x->f->r==x&&x->f->f->r==x->f){
		left_rotate(x->f);//***** 
		left_rotate(x->f);
		splay(x,rt);	
		return;					
	}
	//case 3-1
	if(x->f->r==x&&x->f->f->l==x->f){
		left_rotate(x->f);
		right_rotate(x->f);
		splay(x,rt);
		return;
	}
	//case 3-2
	if(x->f->l==x&&x->f->f->r==x->f){
		right_rotate(x->f);
		left_rotate(x->f);
		splay(x,rt);
		return;
	}
}
void insert(int val,node *&rt=root){
	node *now=rt;
	if(root==null){
		root=new node();
		root->val=val;
		return;
	}
	while(1){
		if(val<now->val){
			if(now->l==null){
				now->l=new node();
				now->l->f=now;
				now->l->val=val;
				splay(now->l,rt);
				return;
			}
			now=now->l;
		}else{
			if(now->r==null){
				now->r=new node();
				now->r->f=now;
				now->r->val=val;
				splay(now->r,rt);
				return;
			}
			now=now->r;			
		}
	}
}
bool find(int val,node *&rt=root){
	node *now=rt;
	while(now!=null){
		if(val<now->val){
			now=now->l;
		}else
		if(val>now->val){
			now=now->r;
		}
		else {splay(now,rt);
		return true;	
		}
	}
	return false;
}
int del(int val,node *&rt=root){
node *now=rt;
int r;
	if(now==null){
		return val;
	}
	if(now->val==val||now->val>val&&now->l==null||now->val<val&&now->r==null){
		if(now->l==null){
				r=now->val;
				if(now->f!=now){
					if(now==now->f->l){
						now->f->l=now->r;
						now->r->f=now->f;
					}else{
						now->f->r=now->r;
						now->r->f=now->f;
					}
					splay(now->f);					
				}else{
					now->r->f=now->r;
					rt=now->r;
				}
				delete now;
				return r;	
		}else if(now->r==null){
				r=now->val;
				if(now->f!=now){
					if(now->f->l==now){
						now->f->l=now->l;
						now->l->f=now->f;
					}else{
						now->f->r=now->l;
						now->l->f=now->f;
					}
					splay(now->f);
				}else{
					now->l->f=now->l;
					rt=now->l;
				}
				delete now;
				return r;
		}else{
			r=now->val;
			now->val=del(val+1,now->l);
			splay(now);
			return r;
		}
	}else{
		if(now->val<val){
			return del(val,now->r);
		}else{
			return del(val,now->l);
		}
	}
}
int main(){
	int m,n,i,t;
	n=read();m=read();
	for(i=0;i<n;i++){
		insert(read());
		/*scanf("%d",&t);
		switch(t){
			case 1:{
				insert(read());
				break;
			}
			case 2:{
				if(find(read())){
					putchar('1');
					putchar(' ');
				}else{
					putchar('0');
					putchar(' ');
				}
				break;
			}
			case 3:{
				del(read());
				break;
			}
			
		}*/
		
		
	}
	for(i=0;i<m;i++){
		if(find(read())){
			putchar('1');
		}else{
			putchar('0');
		}
		putchar(' ');
	}
	
	
	
	
	
	
	
	
	/*for(i=0;i<n;i++){
		insert(read());
	}

	for(i=0;i<m;i++){

		if(find(read())){
			putchar('1');
			putchar(' ');
		}else{
			putchar('0');
			putchar(' ');
		}
	}
	*/
	
}


	/*		if(now->r==null){
				r=now->val;
				if(now->f!=now){
					if(now->f->l==now){
						now->f->l=(node*)null;
					}else{
						now->f->r=(node*)null;
					}
					splay(now->f);					
				}else{
					rt=(node *)null;
				}
				delete now;
				return r;	
			}else{*/
