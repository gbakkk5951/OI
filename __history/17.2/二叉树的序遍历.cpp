#include<cstdio>
int l[17],r[17],p[17];
void mid(int root)
{
	if(l[root])
	mid(l[root]);
	printf("%d ",root);
	if(r[root])
	mid(r[root]);
}
void first(int root)
{printf("%d ",root);
	if(l[root])
	first(l[root]);
	if(r[root])
	first(r[root]);
}
void last(int root)
{
	if(l[root])
	last(l[root]);
	if(r[root])
	last(r[root]);
	printf("%d ",root);
}
int n;
int main()
{
	scanf("%d",&n);
	int i=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",l+i,r+i);
		p[*(l+i)]=i;
		p[*(r+i)]=i;
		
		
	}
	for(i=1;i<=n;i++)
	{
		if(!p[i])
		{
			first(i);
			printf("\n");
			mid(i);
			printf("\n");
			last(i);
			return 0;
		}
	}
	
}
