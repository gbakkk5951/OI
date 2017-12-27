using namespace std;
int main(){}
#include<cstdio>
#include<bitset>
struct _Main{



int n;
bool prime[60];
int way[20];
bool isprime(int a){
	int i;
	for(i=2;i*i<=a;i++){
		if(a%i==0){
			return false;
		}
	}return true;
	
	
}


void dfs(int rem,int pos){
	int i,j;int cnt;
	if(pos==n){
		if(!prime[way[n-1]+1])return;
		for(i=0;i<n;i++){
			printf("%d ",way[i]);
		}putchar('\n');
		
		return;
	}
	for(i=2;i<=n;i++)if((1<<i)&rem){
		if(prime[i+way[pos-1]]){
			way[pos]=i;
			dfs(rem^(1<<i),pos+1);
		}
	}
}
_Main(){
	int i;int rem=0;
	scanf("%d",&n);
	for(i=2;i<=(2*n);i++){
		if(isprime(i))prime[i]=true;
	}
	way[0]=1;
	for(i=2;i<=n;i++){
		rem|=(1<<i);
	}
	dfs(rem,1);
}	
	
	
	
}cdvs1031;
