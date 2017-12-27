#include<cstdio>
#include<cstring>
struct begin{
int n;
struct node{
	bool end;
	int nxt[26];
	int cnt;
	int fail;
}trie[1000010];
int tot ;
int tot2;
int queue2[2000];
char in[1000010];
begin(){
	tot=1;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",in);
		insert();
	}
	fail();
	out();
}
void insert(){
	int i,j,k,l;
	l=strlen(in);
	int root=0;
	for(i=0;i<l;i++){
		if(trie[root].nxt[in[i]-'a']){
			root=trie[root].nxt[in[i]-'a'];
		}else{
			trie[root].nxt[in[i]-'a']=tot;
			root=tot++;
		}
		trie[root].cnt++;
	}

	queue2[tot2++]=root;
	//trie[root].end=true;
	
}
int queue[1000010];
void fail(){
	int c=0;
	int i,j,k;
	int t=0;
	queue[0]=0;
	while(c<=t){
		if(c)
		{
		for(i=0;i<26;i++){
			if(trie[queue[c]].nxt[i]){
				queue[++t]=trie[queue[c]].nxt[i];
				k=trie[queue[c]].fail;
				while((!trie[k].nxt[i])&&k)k=trie[k].fail ;
				trie[queue[t]].fail=trie[k].nxt[i];
		//		printf(" %d fail -> %d ",queue[t],trie[queue[t]].fail);
			}else{
				
			//	trie[queue[c]].nxt[i]=trie[trie[queue[c]].fail].nxt[i];

			}
			}
		}else{
			for(i=0;i<26;i++)
			if(trie[queue[c]].nxt[i]){
				queue[++t]=trie[queue[c]].nxt[i];
				//trie[queue[t]].fail=0;
			}
		}
		c++;
	

	}
		for(i=tot-1;i;i--){
		trie[trie[queue[i]].fail].cnt+=trie[queue[i]].cnt;
		}
}
void out(){
	int i=0;
	for(i=0;i<n;i++){
			printf("%d\n",trie[queue2[i]].cnt);
	}
}

}instance;int main(){}
