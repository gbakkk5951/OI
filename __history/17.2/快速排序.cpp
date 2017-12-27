#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime> 
using namespace std;
vector<int> save;
int main()
{
	int n;
	FILE *a=freopen("随机数.out","r",stdin);
	FILE *b=freopen("快速排序结果.txt","w",stdout);

int t=0;
while(1)
  if(scanf("%d",&t)!=EOF){
  save.push_back(t); 
  }else break;
  
sort(save.begin(),save.end() );
for(int i=0;i<save.size() ;i++)
printf("%d ",save[i]);
fclose(a);
fclose(b);
freopen("CON","w",stdout);
	printf("%f",(float)clock()/CLOCKS_PER_SEC);
 } 
