using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>

int mod;
struct _Main{
short to[10005][26][30];	
int val[10005][26][30];
int n,alphnum; 
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
char str[120050];	
int sumval;
int now;
void run(int times,int way){
	int i;
	for(i=0;times;times>>=1,i++)if(times&1){
		sumval=(sumval+val[now][way][i])%mod;
		now=to[now][way][i];
	}
}
_Main(){
	int i,j,k;int a,b;int len;
	read(n);read(alphnum);
	for(i=1;i<=n;i++){
		for(j=0;j<alphnum;j++){
			read(a);read(b);
			to[i][j][0]=a;
			val[i][j][0]=b;
		}
	}
	scanf("%s",str);
	read(mod);
	for(k=1;k<30;k++){
		for(i=1;i<=n;i++){
			for(j=0;j<alphnum;j++){
				to[i][j][k]=to[to[i][j][k-1]][j][k-1];
				val[i][j][k]=(val[to[i][j][k-1]][j][k-1]
							+val[i][j][k-1])%mod;
			}
		}
	}
	
	len=strlen(str);bool gotnum;
	int num;
	for(i=0,now=1,gotnum=false,num=0;i<len;i++){
		if(isdigit(str[i])){
			num*=10;
			num+=str[i]-'0';
			gotnum=true;
		}else if(isalpha(str[i])){
			if(gotnum){
				run(num,str[i]-'A');
				gotnum=false;
				num=0;
			}else{
				run(1,str[i]-'A');
			}
		}
	}
	printf("%d",sumval);
	
}	
	
	
	
	
	
	
}ezoj1024;
