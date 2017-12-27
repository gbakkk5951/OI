#include<cstdio>
int map[101][101];
int n;
int mid;
void right(int x,int y,int num);
void left(int x,int y,int num);
void up(int x,int y,int num);
void down(int x,int y,int num);
void print();
int main()
{scanf("%d",&n);
mid=n/2;
map[mid][mid]=1;
if(mid+1<n)
right(mid+1,mid,2);
print();
}
void right(int x,int y,int num)
{

map[x][y]=num;
if(y-1>=0&&map[x][y-1]==0)
{
up(x,y-1,num+1);
}
else if(x+1<n)
right(x+1,y,num+1);
}
void left(int x,int y,int num)
{
	map[x][y]=num;
	if(y+1<n&&map[x][y+1]==0)
	{
		down(x,y+1,num+1);
	}
	else if(x-1>=0)
	left(x-1,y,num+1);
}

void up(int x,int y,int num)
{
		map[x][y]=num;
	if(x-1>=0&&map[x-1][y]==0)
	{

		left(x-1,y,num+1);
	}
	else if(y-1>=0)
	up(x,y-1,num+1);
	
}


void down(int x,int y,int num)
{	map[x][y]=num;
	if(x+1<n&&map[x+1][y]==0)
	{
		right(x+1,y,num+1);
	}
	else if(y+1<n)
	down(x,y+1,num+1);
    
}

void print()
{
	int sum=0;
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		printf("%d ",map[j][i]);
	}
	printf("\n");
    }
    for(i=0;i<n;i++)
    {
    	sum+=map[i][i];
    	map[i][i]=0;
    	sum+=map[n-1-i][i];
    	
	}
    printf("%d",sum);
    
    
    
}
