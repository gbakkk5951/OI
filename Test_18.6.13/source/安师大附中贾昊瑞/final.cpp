#include"bits/stdc++.h"
#define F(i,j,n) for(register int i=j;i<=n;i++)
#define D(i,j,n) for(register int i=j;i>=n;i--)
#define ll long long
using namespace std;
void in(int&a);void in(ll&a);
int a[9][9],x[9],n,p,q;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void work(){
	F(i,1,n){F(j,i+1,n)if(gcd(x[i],x[j])==1){p=i,q=j;break;}if(p)break;}
//	printf("%d %d\n",p,q);
	int d=2,y=-1;if((p+q)&1)y=-y;
	F(i,1,n)if(i!=p&&i!=q)a[++d][i]=1;
	F(i,-2000,2000)F(j,-2000,2000)if(x[p]*j-x[q]*i==y){a[2][p]=i;a[2][q]=j;return;}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	#endif
	in(n);
	F(i,1,n)in(x[i]),a[1][i]=x[i];
	if(n==1&&x[1]!=1){puts("no solution");}
	work();
	F(i,1,n){F(j,1,n)printf("%d ",a[i][j]);puts("");}
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=0;c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=0;c=getchar();}if(y)a=-a;}

