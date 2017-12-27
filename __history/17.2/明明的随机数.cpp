#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> data;
int main() 
{

	int n=0,i=0,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		data.push_back(temp); 
		
	}
	int j=0;
	for(int i=0;i<data.size();i++){
	for(j=i+1;j<data.size() ;j++)
	if(data[i]==data[j]){data.erase(data.begin() +j);j--; 
	}	
	
	}
	
	sort(data.begin() ,data.end() );
	printf("%d\n",data.size() );
	for(i=0;i<data.size() ;i++)
	{printf("%d ",data[i]);
	}
	
}
