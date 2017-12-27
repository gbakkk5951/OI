#include<cstdio>
struct begin{
int n;
int vis[11];
int data[11];
begin(){
	scanf("%d",&n);
	dd(n);
}
void dd(int time)
{int i;
	if(!time)
	{for(i=n;i;i--)
	printf("%d ",data[i]);
	printf("\n");
	}if(time)
	for(i=1;i<=n;i++){
		if(!vis[i])
		{
		data[time]=i;

		vis[i]=true;
		dd(time-1);
		vis[i]=false;

		
		}
	}
	
}


}instance;
int main(){}
