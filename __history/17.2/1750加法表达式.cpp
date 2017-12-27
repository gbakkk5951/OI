#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int main()
{
char s[110];
int sum=0;
scanf("%s",s);
int t;
int l,i;
l=strlen(s);
string a=s;
for(i=0;i<l;i++)
{
	if(isdigit(a[i]))
	{
		a=a.substr(i,l-i);
		l=l-i;
		i=0;
		sscanf(a.c_str(),"%d",&t);
	sum+=t;
	if(t<10)
	{l--;
		a=a.substr(1,l);
	}
	else if(t<100)
	{l=l-2;
	a=a.substr(2,l);
	}
	else {l=l-3;
	a=a.substr(3,l);
	}
	t=0;
	}
	
}

sum+=t;	

printf("%s=%d",s,sum);
	
} 
