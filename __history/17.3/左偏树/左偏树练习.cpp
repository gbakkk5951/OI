#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define data pool
#include<cstring>
using namespace std;
FILE *sc;
struct node{
	node(){
	this->f=this;
	this->l=(node *)0;
	this->r=(node *)0;
	this->dead=false;
	this->dis=0;
	this->key=0;
	}
	int key;
	node *l,*r,*f;
	int dis;
	bool dead;
}*null,*pool[1000010];
int  getmin(node *a){
	return a->key ;
}
node *merge(node *a,node *b);

void delmin(node *a){
	node *d;
	d=a;
	a->dead=true;
	printf("%d\n",a->key );
	merge(a->r,a->l);
	if(a->r&&a->r->f==a){
		a->r->f=a->r;
	}
	if(a->l&&a->l->f==a){
		a->l->f=a->l;
	}	
}


node *merge(node *a,node *b){

	



	if(a==null)
	{
		return b;
	}
	if(b==null){
		return a;
	}
	
	if(a->key>b->key ){
		swap(a,b);
	}
	node *temp=a->r;
	a->r=merge(temp,b);
	
	if(((a->l!=(node*)0)&&(a->r!=(node*)0)&&a->l->dis<a->r->dis)||a->l==NULL){
		swap(a->l,a->r);
	}

	if(a->r==null){
		a->dis=0;
	}else{
		a->dis=a->r->dis+1;
	}

	if(a->l!=(node*)0)
	{
	a->l->f=a;
	}
	if(a->r!=(node*)0)
	a->r->f=a;
	
	return a;
	
}
node *getf(node  *a){
	while(a->f!=a){
		a=a->f;
	}return a;
}
void insert(node *&a,int val){
	a=new node();
	a->key =val;
}
int n,m;
int main(){
	/*sc=fopen("CON","w");
	freopen("data.in","r",stdin);
	freopen("my.out","w",stdout);*/
memset(pool,0,sizeof(pool));
null=(node *)0;
int i,j,k;

scanf("%d",&n);
for(i=1;i<=n;i++){
	scanf("%d",&j);
	insert(pool[i],j);
}
scanf("%d",&m);
char cmd[10];

for(i=0;i<m;i++){
	scanf("%s",cmd);
	
	if(cmd[0]=='M'){
		scanf("%d%d",&j,&k);
		if(j<=n&&j>0&&k<=n&&k>0&&j!=k)
		if((!pool[j]->dead)&&(!pool[k]->dead )){
			j=(int)getf(data[j]);k=(int)getf(data[k]);
			if(j!=k)
			merge((node *)j,(node*)k);
		}
	}else{
		scanf("%d",&j);
		if(j<=n&&j>0)
		{
		
		if(!data[j]->dead){
			delmin(getf(data[j]));
		}else{
			printf("0\n");
		}
		}else{
			printf("0\n");
		}
	}
	
}
//fclose(stdout);
}
