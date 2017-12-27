#include<cstdio>
#include<ctime>
using namespace std;
#define maxn 32768 //数据范围1~32768
int data[maxn];
int main()
{
FILE *a=freopen("随机数.out","r",stdin),*b=freopen("差分珠排序.txt","w",stdout);

int i=0,j=0;
int temp;
//初始化柱子
for(j=0;j<maxn;j++)
{data[j]=0;
}
//读入数据
while(scanf("%d",&temp)!=EOF)
{
	//data[0]++;
	data[temp]--;

}
for(j=1;j<maxn;j++)
{
if(data[j]!=0)
{
for(i=0;i<(-data[j]);i++)
{printf("%d ",j);
}
data[0]+=data[j];

}
}

fclose(a);
fclose(b);
freopen("CON","w",stdout);
printf("%f",(float)clock()/CLOCKS_PER_SEC);

return 0;
}
