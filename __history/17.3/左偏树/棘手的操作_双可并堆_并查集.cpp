#include<cstdio>
#include<set>
#include<algorithm>
#include<cstdlib>
using namespace std;
int sum;
int tot;
int gap=300005; 


struct _node{
	int l,r,val,lz,f,dis,fa;

}heap[600015];



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
	heap[heap[a].r].fa=a;
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

struct cl{
int root;
void insert(int pos){
	int val=heap[pos].val;
	pos+=gap;

	if(pos==root||heap[pos].f!=pos||heap[pos].l!=0||heap[pos].r!=0){
		del(pos-gap);
	}
	if(root==0){
		root=pos;
		heap[root].val=val;
	}else{
		heap[pos].val=val;
		root=merge(root,pos);
		heap[root].f=root;
	}
	
}

int mx(){
	return heap[root].val;
}
void del(int pos){
	pos+=gap;

	int f=root;
	int i,j,k;
	heap[heap[pos].l].f=heap[pos].l;
	heap[heap[pos].r].f=heap[pos].r;
	j=merge(heap[pos].l,heap[pos].r);
	if(f!=pos){
		if(heap[heap[pos].f].l==pos){
			heap[heap[pos].f].l =j;
			heap[j].f=heap[pos].f;
		}else if(heap[heap[pos].f].r==pos){
			heap[heap[pos].f].r=j;
			heap[j].f=heap[pos].f;
		}
		heap[pos].f=pos;
		heap[pos].l=0;
		heap[pos].r=0;
		heap[pos].dis=0;
	}else{
		heap[pos].f=pos;
		root=j;
		heap[pos].l=0;
		heap[pos].r=0;
		heap[pos].dis=0;
	}
	
	
}

}tree;

void up(int nd){

if(heap[nd].f!=nd){
	up(heap[nd].f);
}
spread(nd);
}
int getf(int nd){
	
	if(heap[nd].fa)
	{
	heap[nd].fa=getf(heap[nd].fa);
	return heap[nd].fa;
	}return nd;
}
int n,q;
struct begin{
begin(){
	int tp;
	int fj,fk;
	int i,j,k,t1,t2;
	char temp[10];
	heap[0].dis=-1;
	n=read();
	for(i=1;i<=n;i++){
		heap[i].val=read();
		heap[i].f=i;
		heap[i].fa=0;
		tree.insert(i);
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
					tree.del(fj);
					heap[heap[j].f].dis=0;										
					heap[heap[j].l].f=0;
					heap[heap[j].l].fa=0;
					heap[heap[j].r].f=0;
					heap[heap[j].r].fa=0;
					t1=merge(heap[j].r,heap[j].l);		
						
					if(heap[heap[j].f].l==j){
						heap[heap[j].f].l=t1;
						heap[t1].f=heap[j].f;
						heap[t1].fa=heap[j].f;
					}
					else
					if(heap[heap[j].f].r==j){
						heap[heap[j].f].r=t1;
						heap[t1].f=heap[j].f;
						heap[t1].fa=heap[j].f;
					}else {heap[t1].f=t1;					
							heap[t1].fa=0;	
					}
					heap[j].fa=0;
					heap[j].f=j;
					heap[j].l=0;
					heap[j].r=0;
					heap[j].val+=k;
					if(fj!=j)
					t1=merge(fj,j);	
					else t1=merge(t1,j);
					heap[t1].fa=0;
					tree.insert(t1);
					break;
				}
				case '2':{
					j=read();k=read();
					fj=getf(j);
					tree.del(fj);
										
					heap[fj].val+=k;
					heap[fj].lz+=k;					
					spread(fj);	
								
					
					tree.insert(fj);
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
					printf("%d\n",sum+tree.mx());
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
			tree.del(fj);
			else
			tree.del(fk);
			heap[merge(fj,fk)].fa=0;
		}
	}

}	
}instance;int main(){}
