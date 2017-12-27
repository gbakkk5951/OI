#include<cstdio>
int main()
{int n;
int data[101];
int i,j,k;
int sum=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&data[i]);
sum+=data[i];
}
int ag=sum/n;
int step=0;
int temp=0;
for(i=0;i<n;i++)
{
	if(data[i]^ag)
	{temp=data[i]-ag;
	data[i+1]+=temp;
		step++; 
		
	}
}
	
	printf("%d",step);
}
