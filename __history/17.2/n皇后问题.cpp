#include<cstdio>
#include<vector>
using namespace std;
vector<int> az;
int n;
int ans;
int b[50];
int a[50];
int c[50];
int d[14];

void dfs(int x)
{
	int i=0,j=0;
	bool eok;

	for(i=1;i<=n;i++)
	{
		bool ok=true;
		if(b[i])ok=false;
		if(a[n-i+x])ok=false;
		if(c[x+i])ok=false;
		if(!ok)
		continue;
		if(n==x)
		{
		if(ans<3)
		{
		for(j=1;j<n;j++)
		
		az.push_back(d[j]); 
		az.push_back(i);
		}
		ans++;
		break;
		}
		b[i]++;
		a[n-i+x]++;
		c[x+i]++;
		d[x]=i;
		dfs(x+1);
		d[x]=0;
		b[i]--;
		a[n-i+x]--;
		c[x+i]--;
		
	}
	
}

int main()
{scanf("%d",&n);
int i=0;

dfs(1);

for(i=0;i<n;i++)
{
printf("%d ",az[0]);	
az.erase(az.begin());
}
printf("\n");
for(i=0;i<n;i++)
{
printf("%d ",az[0]);	
az.erase(az.begin() );
}
printf("\n");
for(i=0;i<n;i++)
{
printf("%d ",az[0]);	
az.erase(az.begin() );
}
printf("\n");
printf("%d",ans);
}
