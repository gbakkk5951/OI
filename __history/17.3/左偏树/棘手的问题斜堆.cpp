#include<cstdio>
#include<set>
#include<algorithm>
#include<cstdlib>
using namespace std;
int sum;
struct node{
	int l,r,val,lz,f;
	bool friend operator < (node a,node b){
	return a.val>b.val;}
}heap[300010];
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

	swap(heap[a].l,heap[a].r);


	return a;	
}


void up(int nd){
	if(nd)
	if(heap[nd].f!=nd){
		up(heap[nd].f);
		spread(nd);
	}
}
int getf(int nd){
	
	while(heap[nd].f!=nd)
	{
	nd=heap[nd].f;
	}return nd;
}
multiset<int>tree;
int n,q;
struct begin{
begin(){
	int fj,fk;
	int i,j,k,t1,t2;
	char temp[10];
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
					tree.erase(tree.find(heap[fj].val));
					if(heap[heap[j].f].l==j){
						heap[heap[j].f].l=0;
					}
					if(heap[heap[j].f].r==j){
						heap[heap[j].f].r=0;
					}							
					heap[heap[j].l].f=heap[j].l;
					heap[heap[j].r].f=heap[j].r;
					t1=merge(heap[j].r,heap[j].l);				
					if(j!=heap[j].f)
					t1=merge(t1,fj);
					heap[j].f=j;
					heap[j].l=0;
					heap[j].r=0;
					heap[j].val+=k;
					t1=merge(t1,j);	
					tree.insert(heap[t1].val);
					break;
				}
				case '2':{
					j=read();k=read();
					fj=getf(j);
					tree.erase(tree.find(heap[fj].val));					
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
		}
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
					printf("%d\n",sum+*(--tree.end()));
					break;
				}
			}
			
		}
		if(temp[0]=='U'){
			j=read();k=read();
			fj=getf(j);fk=getf(k);
			if(fj==fk)
			continue;
			tree.erase(tree.find(heap[fj].val));
			tree.erase(tree.find(heap[fk].val));
			j=merge(fj,fk);
			tree.insert(heap[j].val);
		}
	}

}	
}instance;int main(){}
