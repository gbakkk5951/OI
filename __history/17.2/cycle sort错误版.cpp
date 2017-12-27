#include<cstdio>


int size=5;
int main()
{
	int i=0;
	int temp;
		int array[size];
	int index[size];
	for(i=0;i<size&&scanf("%d",&temp)!=EOF;i++)
	{array[i]=temp;}


	
	for(i=0;i<size;i++)
	{index[i]=i;}
	int j,k;
	for(i=0;i<size;i++)
	{
		if(index[i]==-1)
		continue;
		int t;
		temp=0;
		
		//寻找索引 
		for(j=0;j<size;j++)
		{
		if(array[j]<array[i])
		{
		temp++;
		}
		}
		if(temp==i)
		continue;
		//相等处理
	//	bool b1=false;
		for(k=0;k<size-temp;k++)
		{
		if(temp=i)
		continue;
		if(array[temp]==array[i])
		temp++;
		else if(array[temp]==0)
		{array[temp]=array[i];
		index[temp]=-1;
	//	b1=true;
		break;
		} 
		else {
		t=array[temp];
		array[temp]=array[i];
		array[i]=0;
		index[temp]=-1;
		break;
	    }}
	  
		while(1)
		{
//		printf("{while");
		bool b=false;
			//寻找索引 
		temp=0;
		for(j=0;j<size;j++)
		{
		if(array[j]<t)
		{//  printf("=%d,%d=",temp,t);
		temp++;
		if(temp==5)
		{b=true;
		break;
		printf("+*+*-\n");
	    }
		}
		}
		//相等处理
		for(k=0;k<size;k++)
		{//printf("for(%d){",k);
		
		if(array[temp]==t)
		{temp++;
	
		if(temp==size)
		{
		printf("b"); 
		b=true;
		break;
		}
		}
		else if(array[temp]==0)
		{array[temp]=t;
		index[temp]=-1;
		b=true;
		break;
		} 
		else {
		int t2;
		t2=array[temp];
	//	printf("a%d,%da",temp,t2);
		array[temp]=t;
		t=t2;
		
		index[temp]=-1;
		//	printf("bug{temp=%d;array[temp]=%d}",temp,array[temp]);
		break;
	    }
	    //printf("for}");
		}
		if(b)
		{printf("b"); 
		break;
	}
		
//		printf("while}");
	    }
	    }
	    
for(i=0;i<size;i++)
printf("%d ",array[i]);	    

		}
	
	
	

