using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cstring>
struct Way{
    int beg,end,cst,lca;
}way[300010];

template<typename Type>
    void read(Type &a){
        char t;
        while(!isdigit(t=getchar()));
        a=t-'0';
        while( isdigit(t=getchar())){
            a*=10;a+=t-'0';
        }
    }
int fa[300010];
vector<Way *> query[300010] ;
struct _Main{
int add[300010];
int dis[300010];
bool in[300010];
int getfa(int nd){
    if(fa[nd]){
        return fa[nd]=getfa(fa[nd]);
    }
    return nd;
}
void tarjan(int nd=1,int from=0){
    int i;
    in[nd]=1;
    for(i=0;i<query[nd].size();i++){
        if(nd==query[nd][i]->beg){
            if(!in[query[nd][i]->end])continue;
            query[nd][i]->lca=getfa(query[nd][i]->end);
            query[nd][i]->cst=dis[query[nd][i]->beg]+dis[query[nd][i]->end]
                             -2*dis[query[nd][i]->lca];
        }else if(in[query[nd][i]->beg]){
            query[nd][i]->lca=getfa(query[nd][i]->beg);
            query[nd][i]->cst=dis[query[nd][i]->beg]+dis[query[nd][i]->end]
                             -2*dis[query[nd][i]->lca];
        }
    }
    for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
        dis[to[i]]=dis[nd]+val[i];
        tarjan(to[i],nd);
        fa[to[i]]=nd;
    }
}

void getdis(int nd=1,int from=0){
    int i;
    for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
        dis[to[i]]=dis[nd]+val[i];
        getdis(to[i],nd);
    }
}

int m,n;
int nxt[600010];
int to[600010];
int head[300010];
int val[600010];
int mxnum;
int eidx;
int edge[300010];
void inline addedge(const int &a,const int &b,const int &c){
    eidx++;
    nxt[eidx]=head[a];
    head[a]=eidx;
    to[eidx]=b;
    val[eidx]=c;
}
int choseedge;
int getedge(int nd=1,int from=0){
    int i;int ret=0,cnt;
    for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
        ret+=(cnt=getedge(to[i],nd));
        if(cnt==mxnum && val[i]>val[choseedge]){
            choseedge=i;
        }
    }
    ret+=add[nd];
    return ret;
}
int mxans;
_Main(){
    int a,b,c;
    int i,j,k;
    read(n);read(m);
    for(i=1;i<=n-1;i++){
        read(a);read(b);read(c);
        addedge(a,b,c);addedge(b,a,c);
    }
    for(i=0;i<m;i++){
        read(way[i].beg);read(way[i].end);
        query[way[i].beg].push_back(&way[i]);
        query[way[i].end].push_back(&way[i]);
    }
    tarjan();
    
    
    int l=0,r=0;int mxcst=0;
    for(i=0;i<m;i++){
		mxcst=max(mxcst,way[i].cst);
    }
    r=mxcst;
    while(l<r){
    	mxans=(l+r)>>1;
		mxnum=0;
	    for(i=0;i<m;i++)if(way[i].cst>mxans){
	    	mxnum++;
	    	add[way[i].beg]++;
	    	add[way[i].end]++;
	    	add[way[i].lca]-=2;
		}
    	choseedge=0;
    	getedge();
	    if(val[choseedge]>=mxcst-mxans){
			r=mxans;
	    }else{
	    	l=mxans+1;
		}
	    for(i=1;i<=n;i++){
	    	add[i]=0;
		}
	}
    printf("%d",l);
}




}ezoj1102;
