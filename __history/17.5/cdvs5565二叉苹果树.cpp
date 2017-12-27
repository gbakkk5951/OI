#include<cstdio>
#include<cctype>
using namespace std;
struct node{
	int dp[100];//剩i个枝子最多多少苹果； 
	int apple[3];
	char size;
	node *lnk[3];
	char tot;

}tree[200];
node * null=-0;
struct _Main{

int read (){
	char t;
	int ans;
	while(!isdigit (t = getchar ()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}

int n,q;
_Main (){
	int i;
	n = read ();
	q = read ();
	int t1,t2,t3;
	for (i = 1; i < n; i ++) {
		t1=read();
		t2=read();
		t3=read();
		tree[t1].lnk[tree[t1].tot] = &tree[t2];
		tree[t1].apple[tree[t1].tot++] = t3;
		tree[t2].lnk[tree[t2].tot] = &tree[t1];
		tree[t2].apple[tree[t2].tot++] = t3;
	}
	dfs(&tree[1]);
	printf("%d\n",tree[1].dp[q+1]);
	
	
}	
inline int max (int a,int b){
	return a > b ? a: b;
}
void dfs (node *nd,node *from=null){
//	printf("%d->%d\n",from-tree,nd-tree);
	if(nd->tot!=1){
		int i,j,app=0;
		node *l=0, *r=0;
		for(i=0;i<nd->tot;i++){
			if(nd->lnk[i] != from){
				if(l!=0){
					r=nd->lnk[i];
				}else{
					l=nd->lnk[i];
				}
				dfs(nd->lnk[i],nd);
				nd->size+=nd->lnk[i]->size;
			}else {
				app=nd->apple[i];
			}
		}
		nd->size++;
//		printf("[%d]l=%d,r=%d \n",nd-tree,l-tree,r-tree);
		if(nd==&tree[1] || nd->tot == 3){
			for(i=1;i<=nd->size;i++){
				for(j=0;j<=l->size&&j<i;j++){
					nd->dp[i]=max(nd->dp[i],l->dp[j]+r->dp[i-j-1]);
				}
				nd->dp[i]+=app;
				printf("tree[%d]dp[%d]=%d\n",nd-tree,i,nd->dp[i]);
			}		
		}else{
			for(i=1;i<=nd->size;i++){				
				nd->dp[i]+=l->dp[i-1]+app;
				printf("tree[%d]dp[%d]=%d\n",nd-tree,i,nd->dp[i]);
			}					
			
			
			
			
		}

	}else{
		nd->size=1;
		nd->dp[1]=nd->apple[0];
	}
//	printf("tree[%d]size=%d \n",nd-tree,nd->size);
}
	
	
	
	
	
	
	
	
	
	
	
}cdvs5565;int main(){return 0;}
