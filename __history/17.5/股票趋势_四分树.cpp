#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool read();
int la,lb;
int maxn=0;
void search();
char a[802],b[802];
int dis[256];
int re[6];

struct node{
	int xl,xg,yl,yg,val;
	node *kid[4];
}pool[1000000];
node *null;
node *root;
int tot;
struct _Main{
public:	
void resize(int s){
	root->xl =1;
	root->yl =1;
	root->xg =s; 
	root->yg =s;	
}
_Main(){
	null=0;
	root=newnode();
	root->xl =1;
	root->yl =1;

}
void insert(int x,int y,int val){
	node *nd=root;
	while((nd->xg^nd->xl)||(nd->yg^nd->yl)){
//		printf("insert %d~%d,%d~%d\n",nd->xl,nd->xg  ,nd->yl,nd->yg);
		nd->val=max(val,nd->val);
		if(x<=xmid(nd)){//2¡¢3ÏóÏÞ 
			if(y<=ymid(nd)){
//				printf("[3]");
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
//				printf("[2]");
				if(nd->kid[1]!=null){
					nd=nd->kid[1];
				}else{
					node *t=nd->kid[1]=newnode();
					t->xl=nd->xl;
					t->yg=nd->yg;
					t->xg=xmid(nd);
					t->yl=ymid(nd)+1;
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
					t->xg=nd->xg;
					t->yl=ymid(nd)+1;
					nd=t;
				}
			}
		}
	}
	nd->val=max(val,nd->val);
//	printf("\n\n\n");
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

int main()
{
	
int n;
scanf("%s",a);
scanf("%s",b);
scanf("%d",&n);
int i=0,j=0;

for(i=0;i<n;i++)
{
for(j=0;j<256;j++)
dis[j]=802;

while(read());

search();
re[i]=maxn;
maxn=0;
int ubt;
for(ubt=0;ubt<tot;ubt++){
	pool[ubt].val=0;
}

}
for(i=0;i<n;i++)
{
printf("%d ",re[i]);
}

 } 
 
 bool read()
{char ct;
ct=getchar();

if(ct=='$')
return false;
else if(ct=='\n'||ct=='\r'||ct==' ')
return true;
else if(ct==EOF)
return false;

scanf("%d",&dis[(int)ct]);
return true;
}

void search()
{
int m,n;
la=strlen(a);
lb=strlen(b);
tree.resize(max(la,lb)); 
int i,j,l;

for(i=1;i<=la;i++)
{
for(j=1;j<=lb;j++)
{
if(a[i-1]==b[j-1])
{
int xl=1>i-dis[a[i-1]]-1?1:i-dis[a[i-1]]-1;
int xr=i-1;
int yl=1>j-dis[b[j-1]]-1?1:j-dis[b[j-1]]-1;
int yr=j-1;


int zmax=tree.query(xl,xr,yl,yr)+1;
if(maxn<zmax)
maxn=zmax;
tree.insert(i,j,zmax);

}
}

}


}
