#include<stdio.h>
#define abs(a) ((a)<0?-(a):(a))
int h[10][10],seq1[10],seq2[10];
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	bool flag;
	int i1,i2,j1,j2,n,s,s1,s2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[1][i]);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n;j++)
			h[i][j]=0;
	flag=true;
	while(flag)
	{
		i1=1,i2=2;
		for(i1=1;i1<n&&flag;i1++)
			for(i2=i1+1;i2<=n&&flag;i2++)
				if(gcd(abs(h[1][i1]),abs(h[1][i2]))==1)
					flag=false;
		if(i1==n&&flag)
		{
			printf("no solution");
			return 0;
		}
		i1--,i2--;
		for(j1=-2000;j1<=2000;j1++)
			if((h[1][i1]*j1-1)%abs(h[1][i2])==0&&abs((h[1][i1]*j1-1)/abs(h[1][i2]))<=2000)
				break;
		if(j1==2001)
			flag=true;
	}
	j2=(h[1][i1]*j1-1)/abs(h[1][i2]);
	if(h[1][i1]*j1-h[1][i2]*j2==1)
		j2=-j2;
	seq1[1]=i1,seq2[1]=i2;
	s=0;
	for(int i=2;i+1<=n;i++)
	{
		for(++s;s==i1||s==i2;s++);
		seq1[i]=seq2[i]=s;
		h[i][s]=1;
	}
	seq1[n]=i2,seq2[n]=i1;
	s1=s2=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(seq1[i]>seq1[j])
				s1++;
			if(seq2[i]>seq2[j])
				s2++;
		}
	if(s1%2==1)
		h[n][i1]=j2;
	else
		h[n][i1]=-j2;
	if(s2%2==1)
		h[n][i2]=j1;
	else
		h[n][i2]=-j1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",h[i][j]);
		printf("\n");
	}
	return 0;
}

