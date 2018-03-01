#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int qbl[210];int n;
int map[210][210];int c=80000;
int line[210];bool fl;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	srand(202336617);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=1;i<=n;i++){qbl[i]=i;}
	for(int i=1;i<=c;i++)
	{
		random_shuffle(qbl+1,qbl+n+1);
		for(int i=1;i<=n-1;i++)
		{
			if(!map[qbl[i]][qbl[i+1]])goto ed;
		}
		if(map[qbl[n]][qbl[1]])
		{
			printf("0\n");for(int i=1;i<=n;i++){printf("%d ",qbl[i]);}return 0;
		}
		else if(!fl)
		{fl=true;for(int i=1;i<=n;i++){line[i]=qbl[i];}}
		ed:;
	}
	if(fl)
	{
		printf("1\n");
		for(int i=1;i<=n;i++){printf("%d ",line[i]);}return 0;
	}
	printf("-1");fclose(stdin);fclose(stdout);
	return 0;
}
