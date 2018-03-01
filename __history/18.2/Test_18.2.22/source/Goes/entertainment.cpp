#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
inline int read(){
	char ch='*';int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		sum*=10,sum+=ch-'0',ch=getchar();
	return sum;
}
#if 0
Writers: Goes && G.S.M.
Fall asleep
#endif
const int N=1005;
int n,k,ms,me;
int v[2][N],ans;
int done[N],t[2][N];
bool pd(int day){
	if(day>=k){
		if(t[0][day]-t[0][day-k]<ms) return false;
		if(t[1][day]-t[1][day-k]<me) return false;
	}else{
		if(t[0][day]+k-day<ms) return false;
		if(t[1][day]+k-day<me) return false;
	}return true;
}

void dfs(int day,int va){
	if(!pd(day-1)) return ;ans=max(va,ans);
	if(day==n+1) return ;
	t[0][day]=t[0][day-1];t[1][day]=t[1][day-1];
	for(int i=0;i<=1;i++)
	{
		t[i][day]++;
		dfs(day+1,va+v[i][day]);
		t[i][day]--;
	}return ;
}
 
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout); 
	n=read(),k=read(),ms=read(),me=read();
	for(int i=1;i<=n;i++)
		scanf("%d",&v[0][i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[1][i]);
	dfs(1,0);printf("%d",ans);return 0;	
}
/*
10 4 1 2
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
*/
