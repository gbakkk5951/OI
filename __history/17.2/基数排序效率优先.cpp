#include<stdio.h>
#include<vector>
#include<cmath> 
using namespace std;
vector <int> bukkit[10];
vector <int> bukkit2[10];
vector<int >data;
int main() 
{
FILE	*a,*b;
	int longest();
	a=freopen("随机数.out","r",stdin); 

int itemp=0;
	while(1)
	{
		if(~scanf("%d",&itemp))
		{
		data.push_back(itemp) ;
		
		
		} 
		else break;
		
	}
	int ln=longest();
	

	for(int s=0;s<ln;s++){
	if(s==0)
	for(int c=0;c<data.size();c++){
	int re=0;
	re=(data[c]/(int)pow((double)10,(double)s)%10);

	bukkit[re].push_back(data[c]);
	}
	else if(s%2==1) for(int c=0;c<10;c++){for(int z=0;z<bukkit[c].size();z++){
	
	int re=0;
	re=((bukkit[c][z]/(int)pow((double)10,(double)s))%10);
	bukkit2[re].push_back(bukkit[c][z]);
	}
	bukkit[c].clear(); 
	} else
	{
		for(int c=0;c<10;c++){for(int z=0;z<bukkit2[c].size();z++){
	
	int re=0;
	re=(bukkit2[c][z]/(int)pow((double)10,(double)s)%10);
	bukkit[re].push_back(bukkit2[c][z]);
	}
	bukkit2[c].clear();
	} 
		
		
	}
	/*int num=0;
	for(int i=0;i<10;i++)
	{
		for(int k=0;k<bukkit[i].size();k++)
		{
			data[num]=bukkit[i][k];
		num++	;
		}
		bukkit[i].clear();
	}
	*/
	
}
int num=0;
	for(int i=0;i<10;i++)
	{
		for(int k=0;k<bukkit[i].size();k++)
		{
			data[num]=bukkit[i][k];
		num++	;
		}
		bukkit[i].clear();
	}
b=freopen("基数排序.txt","w",stdout);
for(int a=0;a<data.size();a++)
printf("%d ",data[a]);
fclose(a);
fclose(b); 
}
int longest()
{int max=0;
for(int i=0;i<data.size();i++)
{
int temp=data[i];
	for(int k=1;1;k++)
	{
	if(k>max)
	max=k;
	temp/=10;
	
	if(temp==0)
	break;
		
	}
	
}
	return max;
	
}
