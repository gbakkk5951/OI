#include<cstdio>
#include<ctime>
using namespace std;
#define maxn 32768 //���ݷ�Χ1~32768
int data[maxn];
int main()
{
FILE *a=freopen("�����.out","r",stdin),*b=freopen("���������.txt","w",stdout);

int i=0,j=0;
int temp;
//��ʼ������
for(j=0;j<maxn;j++)
{data[j]=0;
}
//��������
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
