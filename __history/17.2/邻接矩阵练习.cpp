#include<cstdio>
int map[100][100];
int tot,head[100],nxt[500];
int point[500];
add(int x,int y)
{
	tot++;
	point[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}


int main()
{int n;
scanf("%d",&n);
int i=0;
int t1,t2;

for(i=0;i<n;i++)
{

scanf("%d%d",&t1,&t2);
add(t1,t2);
add(t2,t1);
//map[t1][t2]++;
//map[t2][t1]++;
}/*
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d%d",&t1,&t2);
	printf("%d\n",map[t1][t2]);
}
*/
for(i=0;i<10;i++)
{

printf("%d:",i);
int t=head[i];
while(t!=0)
{
	printf("%d,",point[t]);
	t=nxt[t];
	
}
printf("\n");
}
 } 
