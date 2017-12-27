using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
const long long mod[7]={
	101537,101533,101719,23333,200713,23071,10337
};
bool zero[210000][7];
long long a[105][7];
int ans[1005];
int anscnt;
void read(int idx){
	char t,f=1;int i;
	while(!isdigit(t=getchar())){
		if(t=='-')f=-1;
	}
	do{
		for(i=0;i<7;i++){
			a[idx][i]=(a[idx][i]*10+t-'0')%mod[i];
		}
	}while( isdigit(t=getchar()));
	for(i=0;i<7;i++){
		a[idx][i]*=f;
	}
}
struct _Main{
bool  calc(long long m,int modidx){
	int i;
	long long res=0;
	for(i=n;i>0;i--){
		res=(res+a[i][modidx])*m %mod[modidx];
	}
	res=(res+a[0][modidx])%mod[modidx];
	return res==0;
}
int n,m;
_Main(){
	int i,j;bool ok;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++){
		read(i);
	}
	for(i=1;i<=m;i++){
		ok=true;
		for(j=0;j<7;j++){
			if(i>mod[j]){
				ok=(zero[i%mod[j]][j])&&ok;
			}else{
				ok=(zero[i%mod[j]][j]=calc(i,j))&&ok;
			}
		}
		if(ok){
			ans[anscnt++]=i;
		}
	}
	printf("%d\n",anscnt);
	for(i=0;i<anscnt;i++){
		printf("%d\n",ans[i]);
	}
}	
	
	
	
	
	
	
	
	
}ezoj1106;

