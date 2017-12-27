#include<cstdio>
int main(){}
struct Search{
	int cnt;
	int num;
};
const int prime[]={
	2,3,5,7,11,13,17,19,23,29,31
};
struct _Main{
	
Search dfs(int rem,int pos){
	
	Search ans=(Search){0,1},temp;
	int i;long long pow;
	for(i=1,pow=prime[pos];pow<=rem;i++,pow*=prime[pos]){
		temp=dfs(rem/pow,pos+1);
		temp.cnt=(1+i)*temp.cnt+i;
		temp.num*=pow;
		if(temp.cnt>ans.cnt || (temp.cnt==ans.cnt && temp.num<ans.num)){
			ans=temp;
		}
	}
	return ans;
	
}	
	
_Main(){
	int n;
	scanf("%d",&n);
	Search ans=dfs(n,0);
	printf("%d",ans.num);
	
}	
	
	
	
}zeoj1001; 
