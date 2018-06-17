#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=7;
int n,A[N],C[N][N];
int gcd(register int a,register int b){return b?gcd(b,a%b):a;}
int Check(register int a,register int b,register int c,register int d){
	if(b){
		int t=Check(b,a%b,d,c-a/b*d);
		return t?t+1:0;
	}	
	else return a==1&&c==0&&d==1;
}
bool Work(int p,int q){
	int i,j,d=1,c=0;
	int *D=C[1];
	for(i=1;i<=n;i++)
		D[i]=A[i];
	if(p!=1)swap(D[p],D[1]),d=-d;
	if(q!=2)swap(D[q],D[2]),d=-d;
	i=D[2];
	for(j=-2000;j<=2000;j++)
		if(c=Check(D[1],i,D[2],j))break;
	if(!c){
		for(i=-2000;i<=2000;i++){
			if(gcd(abs(i),D[1])!=1)continue;
			for(j=-2000;j<=2000;j++)
				if(c=Check(D[1],i,D[2],j))break;
			if(c)break;
		}
	}
	if(!c)return 0;
	if(~abs(c)&1)d=-d;
	C[2][1]=i*d,C[2][2]=j*d;
	for(i=3;i<=n;i++)
		C[i][i]=1;
	for(i=1;i<=n;i++)
		swap(C[i][2],C[i][q]);
	for(i=1;i<=n;i++)
		swap(C[i][1],C[i][p]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",C[i][j]);
		puts("");
	}
	return 1;
}
int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	int i,p,q,f;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(p=1;p<=n;p++){
		f=0;
		for(q=1;q<=n;q++){
			if(q==p)continue;
			if(gcd(A[p],A[q])==1){f=1;break;}
		}
		if(f==1&&Work(p,q))return 0;
	}
	puts("no solution");
}
