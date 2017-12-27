#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

int length=0;
vector<int>uv;
int n,map[101][101];
int v[101];

int main(){

	scanf("%d",&n);
	int i,j;
	uv.resize(n+1);
	for(i=1;i<n;i++)
	uv[i]=i+1;
	
	for(i=1;i<=n;i++) 
	for(j=1;j<=n;j++)
	scanf("%d",&map[i][j]);
	int m=0;
int minj=0;
	v[1]=1;
	for(m=1;m<n;m++)
	{

	int min=2147483647,miny=0;
	for(i=1;i<=m;i++) 
	{

	for(j=1;j<=n-m;j++)
    {
		if(map[v[i]][uv[j]]<min)
        {
		min=map[v[i]][uv[j]];
        minj=j;
		miny=uv[j];
		
		
		}
    	
	}
	
	
	}
	uv.erase(uv.begin()+minj);
	length+=min;

	v[m+1]=miny;
    }
    
    printf("%d",length);
}


