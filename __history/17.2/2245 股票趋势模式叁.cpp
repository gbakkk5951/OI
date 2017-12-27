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

int data[802][802];
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



for(k=data.end() ;k!=data.begin() ;)
{
k--;
if((*k).a<i&&(*k).b<j&&(i-dis[a[i-1]]-1)<=(*k).a&&(j-dis[b[j-1]]-1)<=(*k).b)
{max=(*k).v;
break;
}}




now=max+1;
if(now>maxn)
maxn=now;
dp temp;
temp.v =now;
temp.a=i;
temp.b=j;
data.insert(lower_bound(data.begin(),data.end(),temp,cmp),temp); 

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
data.clear() ;

}
