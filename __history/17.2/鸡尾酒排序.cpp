#include<cstdio>

int n,i,j,data[100001];

int main()
{
	bool finish=false;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d",data+i);
	}
	int temp;
	while(!finish){
		finish=true;
		for(i=0;i<n-1;i++){
			if(data[i]>data[i+1]){
			
			temp=data[i];
			data[i]=data[i+1];
			data[i+1]=temp;
			finish=false;
			}
		}
		if(!finish)
		{finish=true;
		for(i=n-1;i>0;i--){
			if(data[i]<data[i-1])
			{finish=false;
			temp=data[i];
			data[i]=data[i-1];
			data[i-1]=temp;
				
			}
			
		}
		}
		
	}
	for(i=0;i<n;i++)
printf("%d ",data[i]);	
	
}
