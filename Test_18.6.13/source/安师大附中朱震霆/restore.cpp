#include"algorithm"
#include"iostream"
#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"math.h"
#include"bitset"

using namespace std;

const int N=105;
typedef long double lf;
const double PI=acos(-1);

lf D[N][N],a[N][N],b[N],x[N],y[N];
bool vis[N],col[N][N];
int n;

void dfs(int x){
	vis[x]=1;
	if(fabs(a[1][x]-PI)<1e-4)return;
	for(int i=3;i<=n;i++)if(!vis[i]&&col[x][i])dfs(i);
}

lf area(lf a,lf b,lf c){
	lf p=(a+b+c)*0.5;
	lf s=p*(p-a)*(p-b)*(p-c);
	return sqrtl(s);
}

lf gt(lf doa,lf dob,lf dab){
//	if(fabsl(doa+dob-dab)<5e-5)return PI;
	lf SinAlpha=2*area(doa,dob,dab)/(doa*dob);
	if(SinAlpha>1)SinAlpha=1;
	lf Alpha=asinl(SinAlpha);
	lf d1=doa-dob*cosl(Alpha);
	lf d2=dob*SinAlpha;
	if(fabsl(d1*d1+d2*d2-dab*dab)<1e-6)
		return Alpha;
	return PI-Alpha;
}

int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	register int i,j;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){
		double x;
		scanf("%lf",&x);
		D[i][j]=x;
	}
	for(i=2;i<=n;i++)for(j=i+1;j<=n;j++)
		a[i][j]=a[j][i]=gt(D[1][i],D[1][j],D[i][j]);
	b[2]=0;
	for(i=3;i<=n;i++)for(j=i+1;j<=n;j++){
		lf a1=a[i][2],a2=a[j][2],a3=a[i][j];
		if(fabsl(fabsl(a1-a2)-a3)<1e-5)col[i][j]=col[j][i]=1;
		else col[i][j]=col[j][i]=0;
	}
	dfs(3);
	for(i=3;i<=n;i++)b[i]=vis[i]?a[i][2]:-a[i][2];
	for(i=2;i<=n;i++){
		x[i]=D[1][i]*cosl(b[i]);
		y[i]=D[1][i]*sinl(b[i]);
	}
	for(i=1;i<=n;i++)printf("%.8lf %.8lf\n",(double)x[i],(double)y[i]);
	return 0;
}
