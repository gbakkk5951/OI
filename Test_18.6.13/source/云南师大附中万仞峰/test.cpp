#include <bits/stdc++.h>
#include <cmath>

using namespace std;

double dist[100][100];
double ans[100][2];

double d(int i,int j)
{
	return (ans[i][0]-ans[j][0])*(ans[i][0]-ans[j][0])+(ans[i][1]-ans[j][1])*(ans[i][1]-ans[j][1]);
}

int main(void)
{
	ifstream cin("restore.out");
	ifstream in("restore.in");
	//ofstream cout("tes.out");
	
	int n;
	in>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ans[i][0]>>ans[i][1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			in>>dist[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(abs(sqrt(d(i,j))-dist[i][j])>1e-3)
			{
				cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[j][0]<<" "<<ans[j][1]<<d(i,j)<<" "<<dist[i][j]<<" "<<i<<" "<<j<<endl;
			}
		}
	}
	
	return 0;
}
