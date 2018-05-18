#include<cstdio>
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
void init(char*s,int n,int m,int*lcp){
	char*t=s+m;
	int l=n-m,*next=lcp+m,p=next[0]=0;
	for(int i=1;i<=l;i++){
		next[i]=i<p+next[p]?min(p+next[p]-i,next[i-p]):0;
		while(i+next[i]<l&&t[i+next[i]]==t[next[i]])++next[i];
		if(i+next[i]>p+next[p])p=i;
	}
	p=lcp[0]=0;
	for(int i=0;i<=m;i++){
		lcp[i]=i<p+lcp[p]?min(p+lcp[p]-i,next[i-p]):0;
		while(i+lcp[i]<n&&lcp[i]<l&&s[i+lcp[i]]==t[lcp[i]])++lcp[i];
		if(i+lcp[i]>p+lcp[p])p=i;
	}
}
int lcp[1000010],lcs[1000010];
int solve(char*s,char*t,int n){
	if(n<4)return n>1&&(s[0]==s[1]||n>2&&s[1]==s[2])?2:0;
	int m=n/2,res=max(solve(s,t+n-m,m),solve(s+m,t,n-m));
	init(s,n,m,lcp);
	init(t,n,n-m,lcs);
	for(int i=0;i<m;i++)if(lcp[i]+lcs[n-i]>=m-i)res=max(res,m-i<<1);
	for(int i=m+1;i<=n;i++)if(lcp[i]+lcs[n-i]>=i-m)res=max(res,i-m<<1);
	return res;
}
char s[1000010],t[1000010];
int main(){
	scanf("%s",s);
	int n=0;while(s[n])n++;
	for(int i=n;i--;)t[i]=s[n-i-1];
	printf("%d\n",solve(s,t,n));
}
