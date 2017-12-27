using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<algorithm>
struct _Main{
char temp[2][100010];
char num[2][100010];
char sum[100010];
int l[2];
_Main(){
	int i,j,k;int iter;
	
	for(iter=0;iter<2;iter++){
		scanf("%s",temp[iter]);
	}
	for(iter=0;iter<2;iter++){
		l[iter]=strlen(temp[iter]);
		for(i=0;i<l[iter];i++){
			num[iter][i]=temp[iter][l[iter]-i-1]-'0';
		}
	}
	for(i=0;i<l[0]||i<l[1];i++){
		sum[i]+=num[0][i]+num[1][i];
		if(sum[i]>=10){
			sum[i+1]=1;
			sum[i]-=10;
		}
	}
	for(i=max(l[0],l[1])+2;i>=0;i--){
		if(sum[i])break;
	}
	if(i<0){
		printf("0");
	}else{
		for( ;i>=0;i--){
			putchar(sum[i]+'0');
		}
	}
}
	
	
	
}ezoj1000;
