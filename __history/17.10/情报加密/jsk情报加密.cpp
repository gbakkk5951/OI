int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
struct AcNode{
	AcNode *son[4],*fail;
	int dp[1005];bool end;
	AcNode(){
		memset(dp,63,sizeof(dp));
	}
};
struct AcTrie{
AcNode pool[1010];
int nodeidx;

AcTrie(){
	root=newnode();
	root->dp[0]=0;
}

inline AcNode * newnode(){
	return &pool[nodeidx++];
}
AcNode *root;
int run(char *str){
	int i,j,k;AcNode *nd;
	for(i=0;str[i];i++){
		for(j=0;j<nodeidx;j++)if( (!pool[j].end) && pool[j].dp[i]<2000){
			pool[j].son[str[i]-'A']->dp[i+1]=min(pool[j].son[str[i]-'A']->dp[i+1],pool[j].dp[i]);
			for(k=0;k<4;k++)if(str[i]-'A'!=k){
				pool[j].son[k]->dp[i+1]=min(pool[j].son[k]->dp[i+1],pool[j].dp[i]+1);
			}
		}
	}return i;
}
int getans(int len){
	int ans=10000;int i;
	for(i=0;i<nodeidx;i++)if(!pool[i].end){
		ans=min(ans,pool[i].dp[len]);
	}return ans;
}

void insert(char *str){
	int i;AcNode *nd=root;
	for(i=0;str[i];i++){
		if( !nd->son[str[i]-'A']){
			nd->son[str[i]-'A']=newnode();
		}
		nd=nd->son[str[i]-'A'];
	}nd->end=true;
}
queue<AcNode *>q;
void build(){
	int i;AcNode *nd=root;
	for(i=0;i<4;i++){
		if(nd->son[i]){
			nd->son[i]->fail=nd;
			q.push(nd->son[i]); 
		}else{
			nd->son[i]=nd;
		}
	}
	while(!q.empty() ){
		nd=q.front();q.pop();
		nd->end=nd->end || nd->fail->end; 
		for(i=0;i<4;i++){
			if(nd->son [i]){
				nd->son[i]->fail =nd->fail ->son[i];
				q.push(nd->son[i]) ;
			}else{
				nd->son[i]=nd->fail->son[i];
			}
		}
	}
}
	
	
}actrie;


struct _Main{
char word[25];
char pat[1005];int n;
_Main()	{
	int i;int ans;int len;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",word);
		actrie.insert(word);
	}actrie.build();
	scanf("%s",pat);
	len=actrie.run(pat);
	ans=actrie.getans(len);
	if(ans<=1000)
	printf("%d",ans);
	else printf("-1");
	fclose(stdout);
}
	
	
}jsk;
