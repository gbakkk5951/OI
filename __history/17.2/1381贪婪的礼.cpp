#include<cstdio>
#include<string>
using namespace std;
string name[10];
int money[10];
int n,m;
int findpo(string na)
{int i=0;
	for(i=0;i<n;i++)
	{if(name[i]==na)
	return i;
	}
}
	
int main()
{
	char t[16];
string tm;
	scanf("%d",&n);
	int i=0;int j=0;int k=0;
	for(i=0;i<n;i++)
    {
    	scanf("%s",t);
    	name[i]=t;
	}
	for(i=0;i<n;i++)
{
	int po;
	scanf("%s",t);
	tm=t;
	po=findpo(tm);
	int mo,nu;
	scanf("%d%d",&mo,&nu);
	if(nu!=0)
	money[po]=money[po]-((mo/nu)*nu);
	
	for(j=0;j<nu;j++)
	{scanf("%s",t);
	tm=t;
	po=findpo(tm);
	money[po]+=mo/nu;
	}
	
	
}
for(i=0;i<n;i++)
{printf("%s %d\n",name[i].data(),money[i]);
}
	
}
