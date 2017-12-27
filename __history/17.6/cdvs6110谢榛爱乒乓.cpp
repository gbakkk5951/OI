int main(){}
using namespace std;
#include<cstdio>
struct _Main{
_Main(){
    int a=0;
    int b=0;
    char t[10];
    while(~scanf("%s",t)){
        if(t[0]=='j') a++;
        else b++;
        if(a>=11 && (b<10 || a>=b+2)){
            break;
        }else if(b>=11 && (a<10 || b>=a+2)){
            break;
        }
    }
    printf("%d:%d\n",b,a);
    if(a>b){
        printf("jxq");
    }else{
        printf("ztz");
    }
}    
    
}cdvs6110;
