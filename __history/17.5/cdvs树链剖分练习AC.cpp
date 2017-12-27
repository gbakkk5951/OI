#include<cstdio>
#include<cctype>
#include<bitset>
using namespace std;
using std::bitset;
struct _Main{
//////////////       {
	bitset<100009>vis;
	int from[100023];
	int head[200009];
	int nxt[200014];	
	int to[200017];
	int val[440013];
	int lazy[440013];
	int fa[100011];
	int size[100007];
	int pos[100005];
	int h[100022];
	int mxpos[100033];
	int e_cnt;
	int cnt;
	int n,q,a,b,c;
//////////////		}
int inline max(int a,int b){
	return (a+b+abs(a-b))>>1;
}
int inline min(int a,int b){
	return (a+b-abs(a-b))>>1;
}
int inline abs(int a){
	return a>>31^((a>>31)+a);
}


int read(){
    int ans;
    char t;
    while(!isdigit(t=getchar()));
    ans=t-'0';
    while(isdigit(t=getchar())){
        ans*=10;
        ans+=t-'0';
    }
    return ans;
}
inline void add(int a,int b){
	nxt[e_cnt]=head[a];
	head[a]=e_cnt;
	to[e_cnt++]=b;
}
void size_dfs(int now){
	int i,t;
	vis[now]=1;
	for(i=head[now];i;i=nxt[i]){
		if(!vis[to[i]]){
			from[to[i]]=now;
			size_dfs(to[i]);
			if(size[to[i]]>size[mxpos[now]]){
				mxpos[now]=to[i];
			}
			size[now]+=size[to[i]];
		}
	}
	++size[now];
}
void f_dfs(int now,int p_fa,int p_h){
	if(!now){
		return;
	}
	h[now]=p_h;
	fa[now]=p_fa;
	vis[now]=true;
	pos[now]=++cnt;
	f_dfs(mxpos[now],p_fa,p_h);
	int i;
	for(i=head[now];i;i=nxt[i]){
		if(!vis[to[i]]){
			f_dfs(to[i],to[i],p_h+1);
		}
	}
}
int query(int l,int r,int nd,int ql,int qr){
	if(l>qr||r<ql){
		return 0;
	}
	if(l>=ql&&r<=qr){
		return val[nd];
	}

	if(lazy[nd]){
		val[nd<<1]+=lazy[nd]*((l+r>>1)-l+1);
		lazy[nd<<1]+=lazy[nd];
		val[nd<<1|1]+=lazy[nd]*(r-(l+r>>1));
		lazy[nd<<1|1]+=lazy[nd];		
		lazy[nd]=0;
	}
	return query(l,l+r>>1,nd<<1,ql,qr)+
			query((l+r>>1)+1,r,nd<<1|1,ql,qr);
}
int change(int l,int r,int nd,int ql,int qr){

	if(l>qr||r<ql){
		return 0;
	}
	if(qr>=r&&ql<=l){
		val[nd]+=r-l+1;
		lazy[nd]++;
		return r-l+1;
	}
	int t;
	t=change(l,l+r>>1,nd<<1,ql,qr)+
	change((l+r>>1)+1,r,nd<<1|1,ql,qr);
	val[nd]+=t;
	return t;
}
void ini(){
	e_cnt=1;
	cnt=1;
	from[1]=1;
}

_Main(){
	ini();
	int i,j,k;
	n=read();
	for(i=1;i<n;i++){
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	n++;
	size_dfs(1);
	vis.reset();
	f_dfs(1,1,1);
	q=read();
	for(i=0;i<q;i++){
		a=read();
		b=read();
		c=read();
		if(a==1){
			a1();
		}else{
			a2();
		}
	}
}
void a1(){
	while(fa[b]!=fa[c]){
		if(h[b]>h[c]){
			change(1,n,1,pos[fa[b]],pos[b]);
			b=from[fa[b]];
		}else{
			change(1,n,1,pos[fa[c]],pos[c]);
			c=from[fa[c]];
		}
	}
	change(1,n,1,min(pos[c],pos[b]),
			max(pos[c],pos[b]));
}
void a2(){
	int ans=0;
	while(fa[b]!=fa[c]){
		if(h[b]>h[c]){
			ans+=query(1,n,1,pos[fa[b]],pos[b]);
			b=from[fa[b]];
		}else{
			ans+=query(1,n,1,pos[fa[c]],pos[c]);
			c=from[fa[c]];
		}
	}
	ans+=query(1,n,1,min(pos[c],pos[b]),
			max(pos[c],pos[b]));
	printf("%d\n",ans);
}

}cdvs4633;int main(){}
