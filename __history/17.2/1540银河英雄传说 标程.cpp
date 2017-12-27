#include<stdio.h>
#include<algorithm>
using namespace std;
int headfa[30010],tailfa[30010],len[30010],sum[30010],lenth;
int findh(int on)
{
	if(headfa[on]==on)
	{
		lenth=0;
		return on;
	}
	headfa[on]=findh(headfa[on]);
	lenth+=len[on];
	len[on]=lenth;
	return headfa[on];
}
int findt(int on)
{
    return tailfa[on]==on?on:tailfa[on]=findt(tailfa[on]);
}
int find(int on)
{
	return headfa[on]==on?on:find(headfa[on]);
}
void merge(int x,int y)
{
	findh(findt(y));
	findh(findt(x));
    len[findh(x)]=len[findt(y)]+1;
    headfa[find(x)]=findh(y);
    tailfa[findt(y)]=findt(x);
}
int dis(int x,int y)
{
    return abs(len[x]-len[y])-1;
}
int main()
{
    int i,j,x,y,t;
    char s[3];
    for(i=0;i<30010;i++)
    {
        headfa[i]=tailfa[i]=i;
        len[i]=0;
    }
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='M')
        {
            merge(x,y);
            findh(findt(x));
        }
        else
        {
            if(findh(x)!=findh(y))
                printf("-1\n");
            else
                printf("%d\n",dis(x,y));
        }
    }
    return 0;
}
