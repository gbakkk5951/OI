#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int o[1010],s[1010];
int s1[1010],s2[1010];
int po[1010];
char way[2020];
bool flag;
int top1,top2,tot,e;
bool check(){
	int i,j,k;
	for(i=0;i<top1;i++){
		if(s1[i]<e+top1-i)
		return true;
	}
	for(j=0;j<top2;j++){
		if(s2[j]<e+top2-j)
		return true;
	}
	return false;
}

void dfs(int step){
	int i,j,k;
	if(check())return;
	//a
	way[step]='a';
	if(tot<n&&(!top1||s1[top1-1]>o[tot])){
	if(o[tot]-1<e)
	return;
	s1[top1++]=o[tot++];
	dfs(step+1);
	top1--,tot--;
	}
	
	if(flag) return;
	
	//b
	way[step]='b';
	if(top1&&s1[top1-1]-1==e){
		int temp=s1[top1-1];
		top1--;
		e++;
		if(e==n){
			flag=true;
			return;
		}
		dfs(step+1);
		top1++;
		e--;
		s1[top1-1]=temp;return;	
	}
	
	
	//c
	way[step]='c';
	if(tot<n&&(!top2||o[tot]<s2[top2-1])){
	if(o[tot]-1<e)
	return;
	s2[top2++]=o[tot++];
	dfs(step+1);
	top2--,tot--;	
	}
	if(flag) return;
	//d
	way[step]='d';
	if(top2&&s2[top2-1]-1==e){
		int temp=s2[top2-1];
		top2--;
		e++;
		if(e==n){
			flag=true;
			return;
		}
		dfs(step+1);
		top2++;
		e--;
		s2[top2-1]=temp;
	}
	

}
int main(){
	
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",o+i);
		s[i]=o[i];
	}sort(s,s+n);

	dfs(0);
	if(!flag){
		printf("0\n");
		return 0;
	}
	for(i=0;i<2*n;i++){
		putchar(way[i]);
		putchar(' ');
	}
} 
