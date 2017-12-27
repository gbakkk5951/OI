#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;
struct _Main{
int n,m,p,c;	
int max_time;
struct seg_node{
	int  l,r;int times;
	int lc,rc;
	long long sum;
	long long list[70];
}tree[410000];
int a[100010];	
long long phi;
long long ph[200];
int tot;
long long getphi(long long t){
	int i,g;
	g=sqrt(t);
	phi=t;
	for(i=2;i<=g;i++){
		
		if(!(t%i)){
			phi=phi/i*(i-1);
			t/=i;
			while(!(t%i)){
				t/=i;
			}
		}
	}
	if(t^1)
		phi=phi/t*(t-1);
	return phi;
}
int change(int l,int r,int nd=1){
	
	if(l>tree[nd].r||r<tree[nd].l||tree[nd].times<=0 ){
//printf("%d->%d=%d ",tree[nd].l,tree[nd].r,tree[nd].sum);		
		return tree[nd].sum;
	}
	if(tree[nd].r==tree[nd].l){
		tree[nd].times--;
		int i;int t=tree[nd].list[0];
		
		for(i=0;i<tree[nd].times;i++){
	
	//	/*	if(tree[nd].list[i]>=ph[i+1]/*||tree[nd].times<max_time-1*/){
	//		//	printf("fz1fz");
	//			tree[nd].list[i]=po(c,tree[nd].list[i]%ph[i+1]+ph[i+1],ph[i]);
	//		}
	//	*/		
		/*	else*/ tree[nd].list[i]=po(c,tree[nd].list[i+1],ph[i]);
			
//			if(tree[nd].list[i]==1)break;
		}
		
		tree[nd].sum=tree[nd].list[0];
		if(tree[nd].list[0]==t)tree[nd].times=-1000;
//printf("%d->%d=%d ",tree[nd].l,tree[nd].r,tree[nd].sum);
		return tree[nd].list[0];
	}
	tree[nd].sum =(change(l,r,tree[nd].lc)+change(l,r,tree[nd].rc))%p;
	tree[nd].times =max(tree[tree[nd].lc].times ,tree[tree[nd].rc].times );
//printf("%d->%d=%d ",tree[nd].l,tree[nd].r,tree[nd].sum);	
	return tree[nd].sum;
	
	
}
long long po(int base,int times,int mod){
	if(times){
		long long ans=po(base,times>>1,mod);
		ans=(ans*ans)%mod;
		if(times&1){
			return ans*base%mod;
		}
		return ans;
	}return 1;
}

int buildtree(int l,int r){
	int index=tot++;
	int mid=(l+r)>>1;
	tree[index].l=l;
	tree[index].r=r;
	tree[index].times = max_time;
	if(l^r){
		tree[index].lc=buildtree(l,mid);
		tree[index].rc=buildtree(mid+1,r);
		tree[index].sum=(tree[tree[index].lc].sum+tree[tree[index].rc].sum)%p;
	}else{
		tree[index].sum=a[l];
		int i;
		
		for(i=0;i<max_time;i++){
			if(ph[i])
			tree[index].list[i]=a[l]%ph[i];
		}
		
	}
	return index;
}

long long query(int l,int r,int nd=1){
	if( l > tree[nd].r || r < tree[nd].l ){
		return 0;
	}
	if(tree[nd].l>=l&&tree[nd].r<=r){
//printf("%d->%d=%d ",tree[nd].l,tree[nd].r,tree[nd].sum);			
		return tree[nd].sum;
	}else{
		return (query(l,r,tree[nd].lc)+query(l,r,tree[nd].rc))%p;
	}
	
}


_Main(){
	int i,j;tot=1;
	int l,r;
/*while(1){printf(">> ");
i=read();j=read();r=read();
printf("%lld",po(l,j,r));	
}*/	
//while(1)printf("%lld\nin:>> ",getphi((long long)read()));
	n=read();m=read();p=read();c=read();
	
	i=1;
	ph[0]=p;
	while((ph[i]=getphi(ph[i-1]))>1){
		i++;
	}/*{
	printf("ph[%d]=%d\n",i-1,ph[i-1]);
}*/
	max_time=i;
	for(i=1;i<=n;i++){
		a[i]=read();
	}buildtree(1,n);
	for(i=0;i<m;i++){
		j=read();l=read();r=read();
		if(j){
			printf("%lld\n",query(l,r));
		}else{
			change(l,r);
		}
		
	}
}	
int read(){
	char t;int ans=0;
	while(!isdigit(t=getchar()));		
	do{
		ans*=10;
		ans+=t-'0';
	}while(isdigit(t=getchar()));
	return ans;
}	

}instance;int main(){}
