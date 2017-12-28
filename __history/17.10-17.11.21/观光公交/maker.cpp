#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	int i,j,n,m,k,a,b;
	srand(time(0));
	n=5,m=5,k=2;
	printf("%d %d %d\n",n,m,k);
	for(i=1;i<n;i++)
	{
		printf("%d ",rand()%10);
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		printf("%d ",rand()%20);
		a=rand()%(n-2)+1;
		b=rand()%(n-a)+1+a;
		printf("%d %d\n",a,b);
	}
	return 0;
}
