#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int head[40010],nxt[80010],whr[80010],val[80010],siz[40010],qson[40010],cnt=1;
int deep[40010],sot[40010],n,k,all,root,ans;
bool vis[40010];
void add(int a,int b,int v){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	val[cnt]=v;
	head[a]=cnt++;
	return;
}
void getroot(int pos,int las){
	siz[pos]=1,qson[pos]=0;
	for(int i=head[pos];i;i=nxt[i]){
		if(whr[i]==las||vis[whr[i]]==false) continue;
		getroot(whr[i],pos);
		siz[pos]+=siz[whr[i]];
		qson[pos]=max(qson[pos],siz[whr[i]]);
	}
	qson[pos]=max(qson[pos],all-siz[pos]);
	if(qson[pos]<qson[root]) root=pos;
	return;
}
void getdeep(int pos,int las){
	sot[++cnt]=deep[pos];
	for(int i=head[pos];i;i=nxt[i]){
		if(whr[i]==las||vis[whr[i]]==false) continue;
		deep[whr[i]]=deep[pos]+val[i];
		getdeep(whr[i],pos);
	}return;
}
int calc(int pos,int chu){
	deep[pos]=chu,cnt=0;
	getdeep(pos,0);
	sort(sot+1,sot+cnt+1);
	int l=1,r=cnt,ret=0;
	while(l<r){
		if(sot[l]+sot[r]<=k) ret+=r-l,l++;
		else r--;
	}return ret;
}
void solve(int pos){
	ans+=calc(pos,0),vis[pos]=false;
	for(int i=head[pos];i;i=nxt[i]){
		if(vis[pos]==false) continue;
		ans-=calc(whr[i],val[i]);
		all=siz[whr[i]];
		root=0;
		getroot(whr[i],0);
		solve(root);
	}
}
int main()
{
	int i,a,b,v;
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d%d%d",&a,&b,&v),add(a,b,v),add(b,a,v);
	memset(vis,true,sizeof(vis));
	qson[root=0]=1061109567,all=n;
	scanf("%d",&k);
	getroot(1,0);
	solve(root);
	printf("%d\n",ans);
	return 0;
}

