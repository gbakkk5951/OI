#include<bits/stdc++.h>
#define maxn 200010
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(x,a,b) for(int x=a;x<=b;++x)
using namespace std;

int A[maxn],B[maxn],aim[maxn],cnt=0,n;
struct data{
	int x,am;
	data(int _x=0,int _am=0){
		x=_x,am=_am;
	}
	friend bool operator <(const data &a,const data &b){
		return abs(a.x-a.am)>abs(b.x-b.am);
	}
};
data pos[maxn];
priority_queue<data> q;
int main(){
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	int x;
	scanf("%d",&n);
	rep(i,1,n)
		scanf("%d",&x),A[x]=i;
	rep(i,1,n)
		scanf("%d",&x),B[x]=i;
	rep(i,1,n)	
		aim[A[i]]=B[i],q.push(data(A[i],B[i]));
	while(!q.empty()){
		data t=q.top();
		q.pop();
		if(aim[t.x]!=t.am)
			continue;
		if(t.x==t.am)
			continue;
		pos[++cnt]=data(t.x,aim[t.x]);
		aim[t.x]=aim[t.am],aim[t.am]=t.am;
		q.push(data(t.x,aim[t.x]));
	}
	printf("%d\n",cnt);
	rep(i,1,cnt)
		printf("%d %d\n",pos[i].x,pos[i].am);
	return 0;
}
