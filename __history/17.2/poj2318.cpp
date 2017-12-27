#include<cstdio>
#include<cstring>

struct beg{
	bool end;
	
	
	int bin[5010];
	int xl[5010],xr[5010];
	int n,m,x1,y1,x2,y2;
	void print(){
		int i=0;
		for(i=0;i<=n;i++){
			printf("%d: %d\n",i,bin[i]);
		}
		printf("\n");
	}
	
	
	void readin(){
		int i,j;
		int k;
		scanf("%d",&n);
		if(!n){
			end=true;
			return;
		}
		
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);

		xl[0]=x1;
		xr[0]=x1;
		xl[n+1]=x2;
		xr[n+1]=x2;
		for(i=1;i<=n;i++){
			scanf("%d%d",&xl[i],&xr[i]);	
		}
		for(i=0;i<m;i++){
			scanf("%d%d",&j,&k);
			binary(j,k,0,n);
		}
	}
	
	void binary(int x,int y,int l,int r){
		int mid=(l+r)>>1;
		if(l==r){
			bin[l]++;
			return;
		}
		int rr,rl;

			//叉乘右向量 
			rr=(xl[mid+1]-xr[mid+1])*(y-y2)-(x-xr[mid+1])*(y1-y2);
			//叉乘左向量 
			rl=	(xl[mid]-xr[mid])*(y-y2)-(x-xr[mid])*(y1-y2);

	

		if(rr>0){
			binary(x,y,l,mid);
		}else{
			if(rl>0){
				bin[mid]++;
				return;
			}
			binary(x,y,mid+1,r);
		}	
			
	}
	beg(){
		readin();
		while(!end)
		{
		print();
		memset(bin,0,sizeof(bin));
		
	
		readin();
		}
		
	}	
	

}exe;
int main(){}
