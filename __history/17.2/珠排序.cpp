#include<cstdio>
#include<vector>
#include<ctime> 
using namespace std;
vector<int> line;
vector<int> a;
vector<int> result;
int main()
{
	int t;
	FILE *b,*c;
	b=freopen("随机数.out","r",stdin);
	c=freopen("珠排序结果.txt","w",stdout);
	while(1)
	{
		if(scanf("%d",&t)!=EOF)
		a.push_back(t); 
		else break;
	}
	result.resize(a.size());
	for(int i=0;i<a.size();i++)
	{
	if(a[i]>line.size())	
		line.resize(a[i]);
	for(int j=0;j<a[i];j++){
	
	line[j]++;
    result[line[j]-1]++;
	}}
	int temp=0;
	for(int i=0;i<a.size() ;i++){
	

printf("%d ",result[i]);
temp=0;
}
fclose(b);
fclose(c);
b=freopen("珠排序时间.txt","w",stdout);
printf("%f",(float)clock()/CLOCKS_PER_SEC);
fclose(b);
}
