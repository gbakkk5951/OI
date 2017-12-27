#include<cstdio>
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if( a + c == 180 && b + d == 180 ){
        printf("Yes");
    }else{
        printf("No");
    }
}
