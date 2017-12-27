int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<queue>
int val[15];
int n,len;
struct AcNode{
	bitset<2050>v[2];
	bool vis[2];
	AcNode *son[4],*fail;
	int set;
};

struct AcTrie{
AcNode pool[1005];
int nodeidx;
inline AcNode * newnode(){
	return &pool[nodeidx++];
}
	
AcNode *root;
AcTrie(){
	root=newnode();
}

void insert(char *str,int idx){
	int i;AcNode *nd=root;
	for(i=0;str[i];i++){
		if(!nd->son[str[i]-'a']){
			nd->son[str[i]-'a']=newnode();
		}nd=nd->son[str[i]-'a'];
	}nd->set|=(1<<idx);
}
int iter;
queue<AcNode *>q;
void build(){
	int i;AcNode *nd=root;
	for(i=0;i<4;i++){
		if(nd->son[i]){
			nd->son[i]->fail =nd;
			q.push(nd->son[i]); 
		}else{
			nd->son[i]=nd;	
		}
	}
	while(!q.empty()){
		nd=q.front();q.pop();
		nd->set|=nd->fail->set;
		for(i=0;i<4;i++){
			if(nd->son[i]){
				nd->son[i]->fail =nd->fail->son[i];
				q.push(nd->son[i]);
			}else{
				nd->son[i]=nd->fail->son[i];
			}
		}
	}
}


void run(int len){
	int i,j,k,l;
	root->vis[iter]=1;root->v[iter][0]=1;
	for(i=0;i<len;i++){
		iter^=1;
		for(j=0;j<nodeidx;j++)if(pool[j].vis[iter^1]){
			pool[j].vis[iter^1]=0;
			for(l=0;l<4;l++){
				pool[j].son[l]->vis[iter]=1;
			}
			for(k=0;k<(1<<n);k++)if(pool[j].v[iter^1][k]){
				pool[j].v[iter^1][k]=0;
				for(l=0;l<4;l++){
					pool[j].son[l]->v[iter][pool[j].son[l]->set|k]=1;
				}
			}
		}
	}
}
int getans(int len){
	int i,j,k;int ans=-1;int temp;
	for(i=nodeidx-1;i>0;i--){
		root->v[iter] |= pool[i].v[iter];
	}
	for(i=0;i<(1<<n);i++)if(root->v[iter][i]){
		for(j=0,temp=0;j<n;j++)if(i&(1<<j)){
			temp+=val[j];
		}ans=max(ans,temp);
	}
	return ans;
}


	
}actrie;


struct _Main{
char str[105];
_Main(){
	scanf("%d%d",&n,&len);
	int i;int ans;
	for(i=0;i<n;i++){
		scanf("%s%d",str,&val[i]);
		if(strlen(str)<=len)
		actrie.insert(str,i);
		else i--,n--;
	}actrie.build() ;
	actrie.run(len);
	ans=actrie.getans(len);
	if(ans>=0){
		printf("%d",ans);
	}else{
		printf("Unhappy!");
	}
	fclose(stdout);
}	
	
	
	
	
	
	
	
}jsk;
