    #include<cstdio>  
    #include<cstdlib>  
    #include<cmath>  
    #include<algorithm>  
    using namespace std;  
    typedef long long ll;  
      
    inline char nc()  
    {  
        static char buf[100000],*p1=buf,*p2=buf;  
        if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }  
        return *p1++;  
    }  
      
    inline void read(int &x)  
    {  
        char c=nc(),b=1;  
        for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;  
        for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;  
    }  
      
    const int N=100005;  
      
    int n,k;  
    int m,g[N];  
    ll f[N][30];  
      
    bool dfs(int t,int x,int tem)  
    {  
        if (!x) return tem==n;  
        x--;  
        while (1)  
        {
            if (t+x>m) return 0;  
            if (f[t][x]>n || f[t][x]*tem>n) return 0;  
            if (dfs(t+1,x,tem*g[t])) return 1;  
            t++;  
        }
    }  
      
    int main()  
    {  
        freopen("data0.in","r",stdin);  
//        freopen("brute0.out","w",stdout);  
        int Q;  
        read(Q);  
        while (Q--)  
        {  
            read(n); read(k);  
            if((n==1 && k>=2) || (n>=3 && k>=n)) { printf("NIE\n"); continue; }  
            if(k<=2) { printf("TAK\n"); continue; }  
            int t; m=0;  
            for (t=1;t*t<n;t++)  
                if (n%t==0)  
                    g[++m]=t,g[++m]=n/t;  
            if (t*t==n) g[++m]=t;  
            sort(g+1,g+m+1);  
            ll tem=1;  
            for (int i=1;i<=m;i++,tem=1)  
                for (int j=0;j<k && i+j<=m;f[i][j++]=tem)  
                    if (tem<=n)  
                        tem*=g[i+j];  
            if (dfs(1,k,1))  
                printf("TAK\n");  
            else  
                printf("NIE\n");  
        }  
        fclose(stdout);
        return 0;  
    }  
