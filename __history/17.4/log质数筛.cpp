#include<cstdio> 
#include<bitset>
#include<cctype>
using namespace std;
bitset<20000010>vis;
struct _Main{
int n;
_Main(){
	int i,j,k;
	char t;
	while(!isdigit(t=getchar()));
	do{
		n*=10;
		n+=t-'0';
	}while(isdigit(t=getchar()));
	for(i=2;i<=n;i++){
		if(!vis[i]){
			output(i);
			putchar(' ');
			k=2*i;
			for(;k<=n;k+=i){
				vis[k]=true;
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
