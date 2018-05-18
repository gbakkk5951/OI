#include<bits/stdc++.h>
#define maxn 1000010
#define rep(x,a,b) for(int x=(a),xx=(b);x<=xx;++x)
#define per(x,a,b) for(int x=(a),xx=(b);x>=xx;--x)
using namespace std;

int lg2[maxn],n,m;
char str[maxn];
struct _string{
	int sa[maxn],rk[maxn],h[maxn],sum[maxn],a[maxn],b[maxn];
	int st[maxn][22];
	void getsa(){
		int *r=a,*scd=b;
		rep(i,1,n)
			sum[r[i]=str[i]]++;
		rep(i,1,m)
			sum[i]+=sum[i-1];
		per(i,n,1)
			sa[sum[r[i]]--]=i;
		for(int len=1,cnt=0;cnt<n;len<<=1,m=cnt){
			cnt=0;
			rep(i,n-len+1,n)
				scd[++cnt]=i;
			rep(i,1,n)
				if(sa[i]>len)
					scd[++cnt]=sa[i]-len;
			rep(i,1,m)
				sum[i]=0;
			rep(i,1,n)
				sum[r[scd[i]]]++;
			rep(i,1,m)
				sum[i]+=sum[i-1];
			per(i,n,1)
				sa[sum[r[scd[i]]]--]=scd[i];
			swap(r,scd),cnt=0;
			rep(i,1,n)	
				r[sa[i]]=max(sa[i-1],sa[i])+len<=n&&scd[sa[i-1]]==scd[sa[i]]&&scd[sa[i-1]+len]==scd[sa[i]+len]?cnt:++cnt;
		}
		rep(i,1,n)
			rk[sa[i]]=i;
		for(int i=1,pre;i<=n;i++)
			for(h[i]=max(h[i-1]-1,0),pre=sa[rk[i]-1];max(i,pre)+h[i]<=n&&str[i+h[i]]==str[pre+h[i]];h[i]++);
		rep(i,1,n)
			st[i][0]=h[sa[i]];
		rep(i,2,n)
			lg2[i]=lg2[i>>1]+1;
		rep(j,1,lg2[n])
			rep(i,1,n)
				st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	}
}s[2];

inline int Min(int x,int y,int tp){
	x=s[tp].rk[x],y=s[tp].rk[y];
	if(x>y)
		swap(x,y);
	x++;
	int len=lg2[y-x+1];
	return min(s[tp].st[x][len],s[tp].st[y-(1<<len)+1][len]);
}
inline int lcp(int x,int y){
	if(x==y)
		return n-x+1;
	return Min(x,y,0);
}
inline int lcs(int x,int y){
	if(x==y)
		return x;
	return Min(n+1-x,n+1-y,1);
}
bool check(int x){
	for(int i=1;i<=n;i+=x){
		if(i+x<=n){
			int _lcp=lcp(i,i+x),_lcs=lcs(i,i+x);
			if(_lcp+_lcs-1>=x)
				return true;
		}
	}
	return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%s",str+1),n=strlen(str+1),m=127;
	s[0].getsa(),reverse(str+1,str+n+1),s[1].getsa(),reverse(str+1,str+n+1);
	per(i,n,1)
		if(check(i))
			return printf("%d\n",i<<1),0;
	puts("0");
	return 0;
}
