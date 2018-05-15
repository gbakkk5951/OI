#include<cstdio>
#include<algorithm>
using namespace std;const int N=5010;typedef unsigned long long ll;
ll mp[2][N][N];ll mod[2]={998244353,1e9+7};ll mi[2][N];char mde[N];int n;int res;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%s",mde+1);
	for(n=1;mde[n+1]!='\0';n++);mi[0][0]=mi[1][0]=1;
	for(int i=1;i<=n;i++)
		mi[0][i]=mi[0][i-1]*28%mod[0],
		mi[1][i]=mi[1][i-1]*28%mod[1];
	for(int i=1;i<=n;i++)
		for(int len=1;i+len-1<=n;len++)
		{
			mp[0][i][i+len-1]=(mp[0][i][i+len-2]+mi[0][len-1]*(mde[i+len-1]-'a'+1))%mod[0];
			mp[1][i][i+len-1]=(mp[1][i][i+len-2]+mi[1][len-1]*(mde[i+len-1]-'a'+1))%mod[1];
		}
	for(int i=1;i<=n;i++)
		for(int len=(n-i+1)/2;len>=1;len--)
		{
			if(mp[0][i][i+len-1]*mp[1][i][i+len-1]==mp[0][i+len][i+2*len-1]*mp[1][i+len][i+2*len-1])
			{res=max(res,2*len);}
		}
	printf("%d",res);fclose(stdin);fclose(stdout);return 0;
} 
