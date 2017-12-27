#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
using namespace std;
struct _Main{
int sq;
int k[200010];
int to[200010];
int c[200010];
int n;
int read(){
	char t;
	int ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}	
void updata(int pos){
	int i,j;
	int q=pos/sq;
	q*=sq;
	int g=q+sq;
	for(i=pos;i>=q;i--){
//		printf("%d ",i);
		j=k[i]+i;
		c[i]=1;
		if(j>=n){
			to[i]=n;
		}else{
			if(j<g){
				to[i]=to[j];
				c[i]+=c[j];
			}else{
				to[i]=j;	
			}
		}
	}
}
void ini(){
	int i;
	updata(n-1);
	for(i=((n-1)/sq)*sq-1;i>=0;i-=sq){
		updata(i);
	}
}
int query(int pos){
	int ans=0;
	while(pos!=n){
		ans+=c[pos];
		pos=to[pos];
	}
	return ans;
}
_Main(){
	int q,i,a,b,c;
	
	n=read();
	sq=sqrt(n);
	for(i=0;i<n;i++){
		k[i]=read();
	}
	ini();
	q=read();
	for(i=0;i<q;i++){
		a=read();
		b=read();
		if(a==1){
			printf("%d\n",query(b));
		}else{
			k[b]=read();
			updata(b);
		}
	}
	
}	
	
	
	
	
	
}cdvs2333;int main(){}
