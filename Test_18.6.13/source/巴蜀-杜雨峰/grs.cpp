#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define N 406
using namespace std;
int x[N],y[N];
int vst[N][N];
int main()
{
	freopen("restore.in","w",stdout);
	srand(time(NULL));
	int n=100;
	cout<<n<<"\n";
	
	for (int i=1;i<=n;i++)
	{
		do
		{
			x[i]=rand()%100,y[i]=rand()%100;
		}while (vst[x[i]][y[i]]);
		vst[x[i]][y[i]]=1;
		
	}
	for (int i=1;i<=n;i++,cout<<"\n")
		for (int j=1;j<=n;j++)
		{
			double xi=1.0*x[i]/100,yi=1.0*y[i]/100,xj=1.0*x[j]/100,yj=1.0*y[j]/100;
			cout<<fixed<<setprecision(14)<<sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj))<<" ";	
		}
		
}
