#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf 1000000000
#define pa pair<int,int>
#define ll long long 
using namespace std;
int n,mx,ans,ansl,ansr;
int bin[30],Log[100005];
int mn[100005][17];
char ch[100005];
void rmq(int mn[100005][17],int *a)
{
	for(int i=1;i<=n;i++)mn[i][0]=a[i];
	for(int i=1;i<=Log[n];i++)
		for(int j=1;j<=n;j++)
			if(j+bin[i]-1<=n)
				mn[j][i]=min(mn[j][i-1],mn[j+bin[i-1]][i-1]);
			else break;
}
struct data{
	int k,p,q;
	int rk[2][100005],sa[2][100005],v[100005],a[100005];
	int h[100005],mn[100005][17];	
	void ini(){
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		memset(rk,0,sizeof(rk));
	}
	void cal(int *sa,int *rk,int *SA,int *RK){
		for(int i=1;i<=n;i++)v[rk[sa[i]]]=i;
		for(int i=n;i;i--)
			if(sa[i]>k)
				SA[v[rk[sa[i]-k]]--]=sa[i]-k;
		for(int i=n-k+1;i<=n;i++)
			SA[v[rk[i]]--]=i;
		for(int i=1;i<=n;i++)
			RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
		
	}
	void getsa(){
		p=0,q=1;
		for(int i=1;i<=n;i++)v[a[i]]++;
		for(int i=1;i<=30;i++)v[i]+=v[i-1];
		for(int i=1;i<=n;i++)
			sa[p][v[a[i]]--]=i;
		for(int i=1;i<=n;i++)
			rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
		for(k=1;k<n;k<<=1,swap(p,q))
			cal(sa[p],rk[p],sa[q],rk[q]);
	}
	void geth(){
		k=0;
		for(int i=1;i<=n;i++)
			if(rk[p][i]==1)h[rk[p][i]]=0;
			else 
			{
				int j=sa[p][rk[p][i]-1];
				while(a[i+k]==a[j+k])k++;
				h[rk[p][i]]=k;if(k>0)k--;
			}
	}
	void pre(){
		getsa();geth();rmq(mn,h);
	}
	int lcp(int x,int y){
		x=rk[p][x],y=rk[p][y];
		if(x>y)swap(x,y);x++;
		int t=Log[y-x+1];
		return min(mn[x][t],mn[y-bin[t]+1][t]);
	}
}c[2];
int query(int x,int y)
{
	int t=Log[y-x+1];
	return min(mn[x][t],mn[y-bin[t]+1][t]);
}
void solve(int L)
{
	int l=0,r=0,t;
	for(int i=1;i+L<=n;i+=L)
		if(ch[i]==ch[i+L])
		{
			r=c[0].lcp(i,i+L),l=c[1].lcp(n-i+2,n-i-L+2);
//			printf("l = %d, r = %d\n", l, r);
			if((l+r)/L+1>mx)
				mx=(l+r)/L+1,ans=inf;
			if((l+r)/L+1==mx)
			{
			    t=query(i-l,i-l+(l+r)%L);
				if(t<ans)
				{  
					ans=t;
					ansl=c[0].sa[c[0].p][t],ansr=ansl+mx*L-1;
//				    printf("rank = %d, i = %d, L = %d, [%d, %d]\n",
//					t, i, L, ansl, ansr);
                }
			}
		}
}
int main()
{
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	Log[0]=-1;for(int i=1;i<=100000;i++)Log[i]=Log[i/2]+1;
	int tst=0;
	while(scanf("%s",ch+1))
	{
		if(ch[1]=='#')break;
		tst++;printf("Case %d: ",tst);
		c[0].ini();c[1].ini();
		n=strlen(ch+1);
		for(int i=1;i<=n;i++)c[0].a[i]=ch[i]-'a'+1;
	    for(int i=1;i<=n;i++)c[1].a[i]=ch[n-i+1]-'a'+1;
		c[0].pre();c[1].pre();
		rmq(mn,c[0].rk[c[0].p]);
		mx=1;ans=inf;
		for(int i=1;i<=n;i++)
			if(c[0].rk[c[0].p][i]<ans)
				ans=c[0].rk[c[0].p][i],ansl=ansr=i;
		for(int i=1;i<=n;i++)solve(i);
		for(int i=ansl;i<=ansr;i++)
			putchar(ch[i]);
		puts("");
	}
	fclose(stdout);
	return 0;
}
