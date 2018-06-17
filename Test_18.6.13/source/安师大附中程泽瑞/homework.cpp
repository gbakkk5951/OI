#include <bits/stdc++.h>
using namespace std;
int ans[100005],tp[100005],len,tlen,sgn;
int main (){
	freopen ("homework.in","r",stdin);
	freopen ("homework.out","w",stdout);
	int n,i,j;
	scanf ("%d",&n);
	if (n<=18)
	{double tp=1.00-1.00/exp(1.0);
	for (int i=1;i<=n;i++)
	{tp=1.00-((double)i)*tp;}
	printf ("%.4lf\n",tp);
	return 0;
	}
	ans[0]=3;ans[1]=5;ans[2]=3;ans[3]=0;ans[4]=9;ans[5]=8;ans[6]=1;ans[7]=9;
	ans[8]=7;ans[9]=2;ans[10]=4;ans[11]=4;ans[12]=7;ans[13]=9;ans[14]=1;
	ans[15]=6;ans[16]=9;ans[17]=5;ans[18]=5;ans[19]=1;len=19;sgn=1;
	for (i=20;i<=n;i++)
	{int jw=0;
	for (j=0;j<=len;j++)
	{ans[j]=ans[j]*i+jw;
	jw=ans[j]/10;ans[j]%=10;
	}
	while (jw) 
	{ans[++len]=jw%10;
	jw/=10;
	}
	sgn*=(-1);
	if (sgn==1)
	{ans[19]++;
	int pos=19;
	while (ans[pos]>=10)
	{ans[pos]-=10;
	ans[++pos]++;
	if (pos>len) {len=pos;}
	}
	}
	else
	{ans[19]--;
	int pos=19;
	while (ans[pos]<0)
	{ans[pos]+=10;
	ans[++pos]--;
	}
	}
	}
	if (ans[14]>=5) {ans[15]++;}
	if (sgn==-1) {printf ("-");}
	for (i=len;i>=19;i--)
	{printf ("%d",ans[i]);}
	printf (".");
	for (i=18;i>=15;i--)
	{printf ("%d",ans[i]);}
	return 0;
}
	
