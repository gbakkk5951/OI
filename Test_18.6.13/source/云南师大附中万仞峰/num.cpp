#include <bits/stdc++.h>

using namespace std;

double dist[100][100];
double ans[100][2];
double d(int i,int j)
{
	if(i>j)
	{
		swap(i,j);
	}
	return (ans[i][0]-ans[j][0])*(ans[i][0]-ans[j][0])+(ans[i][1]-ans[j][1])*(ans[i][1]-ans[j][1]);
}
int main(void)
{
	freopen("restore.in","w",stdout);
	
	int n=100;
	double asdf;
	
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			srand(time(NULL));
			asdf*=double((rand()%2147483647))/60000;
			asdf-=i;
			asdf+=j;
			
			ans[i][j]=asdf;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dist[i][j]=sqrt(d(i,j));
			printf("%.6lf ",dist[i][j]);
		}
		cout<<"\n";
	}
	
	
	
	return 0;
}
