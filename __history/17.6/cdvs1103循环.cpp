using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cstdlib>
const int list[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
struct _Main{
char sn[110];
long long n[15];
long long now[15];
long long test[15];
long long temp[15];
int k;
bool judge(int k){
	printf("[%d]%lld\n",k,test[0]);
	
	
	int i,j,i2;
	j=k/9;
	for(i=0;i<j;i++){
		if(now[i]!=test[i]){
			return false;
		}
	}
	i2=k-j*9;
	for(i=0;i<i2;i++){
		if((now[j]/list[i])%10 != (test[j]/list[i])%10){
			return false;
		}
	}
	printf("true\n");
	return true;
}
_Main(){
	int i,j;
	int ls;
	int k_block;
	scanf("%s",sn);
	ls=strlen(sn);
	k=0;
	for(i=ls-1;i>=0;i-=9){
		for(j=0;j<9&&i-j>=0;j++){
			n[k]+=(sn[i-j]-'0')*list[j];
		}
		k++;
	}
	scanf("%d",&k);
	k_block=k/9;
	int ll=1,nl=0;
	int I;
	memcpy(now,n,sizeof(n));
	memcpy(test,now,sizeof(n));
	int ans=0;
	for(I=0;I<k;I++){
		if(I&&judge(I+1)){
			continue;
		}
		if(nl==1){
			memcpy(test,now,sizeof(temp));
		}else{
			memcpy(now,test,sizeof(test));
		}		
		memcpy(temp,test)
		nl=0;
		
		do{
			memcpy(test,temp,sizeof(temp));
			memset(temp,0,sizeof(temp));
			for(i=0;i<=k_block;i++){
				for(j=0;j<=k_block;j++){
					temp[i+j]+=now[i]*test[j];
				}
			}
			for(i=0;i<=k_block;i++){
				temp[i+1]+=temp[i]/list[8];
				temp[i]%=list[8];
			}
			
			nl++;
			if(nl>10){
				printf("-1");
				return;
			}
		}while(!judge(I+1));

		
		ll=ll*nl;
	//	ans=ll+ll*ans;
		
		
	}
	
	printf("%d",ll);
	
	
}

	
	
	
	
}cdvs1103;
