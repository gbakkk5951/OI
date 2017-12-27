#include<cstring>
#include<cstdio>
#include<vector> 
#include<algorithm>
using namespace std;
char a[802],b[802];
int re[5];
int dis[256];
bool read();
void search();
void clear();
int la,lb;
int maxn=0;

struct dp
{int v;
//int a;
int b;
};

vector<dp>data[802];
bool cmp(dp,dp);

int main()
{
int n;
scanf("%s",a);
scanf("%s",b);
scanf("%d",&n);
int i=0,j=0;

for(i=0;i<n;i++)
{
for(j=0;j<256;j++)
dis[j]=802;
while(read());
clear();
search();
re[i]=maxn;
maxn=0;

	
}
for(i=0;i<n;i++)
{
printf("%d ",re[i]);
}

}


bool read()
{char ct;
ct=getchar();

if(ct=='$')
return false;
else if(ct=='\n'||ct=='\r'||ct==' ')
return true;
else if(ct==EOF)
return false;

scanf("%d",&dis[(int)ct]);
return true;
}


void search()
{
int m,n;
la=strlen(a);
lb=strlen(b);
int i,j,l;

for(i=1;i<=la;i++)
{
for(j=1;j<=lb;j++)
{
if(a[i-1]==b[j-1])
{
int max=0;
int now;
vector<dp>::iterator k;


for(l=i-1;l>=i-dis[a[i-1]]-1&&l>=1;l--)
{
for(k=data[l].end() ;k!=data[l].begin() ;)
{
k--;
if((*k).b<j&&(j-dis[b[j-1]]-1)<=(*k).b)
{
	if((*k).v>max)
max=(*k).v;
break;
}}
}



now=max+1;
if(now>maxn)
maxn=now;
dp temp;
temp.v =now;
temp.b=j;
data[i].insert(lower_bound(data[i].begin(),data[i].end(),temp,cmp),temp); 

max=0;
}


}
}}
bool cmp(dp d1,dp d2)
{
return d1.v<d2.v;
}
void clear()
{
	int i=0;
for(i=1;i<=800;i++)
data[i].clear() ;

}
