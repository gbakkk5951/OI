#include<bits/stdc++.h>
#define lli long long int
#define debug cerr
using namespace std;

inline bool judge(int m)
{
    int sq = sqrt(m);
    for(int i=2;i<=sq;i++)
        if(!(m%i)) return 0;
    return 1;
}

int _rand()
{
	int ret=rand();
	ret |= rand()<<15;
	return ret;
}


int main()
{
    srand(time(0));
    freopen("arg.txt","r",stdin);
    int arg,n,m;
    scanf("%d",&arg);
    
    //debug<<"arg = "<<arg<<endl;
    
    if( arg < 5 )
    {
        n = arg +5,m=_rand() % 10 + 10;
        while(judge(m)) m=_rand() % 10 + 10;;
    }
    else if( arg < 10 )
    {
        n = arg*10,m=_rand() % 100 + 100;
        while(judge(m)) m=_rand() % 100 + 100;
    }
    else
    {
        n = (arg - 9)*1000,m=_rand() % ((int) 1e8) + 8e8;
        while(judge(m)) m=_rand() % ((int) 1e8) + 8e8;
    }
    
    //debug<<"n = "<<n<<"m = "<<m<<endl;
    
    printf("%d %d\n",n,m);
    
    while(n--)
    {
        int t;
        if(arg < 5)
        {
            t = _rand() % 10 + 10;
            while(__gcd(t,m)==1) t = _rand() % 10 + 10;
        }
        else
        {
            t=_rand()+1;
            while(__gcd(t,m)==1) t=_rand()+1;
        }
        printf("%d ",t);
    }
    puts("");
    
    fclose(stdout);
    
    return 0;
}
    
    
    
    
    
