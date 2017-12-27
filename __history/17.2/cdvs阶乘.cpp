#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n;
int mx=0;
vector<int>a;
vector<int>ans;
int main()
{

n=1;
a.resize(n);
int temp;
ans.resize(n); 
int i=0;
for(i=0;i<n;i++)
{scanf("%d",&temp);
a[i]=temp;
if (temp>mx)
mx=temp;
}

	int timx=1;
	int re=0;
	int time=1;
	
	while(mx/(5*timx)>=1)
	{
	int x=1;
	int ts=1;
	if(5*timx==(int)pow((double)5,(double)(time+1))){
	time++;
	re+=time;
	
	}else
	for(x=time;x>=1;x--)
	{
	 if((5*timx>=(int)pow((double)5,(double)(x)))&&((5*timx)%(int)pow((double)5,(double)(x))==0) ){

	re+=x;
	break;
	}
		
	}
	for(i=0;i<n;i++)
	{
		if(5*timx<=a[i]&&(5*timx+5>a[i]))
		ans[i]=re;
	}
	
	
	timx++;
	}
	
for(i=0;i<n;i++)
printf("%d\n",ans[i]);
	
	


	 
	
}
