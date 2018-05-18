#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;typedef long long ll;
int n;int st;int ret;int res;int lst;const ll mod=1e9+7;
priority_queue <int ,vector <int> ,greater <int> > pq1;
priority_queue <int> pq2;
inline int nxt()
{return (1714636915LL*(ll)lst%mod+1681692777LL)*(846930886LL*(ll)ret%mod+1804289383LL)%mod;}
int main()
{
	freopen("mid.in","r",stdin);
	freopen("mid.out","w",stdout);
	scanf("%d%d",&n,&ret);lst=res=ret;
	for(int i=1;i<n;i++)
	{
		lst=nxt();
		if(lst>ret){pq1.push(lst);pq2.push(ret);}
		else {pq1.push(ret);pq2.push(lst);}
		if(i%2){ret=pq2.top();pq2.pop();}
		else {ret=pq1.top();pq1.pop();}
		res^=ret;
	}printf("%d",res);fclose(stdin);fclose(stdout);
}


