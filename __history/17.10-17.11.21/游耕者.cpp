#include<cstdio>
char s[35],c;void o(int a){while(a)s[c++]=c%10,c/=10;while(c--)putchar('0'+s[c]);putchar(' ');}int main(){int n,i;scanf("%d",&n);for(i=0;i<=n;i++)printf("%d ",i%n+1);}
