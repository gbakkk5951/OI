#include<cstdio>
struct problem{
int data[262150];
char lazy[262150];
int ql[100010],qr[100010];
int up[100010];
int org[100010];
int m,n;
int q;
void test(){
	int a,b,c,d;
	while(1){
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{printf("%d\n",query(b,c)) ;
		}else{
			scanf("%d",&d);
			assign(b,c,d);
		}
	}
	
}


problem(){
// 	test();
	int i=0; 
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&org[i]);
	}

	for(i=1;i<=m;i++){
		scanf("%d%d%d",&up[i],&ql[i],&qr[i]);
		
	}
		scanf("%d",&q);
	binary(1,n);
	
}

void binary(int l,int r){
	if(l==r)
	{
		printf("%d",l);
		return ;
	}
	int mid=(l+r)>>1;	
	int i,j,k;
	for(i=1;i<=n;i++){
		if(org[i]>mid){
			assign(i,i,1);
		}else{
			assign(i,i,0);
		}
	
	}
	
//	for(i=1;i<=n;i++)
//	{
//	printf("[%d]=%d; ",i,query(i,i));
//	}
	for(i=1;i<=m;i++){
		sort(ql[i],qr[i],up[i]);
//	for(j=1;j<=n;j++)
//	{
//	printf("[%d]=%d  ",j,query(j,j));
//	}
	}
	

//	printf("\n");
	if(query(q,q)==1){
		binary(mid+1,r);
	}else{
		binary(l,mid);
	}
	
}


void sort(int l,int r,int up){
	int nu=query(l,r);
//	printf("l=%d r=%d nu=%d;",l,r,nu);
	if(!up){
	assign(r-nu+1,r,1);
//	printf("(%d,%d)=%d;",r-nu+1,r,query(r-nu+1,r));
	assign(l,r-nu,0);
//	printf("(%d,%d)=%d;",l,l,query(l,l));
	}else{
		assign(l,l+nu-1,1);
		assign(l+nu,r,0);
	}
}

int query(int l,int r,int root=1,int tl=1,int tr=131072){
	if(l>r)
	return 0;
	int mid=(tl+tr)>>1;
	if(l<=tl&&r>=tr){
	//	printf("q[%d]=%d;",root,data[root]);
		return data[root];
	}else{
		if(tl>r||tr<l){
			return 0;
		}
		
		if(lazy[root]==1){
//			printf("==1");
		lazy[root]=0;
		data[root<<1]=1*(mid-tl+1);
		data[root<<1|1]=1*(tr-mid);
		lazy[root<<1]=1;
		lazy[root<<1|1]=1;
		
//		assign(tl,mid,1,root<<1,tl,mid);
//		assign(mid+1,tr,1,root<<1|1,mid+1,tr);
		
		}else{
		if(lazy[root]==-1){
//		assign(tl,mid,0,root<<1,tl,mid);
//		assign(mid+1,tr,0,root<<1|1,mid+1,tr);
		data[root<<1]=0;
		data[root<<1|1]=0;
		lazy[root<<1]=-1;
		lazy[root<<1|1]=-1;		
		lazy[root]=0;			
		}
			
		}
		return (query(l,r,root<<1,tl,mid)+query(l,r,root<<1|1,mid+1,tr));
		
	}
	
	
}

void assign(int l,int r,bool nu,int root=1,int tl=1,int tr=131072){
	if(l>r)
	return ;
	int mid=(tl+tr)>>1;
	if(l<=tl&&r>=tr){
		if(nu==1)
		{
		
		lazy[root]=nu;
//		printf("nui");
		}
		else
		{
//		printf("---11");
		lazy[root]=-1;
		}
		data[root]=(tr-tl+1)*nu;
//		printf("root[%d]=%d ->lz=%d;",root,data[root],lazy[root]);
	}
	else{
		if(tr<l||tl>r){
			return;
		}
	
		if(lazy[root]==1)
		{
			
//				printf(" lz%d=1?",root);
//		assign(l,r,1,root<<1,,mid);
//		assign(l,r,1,root<<1|1,mid+1,tr);
		lazy[root<<1]=1;
		data[root<<1]=(mid-tl+1)*nu; 
		lazy[root<<1|1]=1;
		data[root<<1|1]=(mid-tl+1)*nu; 		
			
		}else{
			if(lazy[root]==-1)
			{
//			printf("lz[%d]=%d",root,lazy[root]);
//		assign(l,r,0,root<<1,tl,mid);
//		assign(l,r,0,root<<1|1,mid+1,tr);
		lazy[root<<1]=-1;
		data[root<<1]=0; 
		lazy[root<<1|1]=-1;
		data[root<<1|1]=0; 	
			}
		}
		

		lazy[root]=0;
		
		assign(l,r,nu,root<<1,tl,mid);
		assign(l,r,nu,root<<1|1,mid+1,tr);
//		printf("%d")
		data[root]=data[root<<1]+data[root<<1|1];
	}
	
	
	
	
}




}a;


int main(){

}
