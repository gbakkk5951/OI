#include<bits/stdc++.h>
#define maxn 22
#define rep(x,a,b) for(int x=a;x<=b;++x)
using namespace std;

int a[maxn],stk[maxn],gcd[maxn][maxn],n,top,ans=0;
bool vis[maxn];
inline int _gcd(int x,int y){
	if(!x||!y)
		return x|y;
	return x<y?_gcd(x,y%x):_gcd(y,x%y);
}
void dfs(int tmp){
	if(tmp==n){
		top=0;
		for(int i=1;i<=n;i++)
			if(vis[i])
				stk[++top]=a[i];
		if(top==0)
			return;
		if(top==1){
			ans++;
			return;
		}
		for(int i=1;i<=top;i++)
			for(int j=i+1;j<=top;j++)
				if(gcd[stk[i]][stk[j]]!=1)
					return;
		ans++;
		return;
	}
	rep(i,0,1)
		vis[tmp+1]=i,dfs(tmp+1);
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n)
		scanf("%d",&a[i]);
	rep(i,1,maxn-1)
		rep(j,1,maxn-1)
			gcd[i][j]=_gcd(i,j);
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
