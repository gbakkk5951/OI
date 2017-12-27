#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct fm{
int num=0;
int id=0;
}data[100000];
int last=0;
int n=0;
int zmax=0;
vector<int>save;
int main()
{
	int i=0,j=0;
	int tempid;
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	int po=last;
    	scanf("%d",&tempid);
    	for(j=0;j<last;j++)
    	{if(data[j].id==tempid)
    	{
    		po=j;
    		break;
    		
		}
		}
		data[j].id=tempid;
		data[po].num++;
		if(po==last)
		last++;
	}

	for(i=0;i<last;i++)
	{
		if(data[i].num>zmax)
		{zmax=data[i].num;
		save.clear();
		save.push_back(data[i].id);
		}else if(data[i].num==zmax)
		{
		save.push_back(data[i].id);
			
		}
		
		
	}
	printf("%d\n",zmax);
	sort(save.begin(),save.end());
	for(i=0;i<save.size();i++)
	{
		printf("%d ",save[i]);
		
	}
	
	return 0;
}
