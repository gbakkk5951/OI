#include<cstdio>
int n,p[200010],s[200010],t[200010];
bool vis[200010];
int F(){
    char c;while((c=getchar())<'0'||c>'9');
    int a=c-'0';while((c=getchar())>='0'&&c<='9')a=a*10+c-'0';
    return a;
}
int dif(int x,int y){return x>y?x-y:y-x;}
int main(){
    n=F();
    for(int i=0;i<n;i++)p[i]=F()-1;
    for(int i=0;i<n;i++)t[s[i]=F()-1]=i;
    long long s=0;
    for(int i=0;i<n;i++)s+=dif(i,t[p[i]]);
    printf("%lld\n",s/2);
}
