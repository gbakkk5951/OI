#include<cstdio>

#include<ctype.h>
int num=0,n;
char map[102][202]={'\n'};
int main(){

/*	while(EOF!=(temp=getchar()))
	{if(temp=='\n')
	printf("a");
	if(temp=='\r')
	printf("b");
	}
*/	
	scanf("%d",&n);
	int i=1,j=1;
	
	void dfs(int,int);
	while(EOF!=(map[i][j]=getchar()))
	{

		if(map[i][j]=='\n'||map[i][j]=='\r')
		{
		map[i][j]='\n';
			if(j==1)
			continue;
		i++;
		j=1;
	    }
		else 
		j++;
		if(i>n)
		break;	
	}
	if(map[i][j]==EOF)
	map[i][j]='\n';
	i=1,j=1;
	while(i<=n)
	{
		if(map[i][j]!='\n')
	{
		if(isalpha(map[i][j]))
		{	dfs(i,j);
		num++;
		}
	
		j++;
	}else {j=1;
	i++;
	}
		
	}
	printf("%d",num);	
}
void dfs(int i,int j){
	if(isalpha(map[i][j]))
	{map[i][j]='0';
	dfs(i-1,j);
	dfs(i+1,j);
	dfs(i,j+1);
	dfs(i,j-1);
	
	
	}
	
}
