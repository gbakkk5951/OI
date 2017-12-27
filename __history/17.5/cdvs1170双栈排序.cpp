#include<cstdio>
#include<cctype>
#include<vector>
#include<cstdlib>
#include<stack>
using namespace std;
char cl[1010];
struct _Main{
int val[1010];
char scheme[2020];
vector<int>lk[1010];
int now;
stack<int>s1,s2;
int tot;
void add(int a,int b){
//	printf("link %d with %d\n",a,b);
	lk[a].push_back(b);
	lk[b].push_back(a);
}
int read(){
	char t;int ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}
int n;
void buildlink(){
	int i,j,k,l=n-1;
	for(i=1;i<l;i++){
		for(j=i+1;j<n;j++){
			if(val[j]>val[i]){
				for(k=j+1;k<=n;k++){
					if(val[k]<val[i]){
						add(i,j);
						break;
					}
				}
			}
		}
	}
}
bool dye(int now,int from,char c){
	
	if(cl[now] ){
		if(c!=cl[now]){
//			printf("!=");
			return false;
		}else{
			return true;
		}
	}
	int i;
	cl[now]=c;
//	printf("paint %d [%c]\n",now,c);
	for(i=0;i<lk[now].size();i++){
		if(lk[now][i]!=from){
			if(!dye(lk[now][i],now,c=='1'?'0':'1'))
				return false;
		}
	}
	return true;
}
_Main(){
	n=read();
	int i,j,k;
	for(i=1;i<=n;i++){
		val[i]=read();
	}
	buildlink();
	for(i=1;i<=n;i++){
		if(!cl[i]){
			if(!dye(i,0,'0')){
//				printf("fail(%d)",i);
				fail();
			}
		}
	}
	construct_scheme();
	output();
}
void construct_scheme(){
	int i,j,k;
	for(i=1;i<=n;i++){
		while(s1.size() && s1.top()==i-s1.size()-s2.size() ){
			s1.pop();
			scheme[tot++]='b'; 
		}
		if(cl[i]=='0'){
//
			while(s1.size() && s1.top() < val[i]){
				s2.pop();
				scheme[tot++]='d';
				while(s1.size() && s1.top()==i-s1.size()-s2.size()){
					s1.pop();
					scheme[tot++]='b'; 					
				}
			}
//			
			s1.push(val[i]); 
			scheme[tot++]='a';
		}else{
			while(s2.size() && s2.top() == i -s1.size() -s2.size()  ){
				s2.pop() ;
				scheme[tot++]='d';
			}
			s2.push(val[i]); 
			scheme[tot++]='c';
		}
	}
	while(s1.size() || s2.size() ){
		if(s1.size()){
			if(n- s1.size() -s2.size() == s1.top() -1){
				s1.pop() ;
				scheme[tot++]='b';
			}
		}
		if(s2.size()){
			if(n- s1.size() -s2.size() == s2.top() -1){
				s2.pop() ;
				scheme[tot++]='d';
			}
		}			
	}
}
void fail(){
	putchar('0');
	exit(0);
}
void output(){
	int i;
	for(i=1;i<=n;i++){
		printf("%d[%c]\n",i,cl[i]);
	}
	
	
	for(i=0;i<tot;i++){
		putchar(scheme[i]);
		putchar(' ');
	}
}
}cdvs1170;int main(){}
