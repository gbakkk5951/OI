#include<bits/stdc++.h>
#define maxn 100010
#define ll long long
using namespace std;

int a[maxn],n,k;
const int INF=1<<30;
set<int> st;
set<int>::iterator it;
void solve(){
	ll ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		st.clear();
		int tmp=INF;
		for(int j=i;j<=n;j++){
			it=st.lower_bound(a[j]);
			if(it!=st.end())
				tmp=min(tmp,*it-a[j]);
			if(it!=st.begin())
				--it,tmp=min(tmp,a[j]-*it);
			st.insert(a[j]);
			if(j-i+1>=k)
				ans=max(ans,1LL*(j-i)*tmp);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	int T;
	for(scanf("%d",&T);T--;solve());
	return 0;
}
