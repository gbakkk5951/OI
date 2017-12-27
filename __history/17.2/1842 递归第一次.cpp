#include<cstdio>
int dfs(int x)
{
	if(x>=0)
	return 5;
	else return dfs(x+1)+dfs(x+2)+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",dfs(n));
}
