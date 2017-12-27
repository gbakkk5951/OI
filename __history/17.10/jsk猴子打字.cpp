#include<cstdio>
#include<cstring>
int main(){}
struct AcNode{
	int fail,son[26];
	int cnt;bool end;
};



struct AcTrie{
int q[500010];
int qidx;
AcNode tree[500010];
int root;
int nodeidx;
inline int  newnode(){
	return ++nodeidx;
}
AcTrie(){
	root=newnode();
}
void insert(char *str){
	int i;int nd=root;
	for(i=0;str[i];i++){
		if(tree[nd].son[str[i]-'a'] == 0){
			tree[nd].son[str[i]-'a']=newnode();
		}
		nd=tree[nd].son[str[i]-'a'];
	}
	tree[nd].end=true;
}
void build(){
	int nd=root;int i,j;
	for(i=0;i<26;i++){
		if(tree[nd].son[i]){
			tree[tree[nd].son[i]].fail =nd;
			q[qidx++]=tree[nd].son[i];
		}else{
			tree[nd].son[i]=nd;
		}
	}
	for(i=0;i<qidx;i++){
		nd=q[i];
		for(j=0;j<26;j++){
			if(tree[nd].son[j]){
				tree[tree[nd].son[j]].fail =tree[tree[nd].fail ].son[j];
				q[qidx++]=tree[nd].son[j];
			}else{
				tree[nd].son[j]=tree[tree[nd].fail].son[j];
			}
		}
	}
}
void run(char *str){
	int i;int nd=root;
	for(i=0;str[i];i++){
		nd=tree[nd].son[str[i]-'a'];
		if(tree[nd].end)tree[nd].cnt=1;
	}
}
int count(){
	int i;
	int ans=0;
	for(i=qidx-1;i>=0;i--){
		ans+=tree[q[i]].cnt;
	}
	return ans ;
}

}actrie;
struct _Main{
char word[55];
char passage[1000010];	
_Main(){
	int n,i;int ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",word);
		actrie.insert(word);
	}actrie.build();
	scanf("%s",passage);
	actrie.run(passage);
	ans =actrie.count();
	printf("%d",ans);
}	
	
}jsk;


