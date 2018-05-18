#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
using namespace std;
typedef long long s64;

const int Max = 1000005;
const int ONE = 1000005;

int n,Q;
int Num[ONE];

int get()
{
        int res=1,Q=1;    char c;
        while( (c=getchar())<48 || c>57)
        if(c=='-')Q=-1;
        if(Q) res=c-48; 
        while((c=getchar())>=48 && c<=57) 
        res=res*10+c-48; 
        return res*Q; 
}

int main()
{      
    	freopen("meet.in","r",stdin);
    	freopen("meet.out","w",stdout);
    	n=get();	Q=get();
    	while(Q--)
    	printf("YES\n");
}
