#include<cstdio>
int main()
{
	int n;
	char data[3][3]={'*','x','*',' ','x','x','*',' ','*'};
	int i,j,k,l;
	scanf("%d",&n);
	
	for(i=0;i<3;i++)//���� 
	for(j=0;j<n;j++)//ÿ���ظ� 
	{
	
	for(k=0;k<3;k++)//��ÿ���ַ� 
	for(l=0;l<n;l++)//ÿ���ַ��ظ� 
	{
		putchar(data[i][k]);
		
	}
	putchar('\n');/ 
	}	
}
