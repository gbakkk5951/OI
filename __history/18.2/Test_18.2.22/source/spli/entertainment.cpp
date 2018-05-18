#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;

const int N=1005;
int n,m,slee,eat;
int c[2][N];

namespace solve1{
	LL ans=-10000000000000ll;
	void check(int st){
		for(int i=1;i+m-1<=n;++i){
			int num=0;
			for(int j=i;j<i+m;++j)
				if(st&(1<<j>>1)) num++;
			if(num<slee||m-num<eat) return;
		}
		LL ret=0;
		for(int i=1;i<=n;++i){
			if(st&(1<<i>>1)) ret+=c[0][i];
			else ret+=c[1][i];
		}
		ans=max(ans,ret);
	}
	void work(){
		int S=(1<<n)-1;
		for(int i=1;i<=S;++i) check(i);
		cout<<ans;
	}
}

int main(){
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&slee,&eat);
	for(int i=1;i<=n;++i) scanf("%d",&c[0][i]);
	for(int i=1;i<=n;++i) scanf("%d",&c[1][i]);
	if(n<=10) {solve1::work();return 0;}
	LL ans=0;
	for(int i=1;i<=n;++i) ans+=max(c[0][i],c[1][i]);
	cout<<ans;
	return 0;
}

/*
10 4 1 2

1 2 3 4 5 6 7 8 9 10

10 9 8 7 6 5 4 3 2 1
*/
