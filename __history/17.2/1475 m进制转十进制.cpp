#include<cstdio>
#include<cstring>
#include<cctype>
int re;
int po[8];
int main()
{int m;
char n[9];
	scanf("%s%d",&n,&m);
	int i;
	po[0]=1;
	for(i=1;i<8;i++)
	po[i]=po[i-1]*m;
	int l=strlen(n);
	for(i=0;i<l;i++)
	{
	if(isdigit(n[l-i-1]))
	{
		re+=(n[l-i-1]-'0')*po[i];
	}
	else re+=(10+n[l-i-1]-'A')*po[i];
	}
	printf("%d",re);
}

