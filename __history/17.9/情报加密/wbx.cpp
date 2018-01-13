#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
struct node{
	int nxt[4],fail,num;
	int dp[1010];
}tree[1010];
char s[1010];
int root=1,cnt=2,len;
void insert(){
	int x,i,pos=root;
	for(i=0;i<len;i++){
		x=s[i]-'A';
		if(tree[pos].nxt[x]==0){
			tree[pos].nxt[x]=cnt;
			memset(tree[cnt].dp,0x3f,sizeof(tree[cnt].dp));
			tree[cnt++].fail=root;
		}
		pos=tree[pos].nxt[x];
	}tree[pos].num++;
//	printf("num[%d]\n", pos);
	return;
}
queue<int>q;
void acm(){
	int pos,i,x,y;
	for(i=0;i<4;i++) if(tree[root].nxt[i]) q.push(tree[root].nxt[i]);
	while(!q.empty()){
	    
		pos=q.front();
		q.pop();
		tree[pos].num |= tree[tree[pos].fail].num;
//		printf("%d fail = %d\n", pos, tree[pos].fail);
		for(i=0;i<4;i++){
		    
			if(tree[pos].nxt[i]==0) continue;
			x=tree[pos].nxt[i];
            y=tree[pos].fail;
			q.push(x);
			while(y!=root&&tree[y].nxt[i]==0) y=tree[y].fail;
			if(tree[y].nxt[i]) y=tree[y].nxt[i];
			tree[x].fail=y;
			if (tree[pos].num) tree[x].num++;
			if(tree[y].num) tree[x].num++;
            
		}
	}
	return;
}
void solve(){
	int i,j,k,x,t;
	memset(tree[root].dp,0x3f,sizeof(tree[root].dp));
	tree[1].dp[0]=0;tree[root].fail=root;
	for(i=1;i<cnt;i++) for(k=0;k<4;k++) if(tree[i].nxt[k]==0){
		if(tree[tree[i].fail].nxt[k]) tree[i].nxt[k]=tree[tree[i].fail].nxt[k];
		else {
//		    printf("???");
            printf("tree[%d].nxt[%c] = %d\n", i, (char)k + 'A', tree[i].fail);
		    tree[i].nxt[k]=tree[i].fail;
		}
//		printf("tree[%d].nxt[%c] = %d\n", i, (char)k + 'A', tree[i].nxt[k]);
	} else {
//	    printf("tree[%d].nxt[%c] = %d\n", i, (char)k + 'A', tree[i].nxt[k]);
	}
	for(i=0;i<len;i++){
		x=s[i]-'A';
		for(j=1;j<cnt;j++){
			if(tree[j].num||tree[j].dp[i]>10000) continue;
			if(tree[j].nxt[x]){ 
				t=tree[j].nxt[x];
				tree[t].dp[i+1]=min(tree[t].dp[i+1],tree[j].dp[i]);
			}
			for(k=0;k<4;k++){
				if(k==x) continue;
				t=tree[j].nxt[k];
				tree[t].dp[i+1]=min(tree[t].dp[i+1],tree[j].dp[i]+1);
			}
		}
	}
}
int main()
{
	int n,i,ans=10000;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",s);
		len=strlen(s);
		insert();
	}
	acm();
	scanf("%s",s);
	len=strlen(s);
	solve();
	for(i=1;i<cnt;i++) if (!tree[i].num)ans=min(ans,tree[i].dp[len]);
	if(ans==10000) printf("-1");
	else printf("%d",ans);
}

