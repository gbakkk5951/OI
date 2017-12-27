#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int n,m;
char p[500010];
bitset<600000>get;
bitset<600000>end;
int dp[200010];
bitset<200010> ok;

void insert(char word[10],int len,int fa=0)
{
	int i,j,k,l;
	char temp[4];
	if(len!=1)
	{
	for(i=1;i<len;i++)
	{temp[i-1]=word[i];
	}
	get[fa*27+27] =true;
	insert(temp,len-1,fa*27+27);
	get[fa*27+word[0]-'a'+1] =true;
	insert(temp,len-1,fa*27+word[0]-'a'+1);
	}
	else
	{
		get[fa*27+27] =true;
		get[fa*27+word[0]-'a'+1]=true;
		end[fa*27+27] =true;
		end[fa*27+word[0]-'a'+1] =true;		
	}
	
}




int getmin(char s[10],int len,int data=0,int fa=0)
{
	
	
	int i;
	char temp[4];
	for(i=1;i<len;i++)
	{
		temp[i-1]=s[i];
	}
	if(len!=1)
	{
	int mn=getmin(temp,len-1,data+1,fa*27+27);//走任意字符 
	if(get[fa*27+s[0]-'a'+1])
	mn=min(mn,getmin(temp,len-1,data,fa*27+s[0]-'a'+1));//走本字符 
	
	if(mn>=10)//无解 
	return 10;
	return mn;
	}else
	{
		if(end[fa*27+s[0]-'a'+1])//走本字符 
		return data;
		
		if(end[fa*27+27])//末尾走任意字符 
		return	data+1;
		else return 10;
		
	}
	
	
	
}




int main()
{



int i,j,k,l;
char ct[10];
scanf("%d",&n);
for(i=0;i<n;i++)

{
scanf ("%s",ct);
insert(ct,strlen(ct));
}


scanf("%d",&m);
scanf("%s",p);
char ctemp[4];

for(i=0;i<m;i++)
{
	dp[i]=2147483647;
	for(j=max(i-3,0);j<=i;j++)
	{
	
	for(k=j;k<=i;k++)
	ctemp[k-j]=p[k];//复制字符 
	
	int intemp=getmin(ctemp,i-j+1);
	
	if(intemp<5&&((j-1<0)||ok[j-1]))
	dp[i]=min(dp[i],dp[j-1]+intemp);
	
	}
//	printf("%d=%d;",i,dp[i]); 
	if(dp[i]==2147483647)
	ok[i]=false;
	else 
	{
	
	
	ok[i]=true;
	} 
}

if(!ok[m-1])
printf("No");
else printf("%d",dp[m-1]);
}
