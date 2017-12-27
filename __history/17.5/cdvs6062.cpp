#include<cstdio>
#include<cctype>
struct _Main{
char buf[201000];
int cnt;
int t[3];
int n;
int tot[3];
int ans;
_Main(){
	int i=0,pos,j,k;
	scanf("%d",&n);
	fread(buf,1,2*n+100,stdin);
	for( pos = 0 ; i < n ; pos ++ ){
		if(isdigit(buf[pos])){
			buf[i++]=buf[pos];
			tot[buf[pos]-'0']++;
			if(i == n>>1){
				for(j=0;j<3;j++){
					t[j]=tot[j];				
				}
			}
		}
	}
	for(i=0, ans = 1;i<3;i++){
		if(t[i] != tot[i] >> 1){
			ans = 0;
			break;
		}
	}
	if(ans){
		printf("%d", ans);
		return;
	}
	for(i=1;i<=n>>1;i++){
		t[buf[i-1] - '0']--;
		t[ buf[ ( n >> 1 ) +i -1] - '0']++; 
		for(ans=2,j = 0 ; j < 3 ; j ++ ){
			if(t[j]!=tot[j]>>1){
				ans=0;
				break;
			}
		}
		if(ans){
			printf("%d", ans);
			return;
		}		
	}
	printf("3");
}

}cdvs6062;int main(){}
