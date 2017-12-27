#include<cstdio>
#include<cstring>
struct matrix{
	matrix(){
		memset(this,0,sizeof(matrix));
		
	}
	long long val[201][201];
	int j,i;
	
	friend matrix  operator * (matrix ma,matrix mb){
		matrix ans;
		ans.i=ma.i;
		ans.j=mb.j;
		int k=1,l=1,m=1,n=1;
		
		for(l=1;l<=ans.i;l++)
		for(k=1;k<=ans.j;k++){
			for(m=1;m<=ma.j;m++){
				ans.val [k][l]+=ma.val[m][l]*mb.val[k][m];
			}
		}
		return ans;
	}
	void print(){
		int ti,tj;
		for(ti=1;ti<=this->i;ti++){
		for(tj=1;tj<=this->j;tj++){
			printf("%lld ",this->val[tj][ti]);
		}
		printf("\n");
	}
	
		
	}
	
};
matrix a,b,ans;
int main(){
	int i,j,k;

	scanf("%d%d",&a.i,&a.j);
	for(i=1;i<=a.i;i++){
	
		for(j=1;j<=a.j;j++){
			scanf("%lld",&a.val[j][i]);
		}
	}

	scanf("%d%d",&b.i,&b.j);
	for(i=1;i<=b.i;i++){
		for(j=1;j<=b.j;j++){
			scanf("%lld",&b.val[j][i]);
		}
	}
	ans=a*b;
	ans.print() ;	

	
}
