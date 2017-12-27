#include<cstdio>
#include<cstring>
int cnt;
char sa[510],sb[1000010];
int la,lb;
int main(){
    int i,j,k;
    scanf("%s",sa);
    la=strlen(sa);
    scanf("%s",sb);
    lb=strlen(sb);
    for(i=0;i<=lb-la;i++){
        for(j=0;j<la;j++){
            if(sa[j]!=sb[i+j])
            break;
            else
            {if(j==la-1)
                cnt++;
            }
            
        }
        
    }
    printf("%d",cnt);  
    
    
}
