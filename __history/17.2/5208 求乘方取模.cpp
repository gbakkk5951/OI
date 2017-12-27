#include<stdio.h>
#include<algorithm>
#include<vector>
#define ll unsigned long long
using namespace std;
vector<unsigned long long>r;
unsigned long long b=0;
unsigned long long m=0;
unsigned long long a=0;


ll mul(ll x,ll y)
{
	ll res=0;
	while(x)
	{
	if(x&1)
	{
		res=(res+y%m)%m;
	}
	x>>=1;y<<=1;
	y%=m;
	}
	return res;
}


int main()
{unsigned long long r2[64];
int j=0;
r2[0]=1;
for(j=1;j<64;j++)
r2[j]=(unsigned long long)2*r2[j-1];


while(scanf("%llu %llu %llu",&a,&b,&m)!=EOF)
{

	if(a==0)
	{r.push_back(0%m);
	continue;
	}if(b==0)
	{r.push_back(1%m);
	continue;
	}
unsigned long long sz[64];
int i=0;
unsigned long long save=b;
unsigned long long re=1;
unsigned long long t=a%m;
sz[0]=t;
for(j=1;j<64;j++)
sz[j]=mul(sz[j-1],sz[j-1])%m;

for(i=63;i>=0;i--){
if(save>=r2[i]&&save!=0)
{
//	printf("[s%I64u,sz%I64u,i%d]",save,sz[i],i);
	save-=r2[i];
	re=mul(re,sz[i])%m;
}
	
}

r.push_back(re);
}
int i=0;
	for(i=0;i<r.size();i++)
	printf("%llu\n",r[i]);
}
