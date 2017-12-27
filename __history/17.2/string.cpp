#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char ca[1000010],cb[1000010];
int zmax;
int next[2000020];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	

scanf("%s%s",ca,cb);
string a=ca;string b=cb;string t=a+"2"+b;





int k=0;
int i=0,j=strlen(ca)+1;
next[1]=0;
for(;j<t.length();j++)
{
	while(k!=0&&t[k]!=t[j])
	k=next[k];
	if(t[k]==t[j])
	k++;

	next[j+1]=k;
}

zmax=k;
t=b+"2"+a;
k=0;
j=strlen(cb)+1;
next[1]=0;
for(;j<t.length();j++)
{
	while(k!=0&&t[k]!=t[j])
	k=next[k];
	if(t[k]==t[j])
	k++;

	next[j+1]=k;
}
if(k>zmax)
printf("%d",k);
else printf("%d",zmax);
fclose(stdout);
fclose(stdin);
	
}
