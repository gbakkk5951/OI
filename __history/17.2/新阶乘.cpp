#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<long long>data;
vector<int>ans; 
vector<int>po;
int main(){
	int n;
	scanf("%d",&n); 
	data.resize(n);
	ans.resize(n);
	int i=0;
int temp;
int mx=0;
	for(i=0;i<n;i++)
	{scanf("%d",&temp);
	data[i]=temp;
	if(temp>mx)
	mx=temp;
	}
	
	po.push_back(1);
	po.push_back(5); 
	while(mx>po[po.size()-1])
	{po.push_back(po[po.size()-1]*5);
	}
	int j=0;
	int re=0;
	for(i=0;i<n;i++)
	{j=1;re=0;
		for(j=1;j<po.size();j++)
		{
			re+=(int)ceil(data[i]/po[j]);

		}
		ans[i]=re;
		
	}
		for(i=0;i<n;i++)
		{
			printf("%d\n",ans[i]);
		}
	
	return 0;
}
