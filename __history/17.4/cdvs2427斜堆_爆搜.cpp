#include<cstdio>
#include<cctype>
#include<cstring>
#include<set>
#include<cstdlib>
#include<stack>
#include<algorithm>
using namespace std;
set<char>anc[51];
char in[51];
char tf[51];
char tl[51];
char tr[51];
char inp[51];
bool use[51];
struct status{
	char f[51],l[51],r[51],rt;
	status(){
		rt=100;
	}
}beg;
stack<status>st;



struct _Main{

char n;

_Main(){
	st.push(beg);
	readin();
	build_ancestor();
	dfs();
}

void readin(){
	char i;short in;
	n=read();	
	for(i=1;i<=n;i++){
		in=read();
		if(in<100){
			tl[in]=i;
			tf[i]=in;
		}else{
			in-=100;
			tr[in]=i;
			tf[i]=in;			
		}
	}
}
void build_ancestor(char index=0){
	if(index){
		anc[index]=anc[tf[index]];
		anc[index].insert(tf[index]); 
	}
/*	set<char>::iterator it=anc[index].begin() ;
	printf("%d\n",index);
	while(it!=anc[index].end()){
		printf("%d ",*it);it++;
	}printf("\n----\n");
*/	
	if(tl[index]){
		build_ancestor(tl[index]);
	}
	if(tr[index]){
		build_ancestor(tr[index]);
	}
}
void del(){
	st.pop();
}
bool insert(char nd){
	#define l st.top().l
	#define r st.top().r
	#define f st.top().f
	#define rt st.top().rt
	st.push(st.top());
	char now=rt;
	if(rt==100){
		rt=nd;
		f[nd]=nd;
		return true;
	}
	while(1){
		if(nd>now){
			swap(l[now],r[now]);
			if(!l[now]){
				l[now]=nd;
				f[nd]=now;
				if(islegal()){
					return true;
				}else {
					return false;
				}
			}
			now=l[now];
		}else{
			if(nd<rt){
				nd=rt;
			}
			f[nd]=f[now];
			if(f[now]!=now){
				if(l[f[now]]==now){
					l[f[now]]=nd;
				}else r[f[now]]=nd;
			}
			f[now]=nd;
			l[nd]=now;
			break;
		}
	}

	if(anc[now].find(nd)==anc[now].end()||!islegal()){
		return false;
	}
	
	return true;
	
	
}
void dfs(char iter=0){
	char i;
	if(iter>n){
		output();
	}
	for(i=0;i<=n;i++){
		if(!use[i]){
			use[i]=true;
			inp[iter]=i;
			if(insert(i)){
				dfs(iter+1);	
			}
			del();
			use[i]=false;
		}
	}
}


bool islegal(int root=rt){
	char fl,i;
	bool vis[51];
	set<char>::iterator it;
	for(i=0;i<=n;i++){
		if(use[i]){
			fl=f[i];
			it=anc[i].begin();
			while(fl!=f[fl]){
				vis[fl]=true;
				fl=f[fl];
			}vis[fl]=true;
			while(it!=anc[i].end()){
				if(!vis[*it]&&use[*it]){
					return false;
				}
				it++;
			}
			memset(vis+1,0,50);
		}
	}
	return true;
}	
void output(){
	int i;
	for(i=0;i<=n;i++){
		printf("%d ",inp[i]);
	}
	exit(0);
}
	
	
short read(){
	char t;short ans=0;
	while(!isdigit(t=getchar()));
	do{
		ans*=10;
		ans+=t-'0';
	}while(isdigit(t=getchar()));
	return ans;
}
	
}instance;int main(){}
