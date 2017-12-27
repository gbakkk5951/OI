using namespace std;
int main(){}
#include<cstdio>
struct _Main{
_Main(){
    int mod=14233333;
    int last[2]={1,2};
    int i,k;
    scanf("%d",&k);
    char iter=1;
    for(i=3;i<=k;i++){
        last[iter^1]=(long long)((long long)last[iter^1]*(i-1)+last[iter])%mod;
        iter^=1;
    }
    if(k==1){
        printf("1");
    }else{
        printf("%d",last[iter]);
    }

}    
       
}cdvs6166;

