//by achhhy
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
inline int in()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f*x;
}
//need changing
const int inf=(1<<30);
const int mod=1e9+7;
const int N=110;

int n,m;
double d[N][N];
double x[N],y[N];

inline double f(double x) {return x*x;}
inline double cal(int a,int b)
{
	return sqrt(f(x[a]-x[b])+f(y[a]-y[b]));
}

const double eps=1e-4;

bool check(int p,double X,double Y)
{
	rep(i,3,p-1)
		if(fabs(cal(i,p)-d[i][p])>eps)
			return 0;
	return 1;		
}


int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	n=in();
	rep(i,1,n) rep(j,1,n) scanf("%lf",&d[i][j]);
	x[2]=d[1][2];
	rep(i,3,n)
	{
		double a=d[1][i],b=d[2][i],c=d[1][2];
		double co=(f(a)+f(c)-f(b))/(2.0*a*c);
		if(check(i,x[i]=a*co,y[i]=a*sqrt(1-co*co))) continue;
		else y[i]=-y[i];
	}
	rep(i,1,n) printf("%.10lf %.10lf\n",x[i],y[i]);	
	return 0;
}



