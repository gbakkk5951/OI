#include<cstdio>
#include<algorithm>
using namespace std;
int m,n;
long long mo=1000000007;
long long re=1;
long long p[1000001];//从1开始计数； 
int main()
{
FILE *a=	freopen("Angry.in","r",stdin);
FILE *b=	freopen("Angry.out","w",stdout);

scanf("%d%d",&n,&m);
int i,j,k,l;
for(l=1;l<=m;l++){
p[l]=1;
	
}
for(i=0;i<n;i++)
{
int temp,tl,tr;
scanf("%d",&temp);
for(j=0;j<temp;j++)
{
scanf("%d%d",&tl,&tr);	
for(k=tl;k<=tr;k++)
{
p[k]+=1;	
	
}
	
}
}
for(i=1;i<=m;i++)
{
	re=(re*(p[i]%mo))%mo;
	
}
printf("%lld",re);
fclose(a);
fclose(b);
return 0;
}
