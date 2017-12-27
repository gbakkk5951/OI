#include<cstdio>
int n;
float t1,t2;
float sum;
float suma;
int main()
{int i=0;
scanf("%d",&n);
for(;i<n;i++)
{scanf("%f%f",&t1,&t2);
sum+=t1*t2;
suma+=t1;
}
	printf("%.2f",(float)sum/suma);
	
}
