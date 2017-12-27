#include<cstdio>
int n;
struct node{
	int xl,xg,yl,yg,val;
	node *kid[4];
}pool[2000000];
node *null;
node *root;
int tot;
struct _Main{
public:	
void resize(int s){
	n=s;
	root->xg =n; 
	root->yg =n;	
}
_Main(){
	null=0;
	root=newnode();
	tot=2;
	root->xl =1;
	root->xg =n; 
	root->yl =1;
	root->yg =n;
}
void insert(int x,int y,int val){
	node *nd=root;
	while((nd->xg^nd->xl)||(nd->yg^nd->yl)){
//		printf("%d ->",nd-pool);
		nd->val=max(val,nd->val);
		if(x<=xmid(nd)){//2¡¢3ÏóÏÞ 
			if(y<=ymid(nd)){
				printf("[3]");
				if(nd->kid[2]!=null){
					nd=nd->kid[2];
				}else{
					node *t=nd->kid[2]=newnode();
					t->xl=nd->xl;
					t->yl=nd->yl;
					t->xg=xmid(nd);
					t->yg=ymid(nd);
					nd=t;
				}
			}else{
				
				if(nd->kid[1]!=null){
					nd=nd->kid[1];
				}else{
					node *t=nd->kid[1]=newnode();
					t->xl=nd->xl;
					t->yl=ymid(nd)+1;
					t->xg=xmid(nd);
					t->yg=nd->yg;
					printf("[2](%d~%d)\n",t->yl ,t->yg );	
					nd=t;
				
				}				
			}
		}else{
			if(y<=ymid(nd)){
//				printf("[4]");
				if(nd->kid[3]!=null){
					nd=nd->kid[3];
				}else{
					node *t=nd->kid[3]=newnode();
					t->xl=xmid(nd)+1;
					t->yl=nd->yl;
					t->xg=nd->xg;
					t->yg=ymid(nd);
					nd=t;
				}
			}else{
//				printf("[1]");
				if(nd->kid[0]!=null){
					nd=nd->kid[0];
				}else{
					node *t=nd->kid[0]=newnode();
					t->xl=xmid(nd)+1;
					t->yg=nd->yg;
					t->xg=nd->yg;
					t->yl=ymid(nd)+1;
					nd=t;
				}				
			}
		}
	}
	nd->val=max(val,nd->val);
	
}

int query(int x1,int x2,int y1,int y2){
	xl=x1;
	xg=x2;
	yl=y1;
	yg=y2;
	return squery(root);
}
private:
inline node * newnode(){
	return &pool[tot++];
}

inline int max(int a,int b){
	return a > b ? a: b;
}
int xl, xg, yl, yg;
int squery(node *nd){

	if(nd==null||nd->xl>xg||nd->xg<xl||nd->yl>yg||nd->yg<yl){
		return 0;
	}
	if(nd->xl>=xl&&nd->xg<=xg&&nd->yl>=yl&&nd->yg <=yg){
		return nd->val;
	}
	return max(max(squery(nd->kid[0]),squery(nd->kid[1])),max(squery(nd->kid[2]),squery(nd->kid[3])));
}


inline int xmid(node *a){
	return (a->xl+a->xg)>>1;
}
inline int ymid(node *a){
	return (a->yl+a->yg)>>1;
}























	
}tree;


int main(){
	tree.resize(8);
	 
	tree.insert(1,8,150);
	tree.insert(1,6,1000);
	printf("%d",tree.query(1,8,1,6) );
}
