#include<cstdio>
#include<bitset> 
using namespace std;
bitset<1000010>vis;
int main()
{
	int n;
	scanf("%d",&n);
	int i=2;
	int j;
	for(i=2;i<n;i++)
	{
		if(!vis[i])
		{
			printf("%d\n",i);
			for(j=1;j*i<n;j++)
			{
				vis[i*j]=true;				
			}
			
			
		}
		
	}
	
}
