using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<queue>

const int mod=10007;

struct AcNode{
	AcNode *fail,*son[26];
	int end;int dp[2][105];
};

struct AcTrie{
AcNode *root;
AcNode pool[6005];
AcNode *q[6005];
int qcnt;
int nodeidx;
inline AcNode * newnode(){
	return &pool[nodeidx++];
}
AcTrie(){
	root=newnode();
	root->dp[0][0]=1;
}	
void insert(char *str){
	int i;AcNode *nd=root;
	for(i=0;str[i];i++){
		if(!nd->son[str[i]-'A']){
			nd->son[str[i]-'A']=newnode();
		}nd=nd->son[str[i]-'A'];
	}nd->end=true;
}
void build(){
	int i,j;AcNode *nd=root;
	for(i=0;i<26;i++){
		if(nd->son[i]){
			nd->son[i]->fail=nd;
			q[qcnt++]=nd->son[i];
		}else{
			nd->son[i]=nd;
		}
	}
	for(i=0;i<qcnt;i++){
		nd=q[i];
		nd->end=nd->end || nd->fail->end; 
		for(j=0;j<26;j++){
			if(nd->son[j]){
				nd->son[j]->fail=nd->fail->son[j];
				q[qcnt++]=nd->son[j];
			}else{
				nd->son[j]=nd->fail->son[j];
			}
		}
	}
}

void run(int len){
	int i,j,k,l;int *goal;
	for(i=0;i<len;i++){
		for(j=0;j<nodeidx;j++){
			for(k=0;k<2;k++)if(pool[j].dp[k][i]){
				for(l=0;l<26;l++){
					goal=&pool[j].son[l]->dp[k||pool[j].son[l]->end][i+1];
					*goal+=pool[j].dp[k][i];
					*goal%=mod;
				}
			}
		}
	}
}
int getans(int len){
	int i,k,ans=0;
	for(i=nodeidx-1;i>=0;i--){
		ans+=pool[i].dp[1][len];
	}ans%=mod;
	return ans;
}


}actrie;


struct _Main{
int m;
char str[105];	
_Main(){
	scanf("%d%d",&n,&m);
	int i;int ans;
	for(i=0;i<n;i++){
		scanf("%s",str);
		if(strlen(str)<=m)
		actrie.insert(str);
	}	actrie.build() ;
	actrie.run(m);
	ans=actrie.getans(m);
	printf("%d",ans);
}	
int n;	
}jsk;
