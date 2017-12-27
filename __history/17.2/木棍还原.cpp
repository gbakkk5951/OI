#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int mx=0;
int data[70];
int vis[70];
int sum;
int ag;
int lgst;
int bst;
int n;
bool dfs(int rm,int nu,int iter=1);
int main()
{scanf("%d",&n);
int i,j,k,l;
for(i=0;i<n;i++)
{

scanf("%d",data+i);sum+=data[i];mx=max(mx,data[i]);
}sort(data,data+n,greater<int>());

for(i=mx;i<=sum;i++)
{
	if(!(sum%i))
	{
		ag=i;
		vis[0]=true;
		if(dfs(ag-data[0],1))
		{
			printf("%d\n",i);
			break;
		}
	}
}
}
bool dfs(int rm,int nu,int iter)
{
//	printf("in(%d,%d,%d)",rm,nu,iter);
	int fst=214;
	int i,j,k,l;
	int sec=214;
	bool flag;
	if(rm == ag){
		vis[nu]=true;
		
		for(i=0;i<n;i++)
		{
		if(!vis[i])
		sec=min(sec,i);
		}
		if(sec!=214)
		{
		if(dfs(rm-data[nu],sec,iter+1))
		return true;
		else return false ;
		}
		else return true;
	}
	
	
	else	if(rm!=0)	{
//	printf("rm!=0");
	for(i=nu;i<n;i++)
	{
	fst=214;
	sec=214;
	if(!vis[i]&&data[i]<rm)
	{
		
//	printf("<");
		flag=true;
	vis[i]=true;
	for(j=0;j<n;j++)
	{if(!vis[j])
	sec=min(sec,j);}
	if(!dfs(rm-data[i],sec,iter+1))
	{
	vis[i]=false;
	}
	else {vis[i]=false;
	return true;
	}
	}
	else if(!vis[i]&&data[i]==rm)
	{
//		printf("=");
		vis[i]=true;
		for(j=0;j<n;j++)
		{
			if(!vis[j])
			{fst=min(j,fst);
			if(fst!=j); 
			{
				sec=j;
				break;
			}
			}
		}
		vis[fst]=true;
		if(sec!=214)
		{flag=true;
		if(!dfs(ag-data[fst],sec,iter+1))
		{
		vis[fst]=false;
		vis[i]=false;return false;
		}
		else {vis[fst]=false;vis[i]=false;return true;}
		}
		else {vis[fst]=false;vis[i]=false;return true;}
	}

	
	
	}
	return false;
	}
	else//rm=0;
	{//printf("rm=0");
		vis[nu]=true;
		

		for(i=0;i<n;i++)
		{
			if(!vis[i])
			sec=min(sec,i);
		}
		if(sec==214)
		return true;
		else {
			
			bool temp= dfs(ag-data[nu],sec,iter+1);
			vis[nu]=false;
			return temp;
		}
		vis[nu]=false;
	}
}
