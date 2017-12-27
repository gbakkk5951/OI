#include<cstdio>
#include<algorithm>
#define data pool
#include<cstring>
using namespace std;
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
	a->r=merge(a->r,b);
	
	if((a->l!=(node*)0)&&(a->r!=(node*)0)&&a->l->dis<a->r->dis ){
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
insert(node *&a,int val){
	node *temp=(node *)0;
	temp=new node();
	temp->key =val;
	if(a!=(node *)0)
	a=merge(a,temp);
	else{
		a=temp;
	}
	if((a->r)!=null){
		a->r->f=a;
	}
	if((a->l)!=null){
		a->l->f=a;
	}	
}
int n,m;
int main(){
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
		if((!pool[j]->dead)&&(!pool[k]->dead )){
			merge(getf(data[j]),getf(data[k]));
		}
	}else{
		scanf("%d",&j);
		
		if(!data[j]->dead){
			delmin(getf(data[j]));
		}else{
			printf("0\n");
		}
	}
	
}

}
