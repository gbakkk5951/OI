#include<cstdio>
struct matrix{
	int x,y;
	matrix *m1,*m2;
	long long xsum[801][801];
	long long ysum[801][801];
	
	long long data[801][801]; 
	bool vis[801][801];
	void mul(matrix &ma,matrix &mb){
		this->x=mb.x;
		this->y=ma.y;
		int i,j,k;
		for(j=1;j<=this->y;j++){
			for(i=1;i<=this->x;i++){
				for(k=1;k<=ma.x;k++){
					this->data[i][j]+=ma.data[k][j]*mb.data[i][k];
				}
			}
		}
	}
	void prefix(){
		int i,j;
		for(i=1;i<=x;i++){
			for(j=1;j<=y;j++){
				data[i][j]+=data[i-1][j]+data[i][j-1]-data[i-1][j-1];
			}
		}
	}
	
	void nprefix(){
		int i,j;
		for(i=1;i<=x;i++){
			for(j=1;j<=y;j++){
				xsum[i][j]=xsum[i][j-1]+m1->data[i][j];
			}
		}
		for(i=1;i<=x;i++){
			for(j=1;j<=y;j++){
				ysum[i][j]=ysum[i-1][j]+m2->data[i][j];
			}
		}
		
		
		
		
		
		
		
	}
	
	long long nquery(int x1,int y1,int x2,int y2){
		long long ans=0;
		int i=0;
		
		int temp;
		if(x1>x2)
		{
			temp=x2;
			x2=x1;
			x1=temp;	
		}
		if(y1>y2){
			temp=y2;
			y2=y1;
			y1=temp;
		}
		
		for(i=1;i<=x;i++){
			ans+=(xsum[i][y2]-xsum[i][y1-1])*(ysum[x2][i]-ysum[x1-1][i]);
		}
		return ans;
	}
	
	void scan(int ix,int iy){
		x=ix;y=iy;
		int i,j;
		for(j=1;j<=y;j++)
		{
			for(i=1;i<=x;i++){
				scanf("%lld",&this->data[i][j]);
			}			
		}
	}
	long long query(int x1,int y1,int x2,int y2){
		int temp;
		if(x1>x2)
		{
			temp=x2;
			x2=x1;
			x1=temp;	
		}
		if(y1>y2){
			temp=y2;
			y2=y1;
			y1=temp;
		}
		return (this->data[x2][y2]-data[x1-1][y2]-data[x2][y1-1]+data[x1-1][y1-1]);
	}
	
	
	long long pquery(int x1,int y1,int x2,int y2){
		int temp;
		if(x1>x2)
		{
			temp=x2;
			x2=x1;
			x1=temp;	
		}
		if(y1>y2){
			temp=y2;
			y2=y1;
			y1=temp;
		}
		int i,j,k;
		long long ans=0;
		int m;
		for(j=y1;j<=y2;j++){
			for(i=x1;i<=x2;i++){
				if(!vis[i][j]){
					for(m=1;m<=x;m++){
						data[i][j]+=m1->data[m][j]*m2->data[i][m];
					}
					vis[i][j]=true;
				}
				ans+=data[i][j];
			}
		}
		
		return ans;
		
		
	}
	void relate(matrix &ma,matrix &mb)
	{
		this->m1=&ma;
		this->m2=&mb;
		this->x=mb.x;
		this->y=ma.y;
	}
	
};
matrix a,b,c;

int main(){
	int q,n;
	int i,j,k,l,m;
	scanf("%d%d",&n,&q);
	a.scan(n,n) ;
	b.scan(n,n); 
	c.relate(a,b);
	c.nprefix();
	for(m=0;m<q;m++){
		scanf("%d%d%d%d",&i,&j,&k,&l);
		printf("%lld\n",c.nquery(j,i,l,k));
	}
	
	
}
