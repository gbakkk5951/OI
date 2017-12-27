#include<cstdio> 
#include<algorithm>
#define mxr 131072
using namespace std;
struct begin{

int data[100010];
int un[100010];
int *tr;
struct node{
	int lc,rc;
	int sum;
node(){

	lc=0;
	rc=0;
	sum=0;
}
}pool[2300000];
int root[100010];
int cnt;
void builde(int l,int r){
	int now=cnt;
	cnt++;
	if(l==r){
		return;
	}
	pool[now].lc=cnt;
	builde(l,(l+r)>>1);
	pool[now].rc=cnt;
	builde(((l+r)>>1)+1,r);
	
}
void build(int root,int val,int last,int l,int r){
	cnt++;
int mid=(l+r)>>1;
pool[root].sum=pool[last].sum+1;
if(l!=r){
	if(val<=mid){
		pool[root].rc=pool[last].rc;
		pool[root].lc=cnt;
		build(pool[root].lc,val,pool[last].lc,l,mid);
	}else{
		pool[root].lc=pool[last].lc;		
		pool[root].rc=cnt;
		build(pool[root].rc,val,pool[last].rc,mid+1,r);

	}
	
}
}

begin(){
	root[0]=0;
	int i,j,k,p;
	scan();
	builde(1,mxr);
	for(i=1;i<=n;i++)
	{
	root[i]=cnt;

	build(root[i],lower_bound(un+1,tr,data[i])-un,root[i-1],1,mxr);
	}for(i=1;i<=m;i++){
		scanf("%d%d%d",&j,&k,&p);
		query(j,k,p);
	}
}
void scan(){
	int i=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&data[i]);
		un[i]=data[i];
	}
	sort(un+1,un+n+1);
	tr=unique(un+1,un+n+1);

}
int n,m;

void query(int l,int r,int p){
	int ans=0;
	int tl=1,ter=mxr;
	int ln,rn;
	ln=root[l-1];
	rn=root[r];
	int mid;
	p=upper_bound(un+1,tr,p)-&un[1];
	if(p>=tr-&un[1]){
		printf("%d\n",pool[rn].sum-pool[ln].sum);
		return;
	}
	if(p==0){
		printf("0\n");
		return;
	}else{
		while(ter!=tl){
			mid=(ter+tl)>>1;
			if(p>mid){
				ans+=pool[pool[rn].lc].sum-pool[pool[ln].lc].sum;
				tl=mid+1;
				ln=pool[ln].rc;
				rn=pool[rn].rc;
			}
			if(p==mid){				
				ans+=pool[pool[rn].lc].sum-pool[pool[ln].lc].sum;
				printf("%d\n",ans);
				return;
			}
			if(p<mid){
				ter=mid;
				ln=pool[ln].lc;
				rn=pool[rn].lc;
				
			}
			
			
		}
		ans+=pool[rn].sum-pool[ln].sum;
		printf("%d\n",ans);
		
	}
	
	
}

}instance;int main(){}
