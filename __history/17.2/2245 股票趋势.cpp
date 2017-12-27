#include<cstdio>
#include<cstring>
#include<sstream>
#include<string>
#include<cctype>
using namespace std;
string a,b;
int re[5];
int dis[256];
bool read();
void search();
int dp[802][802][802][802];//dp[a][geta][b][getb]



int main()
{
int n;
char temp[802];
fgets(temp,801,stdin);
a=temp;
fgets(temp,801,stdin);
b=temp;
scanf("%d",&n);
int i=0,j=0,k=0;

for(i=0;i<n;i++)
{
for(j=0;j<256;j++)
dis[j]=802;
while(read());
search();


	
}


}


bool read()
{char ct;
ct=getchar();
if(ct=='$')
return false;
else if(ct=='\n'||ct=='\r'||ct==' ')
return true;


scanf(" %d ",&dis[(int)ct]);
return true;
}


void search()
{
int m,n;
la=a.size();
lb=b.size();
int i,j,k,l;
for(i=0;i<la;i++)
{
for(j=0;j<=i;j++)
{
for(k=0;k<lb;k++)
{
for(l=0;l<=k)
{

if(a[l]==a[j] && (l-dis[(int)a[l]]<=m ||dp[i][j][m][n]==-1)&& j-dis[(int)a[l]]<=n )
{


}
else
{
dp[i][j][k][l]=-1000;
}



}






}
}





}





}
