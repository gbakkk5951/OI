using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
int fa[50005];int high[50005];int timeline[50005];
bool vis[50005];

struct MFsetret{
	int fa,time;
};

void clearsig(int nd){
	while(vis[nd]){
		vis[nd]=false;
		nd=fa[nd];
	}
}
MFsetret getfa(int nd){
	int t=0;
	while(fa[nd] &&!vis[nd]){
		vis[nd]=1;
		t=max(t,timeline[nd]);
		nd=fa[nd];
	}
	return (MFsetret){nd,t};
}
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}

struct _Main{
int n,m;
_Main(){
	int i;int a;int b;MFsetret f1,f2;
	read(n);read(m);
	for(i=1;i<=m;i++){
		read(a);read(b);
		f1=getfa(a);
		f2=getfa(b);
		if(f1.fa ==f2.fa || fa[f2.fa]){
			clearsig(a);
			vis[f2.fa]=true;
			f1=getfa(a);
			printf("%d\n",max(f1.time,f2.time)-1);
		}else{
			if(high[f1.fa]>high[f2.fa]){
				fa[f2.fa]=f1.fa;timeline[f2.fa]=i;
			}else if(high[f1.fa]<high[f2.fa]){
				fa[f1.fa]=f2.fa;timeline[f1.fa]=i;
			}else{
				fa[f2.fa]=f1.fa;timeline[f2.fa]=i;
				high[f1.fa]++;
			}
		}
		clearsig(a);clearsig(b);

	}
}
	
	
}ezoj1092;

