#include<cstdio>
#include<cstring>
//#include<sstream>
//#include<string>
//#include<cctype>
using namespace std;
char a[802],b[802];
int re[5];
int dis[256];
bool read();
void search();
void clear();
//void getin();
int dp[802][802];//dp[geta][getb]
int la,lb;

int maxn=0;
int main()
{
int n;
//getin();
/*char temp[802];
//fgets(temp,801,stdin);
a=temp;
fgets(temp,801,stdin);
b=temp;
*/
scanf("%s",a);

scanf("%s",b);
scanf("%d",&n);
//printf("[[[%d]]]\n",n);
int i=0,j=0,k=0;

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




int i,j,k,l;


for(i=1;i<=la;i++)
{
for(j=1;j<=lb;j++)
{
if(a[i-1]==b[j-1]&&a[i-1]!=' '&&a[i-1]!='\n'&&a[i-1]!='\0'&&a[i-1]!='\r')
{
int max=0;
for(k=1;k<=dis[(int)a[i-1]]+1&&k<i;k++)
for(l=1;l<=dis[(int)b[j-1]]+1&&l<j;l++)
{
if(dp[i-k][j-l]>max)
max=dp[i-k][j-l];

}

dp[i][j]=max+1;
if(dp[i][j]>maxn)
maxn=dp[i][j];
max=0;
}else dp[i][j]=0;
if(dp[i][j]!=0)
printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);


}
}
// ‰≥ˆæ‡¿Î±Ì 
/*for(i=0;i<256;i++)
if(dis[i]!=802)
printf("dis[%d](%c)=%d ",i,(char)i,dis[i]); 
*/
}

void clear()
{int i=0;
for(i=0;i<=801;i++)
{
dp[0][i]=0;
}
for(i=0;i<=801;i++)
{
dp[i][0]=0;
}


}
/*
bool f=false;
void getin()
{
if(!f)
{char temp;
int i,j;
while(1)
{
temp=getchar();
if(temp=='\n'||temp=='\r')
break;
if(temp==' '){ 
getchar();break;}
a.push_back(temp) ;

} 
f=true;
getin();
}else
{
char temp;
	int i,j;
while(1)
{
temp=getchar();
if(temp=='\r'||temp=='\n')
break;
if(temp==' '){ 
/*getchar();*//*break;}
b.push_back(temp) ;

} 

}


}*/
