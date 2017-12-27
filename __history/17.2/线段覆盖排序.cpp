#include<cstdio>
#include<ctime>
using namespace std;
int data[32768];
int main()
{
FILE *a=freopen("Ëæ»úÊı.out","r",stdin),*b=freopen("²î·ÖÖéÅÅĞò.txt","w",stdout);

int i=0,j=0;
int temp;
for(j=0;j<32768;j++)
{data[j]=0;
}
while(scanf("%d",&temp)!=EOF)
{
	data[0]++;
	data[temp]--;

}
for(j=1;j<32768;j++)
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
