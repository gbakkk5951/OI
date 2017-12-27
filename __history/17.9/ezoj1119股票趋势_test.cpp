using namespace std;
int main(){}
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
int base;
 
struct SubTree{
    int node[2055];
	int query(int l,int r){
		int lans=-1e8,rans=-1e8;
		for(l=l+base-1,r=r+base+1;l^r^1;l>>=1,r>>=1){
			lans+=node[l];rans+=node[r];
			if(~l&1) lans=max(lans,node[l^1]);
			if( r&1) rans=max(rans,node[r^1]);
		}
		lans=max(lans+node[l],rans+node[r]);
		while(l>>=1){
			lans+=node[l];
		}
		return lans;
	}
	void change(int l,int add){
		int r=l;
		int a;
		for(l=l+base-1,r=r+base+1;l^r^1;l>>=1,r>>=1){
			if(~l&1) node[l^1]+=add;
			if( r&1) node[r^1]+=add;
			a=max(node[l],node[l^1]);
			node[l>>1]+=a;
			node[l]-=a;node[l^1]-=a;
			a=max(node[r],node[r^1]);
			node[r>>1]+=a;
			node[r]-=a;node[r^1]-=a;			
		}
		while(l>>1){
			a=max(node[l],node[l^1]);
			node[l]-=a;node[l^1]-=a;
			node[l>>=1]+=a;
		}
	}
    void clear(){
        memset(node,0,sizeof(int)*(2*base+1));
    }
};
 
struct Tree{
    SubTree node[2055];
    int query(int l,int r,int y1,int y2){
 		int lans=-1e8,rans=-1e8;
		for(l=l+base-1,r=r+base+1;l^r^1;l>>=1,r>>=1){
			lans+=node[l].query(y1,y2);rans+=node[r].query(y1,y2);
			if(~l&1) lans=max(lans,node[l^1].query(y1,y2));
			if( r&1) rans=max(rans,node[r^1].query(y1,y2));
		}
		lans=max(lans+node[l].query(y1,y2),rans+node[r].query(y1,y2));
		while(l>>=1){
			lans+=node[l].query(y1,y2);
		}
		return lans;

    }
	void change(int x,int y,int add){
		int l=r=x;
		l=max(1,l);r=min(sn,r);
		int a;
		for(l=l+sbase-1,r=r+sbase+1;l^r^1;l>>=1,r>>=1){
			if(~l&1) node[l^1]+=add;
			if( r&1) node[r^1]+=add;
			a=max(node[l],node[l^1]);
			node[l>>1]+=a;
			node[l]-=a;node[l^1]-=a;
			a=max(node[r],node[r^1]);
			node[r>>1]+=a;
			node[r]-=a;node[r^1]-=a;			
		}
		while(l>>1){
			a=max(node[l],node[l^1]);
			node[l].change();node[l^1]-=a;
			node[l>>=1]+=a;
		};
	}    
    void clear(){
        int i;
        for(i=0;i<=base*2;i++){
            node[i].clear();
        }
    }
}tree;
 
 
struct _Main{
     
     
     
char a[1000],b[1000];
int limit[26];
int la,lb;
_Main(){
    int T;char alph;int gap;int ans;int dp;
    cin>>a>>b;
    cin>>T;
    int i,j,k;
    la=strlen(a);lb=strlen(b);
    for(j=max(la,lb),i=0;(1<<i)<(j+3);i++);
    base=(1<<i);
    while(T--){
        memset(limit,63,sizeof(limit));
        tree.clear();
        ans=0;
        while(1){
            cin>>alph;
            if(alph!='$'){
                cin>>gap;
                limit[alph-'A']=gap+1;
            }else{
                break;
            }
        }
        for(i=1;i<=la;i++){
            for(j=1;j<=lb;j++)if(a[i-1]==b[j-1]){
                alph=a[i-1]-'A';;
                dp=tree.query(max(1,i-limit[alph]),i-1,max(1,j-limit[alph]),j-1)+1;
                tree.change(i,j,dp);
                ans=max(ans,dp);
            }
        }
        printf("%d\n",ans);
    }
     
}   
     
     
     
     
     
     
     
}ezoj1119;
