#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,m,ms,me,a[N],b[N],c[N],ans,mx[N];
void dfs(int d,int va,int s,int e)
{
	if((d>m&&(s<ms||e<me))||va+mx[d]<=ans)
		return;
	if(d>n)
	{//cout<<"OK"<<endl;
		ans=max(ans,va);
		return;
	}
	c[d]=1;
	dfs(d+1,va+a[d],s-(d>m&&c[d-m]==1)+1,e-(d>m&&c[d-m]==2));
	c[d]=2;
	dfs(d+1,va+b[d],s-(d>m&&c[d-m]==1),e-(d>m&&c[d-m]==2)+1);
	c[d]=0;
}
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&ms,&me);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		mx[i]=max(a[i],b[i]);
	for(int i=n;i>=1;i--)
		mx[i]=mx[i+1]+mx[i];
	dfs(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}
/*
10 4 1 2
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
*/