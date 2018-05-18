#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int sle[1010];int eat[1010];
int book[1010];
int n;int k;int me;int ms;int up;
int res;
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d",&n,&k,&ms,&me);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sle[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&eat[i]);
	}
	up=pow(2,n);
	for(int i=0;i<=up-1;i++)
	{
		int e=0;int s=0;int ret=0;int p=i;
		for(int j=1;j<=n;j++){book[i]=0;}
		for(int j=1;j<=n;p>>=1,j++){book[j]=(p&1);}
		for(int j=1;j<=k;j++)
		{
			if(book[j]){e++;ret+=eat[j];}
			else {s++;ret+=sle[j];}
		}
		for(int j=k+1;j<=n;j++)
		{if(e<me||s<ms)goto ed;
			if(book[j]){e++;ret+=eat[j];}
			else {s++;ret+=sle[j];}
			if(book[j-k]){e--;}else {s--;}
		}
		if(e<me||s<ms)goto ed;
		res=max(res,ret);ed:;
	}
	fclose(stdin);fclose(stdout);
	printf("%d",res);
}


