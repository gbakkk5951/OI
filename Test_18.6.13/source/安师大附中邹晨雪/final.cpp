#include<bits/stdc++.h>
using namespace std;
const int N=50,P=998244353;
int A[N],G[N][N],a[N][N],n;
inline int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
inline int ksm(int n,int c){
	int jc=1;
	while(c){
		if(c&1) jc=(long long)jc*n%P;
		n=(long long)n*n%P;
		c>>=1;
	}
	return jc;
}
int Gauss(){
	int i,j,k,ans=1;
	for(i=0;i<n;++i)
	for(j=0;j<n;++j)
	a[i][j]=G[i+1][j+1];
	
	for(i=0;i<n;++i){
		for(j=i;j<n;++j)
		if(a[j][i]){
			if(j!=i) ans*=-1;
			for(k=0;k<n;++k)
			swap(a[i][k],a[j][k]);
			break;
		}
		int ny=ksm(a[i][i],P-2);
		for(j=0;j<n;++j)
		if(j!=i&&a[j][i]){
			int tmp=(long long)a[j][i]*ny%P;
			for(k=i;k<n;++k)
				a[j][k]=(a[j][k]-(long long)tmp*a[i][k]%P+P)%P;
		}
	}
	for(i=0;i<n;++i) ans=(long long)ans*a[i][i]%P;
	if(ans<0) ans+=P;
	return ans;
}
void work(int x,int y,int a,int b){
	int i;
	if(b==1){
		for(i=1;i<=n;++i) G[i][i]=1;
		if(y!=1) G[1][y]=1,G[y][1]=1,G[y][y]=0;
		for(i=1;i<=n;++i) if(i!=y) G[1][i]=A[i];
		G[1][x]=a;
		return;
	}
	work(y,x,b,a%b);
	int j,tim=a/b;
	for(i=1;i<=n;++i) G[i][x]+=G[i][y]*tim;
}
int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	int i,j,x,y; cin>>n;
	
	for(i=1;i<=n;++i) cin>>A[i];
	if(n==2){
		for(i=-2000;i<=2000;++i)
		for(j=-2000;j<=2000;++j)
		if(A[1]*j-A[2]*i==1){
			cout<<A[1]<<' '<<A[2]<<endl<<i<<' '<<j<<endl;
			return 0;
		}
		puts("no solution");
		return 0;
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(gcd(A[i],A[j])==1){
		x=i,y=j;
		if(A[i]>A[j]) swap(x,y);
		break;
	}
	work(y,x,A[y],A[x]);
	if(Gauss()==P-1)
	for(i=1;i<=n;++i) swap(G[n][i],G[n-1][i]);
	
	for(i=1;i<=n;cout<<endl,++i)
	for(j=1;j<=n;++j)
	cout<<G[i][j]<<' ';
	return 0;
}
