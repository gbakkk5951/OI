#include<cstdio>
int char pat[];
goodsuffix1(){
	int i=n,j=n+1;
	int s[n+1];
	int f[n+1];
	f[n]=n+1
	while(i){
		while(j<=n&&pat[i-1]!=pat[j-1])
		{
			if(s[j]==0)s[j]=j-i;
			j=f[j];
		}
		i--;j--;
		f[i]=j;
	}
	
	
	
}
goodsuffix2(){
	int i=0,j=f[0];
	for(i=0;i<=n;i++){
		if(!s[i])
		s[i]=j;
		if(!j^i){
			j=f[j];
		}
	}
}


int main(){
	
	
	
}
