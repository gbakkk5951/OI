#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int head[100010],nxt[200010],whr[200010],du[100010],id[100010],siz[100010],fan[100010],cnt=1,intf=1061109567;
long long val[200010],ll[100010],rr[100010],xiao[100010],inf=2305843009213693952ll,ans=0ll;
int rong[100010],shang[100010],son[100010],xia[100010][2],n,m,root;
void add(int a,int b,int v){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	val[cnt]=v;
	head[a]=cnt++;
	return;
}
void dfs1(int pos,int las){
	siz[pos]=1;
	for(int i=head[pos];i;i=nxt[i]){
		if(whr[i]==las) continue;
		dfs1(whr[i],pos);
		siz[pos]+=siz[whr[i]];
	}return;
}
void dfs2(int pos,int las){
	siz[pos]=1;
	for(int i=head[pos];i;i=nxt[i]){
		if(whr[i]==las) continue;
		dfs2(whr[i],pos);
		siz[pos]+=siz[whr[i]];
	}return;
}
void dfs3(int pos,int las,int now){
	int i,j=0,son[2]={0,0};id[now]=pos;long long fzv[2];
	for(i=head[pos];i;i=nxt[i]) if(whr[i]!=las) son[j]=whr[i],fzv[j++]=val[i];
	if(siz[son[0]]<siz[son[1]]) swap(son[0],son[1]);
	if(son[0]) dfs3(son[0],pos,now*2),ll[now]=fzv[0];
	if(son[1]) dfs3(son[1],pos,now*2+1),rr[now]=fzv[1];
	return;
}
void dfs4(int pos){
	int lson=pos*2,rson=pos*2+1;
	xiao[pos]=inf,son[pos]=-1;
	if(rong[pos]) xiao[pos]=0ll,son[pos]=pos;
	if(lson<=n){
		dfs4(lson);
		if(xiao[lson]+ll[pos]<xiao[pos]){
			xiao[pos]=xiao[lson]+ll[pos];
			son[pos]=son[lson];
		}
	}
	if(rson<=n){
		dfs4(rson);
		if(xiao[rson]+rr[pos]<xiao[pos]){
			xiao[pos]=xiao[rson]+rr[pos];
			son[pos]=son[rson];
		}
	}
	return;
}
int find(int pos){
	int ret,las;long long imin=inf,stp=0ll;
	while(pos){
		if(xiao[pos]+stp<imin){
			imin=xiao[pos]+stp;
			ret=pos;
		}
		las=pos;pos=pos/2;
		if(pos*2==las){
			if(shang[las]) stp-=ll[pos]+ll[pos];
			stp+=ll[pos];
		}
		else{
			if(shang[las]) stp-=rr[pos]+rr[pos];
			stp+=rr[pos];
		}
	}
	ans+=imin;
	return ret;
}
void xiangshang(int a,int b){
	while(a!=b){
		if(shang[a]) shang[a]--;
		else if(a==a/2*2) xia[a/2][0]++;
		else xia[a/2][1]++;
		a/=2;
	}return;
}
void xiangxia(int a,int b){
	while(a!=b){
		if(a==a/2*2){
			if(xia[a/2][0]) xia[a/2][0]--;
			else shang[a]++;
		}
		else{
			if(xia[a/2][1]) xia[a/2][1]--;
			else shang[a]++;
		}
		a/=2;
	}return;
}
void update(int pos){
	xiao[pos]=inf,son[pos]=-1;
	int lson=pos*2,rson=pos*2+1;
	if(rong[pos]) xiao[pos]=0ll,son[pos]=pos;
	else{
		if(lson<=n){
			if(xiao[lson]+(xia[pos][0]?-ll[pos]:ll[pos])<xiao[pos]){
				xiao[pos]=xiao[lson]+(xia[pos][0]?-ll[pos]:ll[pos]);
				son[pos]=son[lson];
			}
		}
		if(rson<=n){
			if(xiao[rson]+(xia[pos][1]?-rr[pos]:rr[pos])<xiao[pos]){
				xiao[pos]=xiao[rson]+(xia[pos][1]?-rr[pos]:rr[pos]);
				son[pos]=son[rson];
			}
		}
	}
	pos/=2;
	while(pos){
		lson=pos*2,rson=pos*2+1;
		xiao[pos]=inf,son[pos]=-1;
		if(rong[pos]) xiao[pos]=0,son[pos]=pos;
		else{
			if(lson<=n){
				if(xiao[lson]+(xia[pos][0]?-ll[pos]:ll[pos])<xiao[pos]){
					xiao[pos]=xiao[lson]+(xia[pos][0]?-ll[pos]:ll[pos]);
					son[pos]=son[lson];
				}
			}
			if(rson<=n){
				if(xiao[rson]+(xia[pos][1]?-rr[pos]:rr[pos])<xiao[pos]){
					xiao[pos]=xiao[rson]+(xia[pos][1]?-rr[pos]:rr[pos]);
					son[pos]=son[rson];
				}
			}
		}pos/=2;
	}return;
}
int main()
{
	int t,i,a,b,c,st,chu,pos,cha=intf;
	scanf("%d%d%d",&t,&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c),add(b,a,c);
		du[a]++,du[b]++;
	}
	if(n==1){for(i=1;i<=m;i++) printf("0 ");return 0;}
	if(n==2) id[1]=1,id[2]=2,root=1;
	else{
		dfs1(1,0);
		if(du[1]==2) root=1,cha=abs(siz[whr[head[1]]]-siz[whr[nxt[head[1]]]]);
		for(i=2;i<=n;i++) if(du[i]==2&&cha>abs(n-siz[i]-(siz[i]-1))) cha=abs(n-siz[i]-(siz[i]-1)),root=i;
	}
	dfs2(root,0);
	dfs3(root,0,1);
	for(i=1;i<=n;i++) fan[id[i]]=i;
	for(i=1;i<=n;i++) scanf("%d",&du[i]);
	for(i=1;i<=n;i++) rong[i]=du[id[i]];
	dfs4(1);
	for(i=1;i<=m;i++){
		scanf("%d",&st),st=fan[st];
		chu=st;pos=find(st);
		xiangshang(st,pos);
		st=pos,pos=son[pos];
		xiangxia(pos,st);
		rong[pos]--;
		update(pos);
		update(chu);
		printf("%lld ",ans);
	}
	return 0;
}

