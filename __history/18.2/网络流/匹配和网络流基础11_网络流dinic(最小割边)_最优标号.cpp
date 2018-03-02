#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int head[510],nxt[6010],whr[6010],val[6010],in[510],cnt=2,n,aa[3010],bb[3010],vv[510],ans[510],ceng[510];
int c,inf=2147483647,vis[510];
queue<int> q;
void add(int a,int b,int v){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	val[cnt]=1;
	head[a]=cnt++;
	nxt[cnt]=head[b];
	whr[cnt]=a;
	if(v==1) val[cnt]=1;
	else val[cnt]=0;
	head[b]=cnt++;
	return;
}
int dfs(int pos,int liu){
	if(pos==n+1) return liu;
	long long tmp,ret=0;
	for(int i=head[pos];i;i=nxt[i]){
		int t=whr[i];
		if(ceng[t]==ceng[pos]+1&&val[i]>0){
			tmp=dfs(t,min(liu,val[i]));
			if(tmp){
				liu-=tmp;
				ret+=tmp;
				val[i]-=tmp;
				val[i^1]+=tmp;
			}
			else ceng[t]=-1;
			if(liu==0) break;
		}
	}
	return ret;
}
void dfs2(int pos){
	vis[pos]=1;
	for(int i=head[pos];i;i=nxt[i]) if(val[i]>0&&vis[whr[i]]==0) dfs2(whr[i]);
	return;
}
int main()
{
	int m,k,i,j,t;
	memset(vv,-1,sizeof(vv));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d%d",&aa[i],&bb[i]);
	scanf("%d",&k);
	for(i=1;i<=k;i++){
		scanf("%d",&t);
		scanf("%d",&vv[t]);
	}
	for(i=1;i<=n;i++) if(vv[i]!=-1) ans[i]=vv[i];
	for(j=0;j<=31;j++){
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		memset(in,0,sizeof(in));
		cnt=2;
		for(i=1;i<=n;i++) if(vv[i]!=-1) in[i]=vv[i]&(1<<j),in[i]>>=j;
		for(i=1;i<=m;i++){
			if(vv[aa[i]]!=-1&&vv[bb[i]]!=-1) continue;
			if(vv[aa[i]]==-1&&vv[bb[i]]==-1) add(aa[i],bb[i],1);
			else{
				if(vv[aa[i]]==-1) swap(aa[i],bb[i]);
				if(in[aa[i]]==1) add(0,bb[i],0);
				else add(bb[i],n+1,0);
			}
		}
		do{
			memset(ceng,0,sizeof(ceng));
			ceng[0]=1;
			q.push(0);
			while(!q.empty()){
				t=q.front();
				q.pop();
				for(i=head[t];i;i=nxt[i]){
					if(val[i]>0&&ceng[whr[i]]==0){
						ceng[whr[i]]=ceng[t]+1;
						q.push(whr[i]);
					}
				}
			}
			if(ceng[n+1]==0) break;
			c=dfs(0,inf);
		}while(c);
		memset(vis,0,sizeof(vis));
		dfs2(0);
		for(i=1;i<=n;i++) if(vv[i]==-1) ans[i]^=(vis[i]<<j);
	}
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
