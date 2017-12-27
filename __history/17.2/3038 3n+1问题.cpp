#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>ji,ou; 
int t,n;
int times;
int main()
{
	void dfs(int);
	scanf("%d",&t);
	int i=0;
	for(i=0;i<t;i++)
	{
		ji.clear();
		ou.clear();
		times=0;
		scanf("%d",&n); 
	dfs(n);
		
		
	}
	
	
}
void dfs(int x)
{
	if(x==1)
	{printf("%d\n",times);
	return ;
	}
	times++;
	
	if(x%2)
	{
	vector<int>::iterator it;
	it=lower_bound(ji.begin(),ji.end(),x*3+1);
	if(it!=ji.end())
	{
		if(*it!=3*x+1)
		ji.insert(it,3*x+1);
		else{
		printf("-1\n");
		return;
		}
	}
	else {
	ji.push_back(3*x+1); 
           }
	dfs(3*x+1);
    }
	else 
	{
		vector<int>::iterator it;
	it=lower_bound(ou.begin(),ou.end(),x/2);
	if(it!=ou.end())
	{
		if(*it!=x/2)
		ou.insert(it,x/2);
		else{
		printf("-1\n");
		return;
		}
	}
	else 
	{
	
		ou.push_back(x/2); 
	}
	
	dfs(x/2);
		
		
	}
	
}
