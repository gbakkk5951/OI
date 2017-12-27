#include<cstdio>
int nu[10];
int bu[2][10010];
int nn[10010];
int nb[10010];
int po[6]={1,10,100,1000,10000,100000};
int main(){
	freopen("随机数.out","r",stdin);
	freopen("静态数组基排.txt","w",stdout);
	int j,k;
	int i=0;
	while(~scanf("%d",&bu[1][i])){
			i++;
	}
	for(j=0;j<6;j++){
		for(k=0;k<10;k++){
			nu[k]=0;
		}
		for(k=0;k<i;k++){
			nu[nn[k]=(bu[(j+1)%2][k]/po[j])%10]++;
		}
		for(k=1;k<10;k++){
			nu[k]+=nu[k-1];
		}
		
		for(k=i-1;k>=0;k--){
			bu[(j)%2][--nu[nn[k]]]=bu[(j+1)%2][k];
		}
	}
	for(k=0;k<i;k++){
	printf("%d ",bu[(j+1)%2][k]);		
	}
	fclose(stdout);
	
	
} 
