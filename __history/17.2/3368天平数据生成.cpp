#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int main()
{
	int i,j,k,l,m,q,p,n;
	srand(clock());
	for(i=1;i<=10;i++)
	{
		scanf("%d%d%d",n,p,q);
		char name[20]="scales";
		char nb[20]
		sprintf(nb,"%d.in",i);
		strcat(name,nb);
		FILE *fa=freopen(name,"w",stdout);
		
		
		for(j=0;j<p;j++)
		{
			printf("%d ",rand()%3+1);
			printf("%d ",rand()%n+1);
			printf("%d\n",rand()%n+1);
		}
		for(j=0;j<q;j++)
		{
			printf("%d %d",rand()%n+1,rand()%n+1);
		}
		
		
		fclose(fa);
	}
	
	
}
