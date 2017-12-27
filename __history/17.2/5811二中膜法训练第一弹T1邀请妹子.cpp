#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int n,data[5005];
int ans;
int nu;
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	for(i=30;i>=0;i--){
		int t=0;
		for(j=0;j<n;j++){
			if((data[j]>>i)&1)
			{
				t=data[j];
			}
			
		}
		if(t)
		{
		
		for(j=0;j<n;j++){
			if(data
			
			
			
			
			
			
			
			
			
			
			 [j]>>i&1)
			{
				data[j]^=t;
			}
		}
		
		}
		if(!((ans>>i)&1))	ans^=t;
		
		
		
	}
	for(i=30;i>=0;i--)
	{
		if((ans>>i)&1)
		nu++;
	}

	
	
	printf("%d\n%d",ans,nu);
	
	
}
