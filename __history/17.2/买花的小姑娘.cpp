#include<cstdio>
using namespace std; 
int n;
int hash[100000003];
int m=100000003;
int m2=100000000;
int list[100000003];
int li=0;
long long mo=1000000007;
long long re=1;

void insert(int);int h(int k,int i);int h2(int k);int h1(int k);

int main()
{

	freopen("Flower.in","r",stdin);
	freopen("Flower.out","w",stdout);
    for(int i=0;i<m;i++)
    {
    hash[i]=-2147483648;
	}
	scanf("%d",&n);
    int i=0;

    int temp;
	for(i=0;i<n;i++)
    {scanf("%d",&temp);
    insert(temp);
	}
	
	for(i=0;i<li;i++)
	{
		re=(re*hash[list[i]]%mo)%mo;
		
	}
	
	printf("%d\n%lld",li,re);
	
}
void insert(int x)
{int i=0;
int temp;
int t;
do{
	t=h(x,i);
temp=hash[t];
i++;
if(temp==x)
return;
if(temp==-2147483648)
{
hash[t]=x;
list[li]=t;
li++;

break;
}

}
while(1);	
	
}
int h(int k,int i)
{
return (h1(k)+i*h2(k))%m;
}
int h2(int k)
{return k%m;
}

int h1(int k) 
 {return (k%m2+1);
 }
