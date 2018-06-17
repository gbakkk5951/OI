#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define tm ndhsfjk
#define y1 cjdksl
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-') f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f) x=-x;
			return ;
		}
}
//*********************************************

#define MAXN 100
#define eps 1e-10

int n;
double d[MAXN+10][MAXN+10];

inline double sqr(double x){
	return x*x;
}
namespace Part1{
inline double Getdist(double x,double y){
	return sqrt(sqr(x)+sqr(y));
}
void solve(){
	double x=(sqr(d[1][3])-sqr(d[2][3])+sqr(d[1][2])/(2*d[1][2]));
	double y=sqrt(sqr(d[1][3])-sqr(x));
	if((Getdist(x,y)-d[1][3])<eps&&(Getdist(x-d[1][2],y)-d[2][3])<eps){
		printf("0.000000 0.000000\n");
		printf("%.6f 0.000000\n",d[1][2]);
		printf("%.6f %.6f\n",x,y);
		return ;
	}
	x=(sqr(d[1][3])-sqr(d[2][3])-sqr(d[1][2])/(2*d[1][2]));
	y=sqrt(sqr(d[2][3])-sqr(x));
	printf("0.000000 0.000000\n");
	printf("%.6f 0.000000\n",d[1][2]);
	printf("%.6f %.6f\n",d[1][2]+x,y);
}
}
void read(){
	Read(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&d[i][j]);
}
void solve(){
	if(n==3) Part1::solve();
	//else if(n==4) Part2::solve();
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	
	read();
	solve();
	return 0;
}
