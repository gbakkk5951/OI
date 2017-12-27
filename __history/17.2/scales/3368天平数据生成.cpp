#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;
int data[310]; //编号 
int data2[310];//关联的数 
int data3[310];//相等的数 
int q,p,n;
void shuffle()
{
	int sum=p;
	int i,j,k,l;
	for(i=0;i<n;i++)
	{
		data[i]=i+1;
	}
	srand((int)clock());
	for(i=0;i<n;i++)
	{
		j=rand()%n;
		k=data[j];
		data[j]=data[i];
		data[i]=k;
		data2[i]=0;
		data3[i]=0;
	}
//	printf("sum=%d\n",sum);
	while(sum!=0)
	{	sum=p;
//	printf("\n");

	memset(data2,0,sizeof(data2));
	memset(data3,0,sizeof(data3));
		for(i=0;i<n;i+=data3[i]+1)
		{
	//		printf("%d-",i);
			
			bool flag=false;
	 		data2[i]=rand()%(min(n,p)+1);
	 		if(data2[i]>n-i-1)
	 		data2[i]=n-i-1;
	//		data2[i]=rand()%(p);
			if(data2[i]>sum)
			{
			data2[i]=sum;
			sum=0;
			flag=true;
			}
			else sum-=data2[i];
			
			data3[i]=rand()%min(5,data2[i]/3+1);
			
			
			if(flag)
			return ;
			
		}
		
		
	}
	
	
}


int main()
{
	int i,j,k,l,m;
	srand(clock());
	for(m=1;m<=10;m++)
	{
		scanf("%d%d%d",&n,&p,&q);
		char name[20]="scales";
		char temp[20];
		sprintf(temp,"%d.in",m);
		strcat(name,temp);
		FILE *fa=freopen(name,"w",stdout);
		printf("%d %d %d\n",n,p,q);
		
		shuffle();

		
		
//		system("pause");
		//status
		for(i=0;i<n;i++)
		{
			for(j=0;j<data3[i];j++)
			{
				bool shunxu=rand()%2;
				//
				if(shunxu)
				{
					printf("3 %d %d\n",data[i],data[i+j+1]);
					
				}
				else
				{
					printf("3 %d %d\n",data[i+j+1],data[i]);
				}
				
			}
			for(;j<data2[i];j++)
			{
				
				int rd=data[i+(rand()%(data3[i]+1))];
				bool shunxu=rand()%2;
				if(shunxu)
				{
					printf("1 %d %d\n",rd,data[i+j+1]);
				}
				else
				{
					printf("2 %d %d\n",data[i+j+1],rd);
				}
				
			}
			
		}
		
		//query
		for(j=0;j<q;j++)
		{
			printf("%d %d\n",rand()%n+1,rand()%n+1);
		}
		
		
		fclose(fa);
	}
	
	
}
