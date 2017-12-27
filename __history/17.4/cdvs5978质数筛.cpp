#include<cstdio> 
#include<bitset>
using namespace std;
int prime[1270607];
bitset<20000010>vis;
struct _Main{
int n;
_Main(){
	int i,j,k;
	int cnt=0;
	char t;
	while(!isdigit(t=getchar()));
	do{
		n*=10;
		n+=t-'0';
	}while(isdigit(t=getchar()));
	for(i=2;i<=n;i++){
		if(!vis[i]){
			prime[cnt++]=i;
			output(i);
			putchar(' ');
		}
		for(j=0;j<cnt&&(k=prime[j]*i)<=n;j++){
			vis[k]=true;
			if(!(i%prime[j])){
				break;
			}
		}
	}
	
}	
void output(int i){
	int j;
	if(j=i/10){
		output(j);
	}
	putchar(i-j*10+'0');	
}	
	
	
}instance;int main(){}
