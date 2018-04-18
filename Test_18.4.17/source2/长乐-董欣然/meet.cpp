#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
using namespace std;
typedef long long ll;
int n,q,u1,v1,t1,u2,v2,t2,q1,tot;
int lx[100005],ly[100005],lz[100005],que[100005],sum[100005],a[100005],du[100005];
int nxt[200005],poi[100005],end[200005],len[200005];
ll g[105][105];
void add(int x,int y,int w)
{
	nxt[++tot]=poi[x];
	poi[x]=tot;
	end[tot]=y;
	len[tot]=w;
}
void folyed()
{
	for (int k=1; k<=n; ++k)
	  for (int i=1; i<=n; ++i)
	    for (int j=1; j<=n; ++j)
	      g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
int work()
{
	for (int i=1; i<n; ++i){
		int x=lx[i], y=ly[i], w=lz[i];
		if (g[u1][x]+g[x][v1]==g[u1][v1] && g[u1][y]+g[y][v1]==g[u1][v1]
		 && g[u2][x]+g[x][v2]==g[u2][v2] && g[u2][y]+g[y][v2]==g[u2][v2]);
		 else continue;
		ll mn1=min(g[u1][x],g[u1][y])+t1;
		ll mn2=min(g[u2][x],g[u2][y])+t2;
	//	if (x==1 && y==2) printf("%I64d %I64d\n",mn1,mn2);
		if (abs(mn1-mn2)<w) return 1;
	}
	return 0;
}
void work1()
{
	for (int i=1; i<n; ++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);	
		g[x][y]=g[y][x]=z;
		lx[i]=x, ly[i]=y, lz[i]=z;
	}
	for (int i=1; i<=n; ++i) g[i][i]=0;
	folyed();
	while (q--){
		scanf("%d%d%d%d%d%d",&u1,&v1,&t1,&u2,&v2,&t2);
		if (work()) printf("YES\n");
		else printf("NO\n");
	}
}
void dfs(int x,int la,int w)
{
	que[++q1]=x;
	sum[q1]=w;
	for (int i=poi[x],y; y=end[i],i; i=nxt[i])
	if (y!=la) {		
		dfs(y,x,len[i]);
	}
}
int check()
{
	int s1=a[u1], d1=a[v1], s2=a[u2], d2=a[v2];
//	
	if (max(s1,d1)<min(s2,d2) || min(s1,d1)>max(s2,d2)) return 0;
	int L=max(min(s1,d1),min(s2,d2)), R=min(max(s1,d1),max(s2,d2));
	int l1,l2,r1,r2;
//	printf("%d\n",(s1<d1)^(s2<d2));
	if ((s1<d1)^(s2<d2)){
		if (s1<d1){
		//	printf("ru");
			r1=sum[R]-sum[s1]+t1;
			l1=sum[L]-sum[s1]+t1;
			l2=sum[s2]-sum[R]+t2;
			r2=sum[s2]-sum[L]+t2;
		//	printf("%d %d %d %d\n",l1,r1,l2,r2);
			if (r2<=l1 || r1<=l2) return 0;
			return 1;
		}
		r2=sum[R]-sum[s2]+t2;
		l2=sum[L]-sum[s2]+t2;
		l1=sum[s1]-sum[R]+t1;
		r1=sum[s1]-sum[L]+t1;
		if (r2<=l1 || r1<=l2) return 0;
		return 1;
	}
	int cha=abs(t2-t1+s1-s2);
	for (int i=L+1; i<=R; ++i)
	if (sum[i]-sum[i-1]>cha) return 1;
	return 0;
}
void work2()
{
	for (int i=1; i<=n; ++i)
	if (du[i]==1) {
		dfs(i,0,0); break;
	}
	for (int i=1; i<=n; ++i){
		a[que[i]]=i;
		sum[i]+=sum[i-1];
	}
	while (q--){
		scanf("%d%d%d%d%d%d",&u1,&v1,&t1,&u2,&v2,&t2);
		if (check()) printf("YES\n");
		else printf("NO\n");
	}
}
int main()
{
	freopen("meet.in","r",stdin);
	freopen("meet.out","w",stdout);
	memset(g,63,sizeof(g));
	scanf("%d%d",&n,&q);
	if (n<=100){
		work1(); return 0;
	}
	for (int i=1; i<n; ++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);	
		du[x]++; du[y]++;
	}
	int cnt=0;
	for (int i=1; i<=n; ++i)
		if (du[i]==1) ++cnt;
	//if (cnt==2){
		 work2(); return 0;
//	}
}
