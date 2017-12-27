#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int k,p,q;
int l,r;
int total;
int re[1000000];
int list[11];
int getsum(int x)
{
	int rz=x/list[10];
	int i=0;
	for(i=9;i>0;i--)
	{rz+=x/list[i]%10;
	}
	return rz;
}
int main()
{
	int i=0,j=0,k=0;
	list[1]=1;
	
	for(i=2;i<11;i++)
    list[i]=10*list[i-1];
    

	scanf("%d%d%d%d%d",&k,&p,&q,&l,&r);
	
	for(i=1;i<=90;i++)
	{long long t=(long long)pow(i,k)*p;

	if(getsum(t+q)==i&&l<=t+q&&r>=t+q)
	re[total++]=t+q;

    }

	sort(re,re+total);
	printf("%d\n",total);
	if(total>0)
	for(i=0;i<total;i++)
	printf("%d ",re[i]);
}
