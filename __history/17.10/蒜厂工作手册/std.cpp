int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
struct AcNode{
	AcNode *son[26];
	AcNode *fail;
	int dep;
	char alpha;char end;
};
struct AcTrie{
AcNode *stk[100010];
int stkidx;
AcNode pool[100010];
AcNode *root;
char strstk[100010];
int stridx;
int nodeidx;
inline AcNode *  newnode(){
	return &pool[nodeidx++];
}

inline AcNode *  newnode(char t){
	pool[nodeidx].alpha =t;
	return &pool[nodeidx++];
}
AcTrie(){
	root=newnode();
}

void run(char *str){
	int i,j,k;AcNode *nd=root;
	stk[stkidx++]=root;
	for(i=0;str[i];i++){
		nd=nd->son[str[i]-'a'];
		stk[stkidx++]=nd;
		strstk[stridx++]=str[i];
		if(nd->end) {
			stkidx-=nd->dep;
			stridx-=nd->dep;
			nd=stk[stkidx-1];
		}
	}
}
void print(bool ios=false){
	int i;
	if(ios==false)for(i=0;i<stridx;i++){
		putchar(strstk[i]);
	}
	else {
		for(i=0;i<stridx;i++){
			cout<<strstk[i] ;
		}cout<<endl;
	}
}
void insert(char *str){
	int len=strlen(str);
	AcNode *nd=root;
	int i;
	for(i=0;i<len;i++){
		if( nd->son[str[i]-'a'] == 0){
		    nd->son[str[i]-'a']=newnode(str[i]);
		}   nd=nd->son[str[i]-'a'];
	}
	nd->dep =len;
	nd->end=true;
}
queue<AcNode*>q;
void build(){
	AcNode *nd=root;
	int i;
	for(i=0;i<26;i++){
		if(nd->son[i]){
			nd->son[i]->fail =nd;
			q.push(nd->son[i]); 
		}else{
			nd->son[i]=nd;
		}
	}
	while(!q.empty() ){
		nd=q.front();q.pop();
		for(i=0;i<26;i++){
			if(nd->son[i]){
				nd->son[i]->fail =nd->fail->son[i];
				q.push(nd->son[i]); 
			}else{
				nd->son[i]=nd->fail->son[i];
			}
		}
	}
}


	
}actrie;


struct _Main{
char book[100010];
char word[100010];
int n;
_Main(){
	scanf("%d",&n);
	
	int i;
	for(i=0;i<n;i++){
		scanf("%s",word);
		actrie.insert(word);
	}actrie.build();
	scanf("%s",book);
	actrie.run(book);
	actrie.print(); 
	fclose(stdout);
}
	
	
	
	
}jsk;
