#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<set>
#include<map>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
#define MAXN 100
int n,cnt,pos;
double dist[MAXN+10][MAXN+10];
long double x[10],y[10],ansx[MAXN+10],ansy[MAXN+10];
void read(){
	Read(n);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%lf",&dist[i][j]);
}
long double sqr(long double x){
	return x*x;
}
void solve(){
	ansx[2]=x[2]=dist[1][2];
	int i;
	cnt=2;
	for(i=3;i<=n;i++){
		if(cnt==2){
			ansx[i]=(-(sqr(dist[1][i]))+(sqr(dist[2][i])-sqr(x[2])))/(2*x[1]-2*x[2]);
			ansy[i]=sqrt(sqr(dist[1][i])-sqr(ansx[i]));
			if(fabs(ansy[i])>1e-8){
				x[++cnt]=ansx[i];
				y[cnt]=ansy[i];
				pos=i;
			}
		}
		else{
			long double tx[3],ty[3],b[3];
			tx[1]=2*x[1]-2*x[2],ty[1]=2*y[1]-2*y[2],b[1]=(sqr(dist[2][i])-sqr(x[2])-sqr(y[2]))-(sqr(dist[1][i])-sqr(x[1])-sqr(y[1]));
			tx[2]=2*x[1]-2*x[3],ty[2]=2*y[1]-2*y[3],b[2]=(sqr(dist[pos][i])-sqr(x[3])-sqr(y[3]))-(sqr(dist[1][i])-sqr(x[1])-sqr(y[1]));
		//	if(i==4)
		//		printf("%f %f %f\n%f %f %f\n",tx[1],ty[1],b[1],tx[2],ty[2],b[2]);
			ty[2]-=ty[1]*tx[2]/tx[1],b[2]-=b[1]*tx[2]/tx[1],tx[2]-=tx[1]*tx[2]/tx[1];
		//	if(i==4)
		//		printf("%f %f %f\n%f %f %f\n",tx[1],ty[1],b[1],tx[2],ty[2],b[2]);
			ansy[i]=b[2]/ty[2];
			ansx[i]=(b[1]-ty[1]*ansy[i])/tx[1];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%.6f %.6f\n",double(ansx[i]),double(ansy[i]));
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	read();
	solve();
}
