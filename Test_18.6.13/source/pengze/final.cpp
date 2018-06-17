#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define si scanf
#define so printf
#define N 20
#define M 
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
struct opr
{
	int t;//0是交换，1是乘-1
	int a,b;
	opr(int type=0,int aa=0,int bb=0)
	{
		t=type;
		a=aa,b=bb;
	}
};
opr stk[10];
int tp;

int n,pa,pb;
long long A,B,C;
long long h[N][N];
inline void print()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			so("%lld",h[i][j]);
			if(j!=n)
				so(" ");
		}
		if(i!=n)
			so("\n");
	}
}
inline long long ab(long long x)
{
	if(x>=0)	return x;
	return -x;
}
long long gcd(long long a,long long b)
{
	a=ab(a),b=ab(b);
	if(b==0)
		return a;
	return gcd(b,a%b);
}
long long det=1;
void exgcd(long long a,long long b,long long& x,long long& y)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	long long x0,y0;
	exgcd(b,a%b,x0,y0);
	x=y0,y=x0-(a/b)*y0;
}
inline void ExGCD(long long a,long long b,long long c,long long& x,long long& y)
{
	exgcd(a,b,x,y);
	x*=c,y*=c;
	long long t=x/b;
	x=x-t*b,y=y+t*a;
	if(x>=0)
		x-=b,y+=a;
	else
		x+=b,y-=a;
}
int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	rd(n);
	for(int j=1;j<=n;++j)
		rd(h[1][j]);
	if(n==2)
	{
		for(h[2][1]=-2000;h[2][1]<=2000;++h[2][1])
		for(h[2][2]=-2000;h[2][2]<=2000;++h[2][2])
			if(h[1][1]*h[2][2]-h[1][2]*h[2][1]==1)
			{
				print();
				return 0;
			}
		so("no solution\n");
		return 0;
	}
	bool ok=0;
	for(int i=1;i<=n&&!ok;++i)
	for(int j=i+1;j<=n&&!ok;++j)
		if(gcd(h[1][i],h[1][j])==1)
		{
			ok=1;
			pa=i,pb=j;
			if(h[1][i]>0)
			{
				det*=-1;
				h[1][i]*=-1;
				stk[++tp]=opr(1,i);
			}
			if(h[1][j]>0)
			{
				det*=-1;
				h[1][j]*=-1;
				stk[++tp]=opr(1,j);
			}
			if(i==1)
			{
				det*=-1;
				for(int k=1;k<=n;++k)
					if(k!=i&&k!=j)
					{
						swap(h[1][i],h[1][k]);
						stk[++tp]=opr(0,i,k);
						pa=k;
						break;
					}
			}
		}
	if(det==-1)
	{
		det=1;
		swap(h[1][pa],h[1][pb]);
		stk[++tp]=opr(0,pa,pb);
	}
	for(int i=2;i<=n;++i)
		h[i][i]=1;
	A=-h[1][pa],B=-h[1][pb],C=1-h[1][1];
	long long x0,y0;
	ExGCD(A,B,C,x0,y0);
	h[pa][1]=x0,h[pb][1]=y0;
	while(tp)
	{
		if(stk[tp].t==0)
		{
			for(int i=1;i<=n;++i)
				swap(h[i][stk[tp].a],h[i][stk[tp].b]);
		}
		else
		{
			for(int i=1;i<=n;++i)
				h[i][stk[tp].a]*=-1;
		}
		--tp;
	}
	print();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
