#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt,tot;
vector < pair < int,int > >from,to;
int book[105],e[105][105],num[105];
int match[105],id[105][105];
bitset <105> vist;
bool dfs(int x){
	for(int y=0;y<cnt;++y)
		if(!book[y]&&e[x][y]&&!vist.test(y)){
			vist.set(y);
			if(match[y]==-1||dfs(match[y])){
				match[y]=x;
				return 1;
			}
		} 
	return 0;
}
int solve(){
	int ans=0;
	cnt=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<num[i];++j)
			id[i][j]=cnt++;
	for(int i=0;i < from.size();++i){
		e[id[from[i].first][from[i].second]][id[to[i].first][to[i].second]]=1;
		e[id[to[i].first][to[i].second]][id[from[i].first][from[i].second]]=1;
	}
	if((n&1)==0){
		ans=cnt;
		memset(match,-1,sizeof(match));
		for(int i=0;i<n;++i)
			if(i&1)
				for(int j=0;j<num[i];++j){
					vist.reset();
					if(dfs(id[i][j]))ans--;
				}
	}
	else{
		int cen,ncnt;
		for(int i=0;i<n;++i)
			if(num[i]<=10){cen=i;break;}
		for(int i=0;i<1<<num[cen];++i){
			int ok=1;
			for(int j=0;j<num[cen];++j)
				if(i&(1<<j))
					for(int k=j+1;k<num[cen];++k)
						if(i&(1<<k))
							if(e[id[cen][j]][id[cen][k]]){
								ok=0;
								goto enf;
							} 
enf:;
			if(ok){
				ncnt=0;
				for(int j=0;j<num[cen];++j)
					if(i&(1<<j))ncnt++;
				memset(book,0,sizeof(book));
				for(int j=0;j<num[cen];++j){
					book[id[cen][j]]=1;
					if(i&(1<<j)){
						for(int k=0;k<cnt;++k)
							if(e[id[cen][j]][k])book[k]=1;
					} 
				}
				int v=0,m=0;
				for(int j=0;j<cnt;++j)
					if(!book[j])v++;
				memset(match,-1,sizeof(match));
				for(int j=0;j<cnt;++j)
					if(!book[j]){
						vist.reset();
						if(dfs(j))m++;
					}
				ans=max(ans,ncnt+v-m/2);
			}
		}
	}
	return ans;
}
int main(){
	freopen("guard.in","r",stdin);
//	freopen("guard.out","w",stdout);
	scanf("%d",&n);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		from.push_back(make_pair(c-1,a-1));
        to.push_back(make_pair(c%n,b-1));
		num[c-1]=max(num[c-1],a);
		num[c%n]=max(num[c%n],b);
	}
	printf("%d\n",solve());
	return 0;
}
