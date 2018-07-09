#include <bits/stdc++.h>
using namespace std;

const int N = 1000+5;
char arr[N];
int f[N/2][N];//从坐标i往后j代价能否实现，实现为1
int n, m;
int dp(){
    memset(f,0,sizeof(f));
    //注意边界条件
    f[n/2][0] = 1;
    for(int i=n/2-1; i>=0; i--){
        if(arr[i]==arr[i+n/2]){
            for(int j=0; j<=m; j++)
                f[i][j] = f[i+1][j];//不改
            for(int j=0; j<=m-2; j++)
            if(f[i+1][j])
                f[i][j+2] = 1;//改两个
            continue;
        }
        for(int j=0; j<=m-1; j++)
        if(f[i+1][j])
            f[i][j+1] = 1;//改一个
        for(int j=0; j<=m-2; j++)
        if(f[i+1][j])
            f[i][j+2] = 1;//改两个
    }
    if(f[0][m]) return 0;
    return 1;
}
void change(){
    int len=m, tmp;
    for(int i=0; i<n/2; i++)
    for(int j=0; j<26; j++){
        tmp = 0;
        if(arr[i] != j+'a') tmp++;
        if(arr[i+n/2] != j+'a') tmp++;
        if(f[i+1][len-tmp]){
            arr[i] = arr[i+n/2] = j+'a';
            len -= tmp;
            break;
        }
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t-->0){
        scanf("%d%d", &n, &m);
        getchar();
		scanf("%s", arr);
        //判断是否存在
        if(dp()){
            printf("Impossible\n");
            continue;
        }
        //以字典序最小原则改动原数组
        change();
		printf("%s", arr);
    }
    return 0;
}
