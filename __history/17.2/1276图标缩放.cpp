#include<cstdio>
int main()
{
	int n;
	char data[3][3]={'*','x','*',' ','x','x','*',' ','*'};
	int i,j,k,l;
	scanf("%d",&n);
	
	for(i=0;i<3;i++)//换行 
	for(j=0;j<n;j++)//每行重复 
	{
	
	for(k=0;k<3;k++)//换每行字符 
	for(l=0;l<n;l++)//每个字符重复 
	{
		putchar(data[i][k]);
		
	}
	putchar('\n');/ 
	}	
}
