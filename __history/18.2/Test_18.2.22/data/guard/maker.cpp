#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int maxn = 50;
const int cas = 10;

inline int get(int a)
{
    return ((rand() << 15) ^ rand()) % a + 1;
}

bool mp[55][105][105];
int n;
int K[55];

inline bool adde(int a,int b,int c, ostream& out){
    if (mp[c][a][b]) return false;
    mp[c][a][b]=mp[c%n+1][b][a]=true;
    out<<a<<' '<<b<<' '<<c<<'\n';
    return true;
}

inline void build(int t, ostream &out)
{
    memset(mp,0,sizeof(mp));
    if (t < cas * 0.3)
    {
        n = 3;
        int a = get(7), b = get(7);
        int c = 20 - a - b;
        K[1]=a;
        K[2]=b;
        K[3]=c;
        K[4]=a;
        out<<"3\n";
        adde(a,b,1,out);
        adde(b,c,2,out);
        int m = 10;
        while(m>0){
            int g=get(n);
            int x=get(K[g]),y=get(K[g+1]);
            m-=adde(x,y,g,out);
        }
        adde(c,a,3,out);
    }
    else if (t < cas * 0.6){
        n=get(10)+17;
        if ((n&1)==0) n--;
        out<<n<<'\n';
        for (int i=1;i<=n;++i) K[i]=1;
        for (int i=n;i<100&&i<n*5;++i){
            int x;
            do{
                x=get(n);
            }while(K[x]==5);
            ++K[x];
        }
        K[n+1]=K[1];
        int m=100;
        int fl=0;
        while(m>0){
            int g=get(n);
            int x=get(K[g]),y=get(K[g+1]);
            if (adde(x,y,g,out)) --m,fl=0;
            ++fl;
            if (fl>100) break;
        }
        for (int i=1;i<=n;++i) adde(K[i],K[i+1],i,out);
    }
    else{
        n=11;
        out<<n<<'\n';
        for (int i=1;i<=n;++i) K[i]=1;
        for (int i=n;i<100;++i){
            int x;
            do{
                x=get(n);
            }while(K[x]>=10);
            ++K[x];
        }
        K[n+1]=K[1];
        int m=800;
        int fl=0;
        while(m>0){
            int g=get(n);
            int x=get(K[g]),y=get(K[g+1]);
            if (adde(x,y,g,out)) --m,fl=0;
            ++fl;
            if (fl>100) break;
        }
        for (int i=1;i<=n;++i) adde(K[i],K[i+1],i,out);
    }
}

int main()
{
    char tmp[100];
    srand(time(0));
    for (int i = 0; i < cas; ++i)
    {
        sprintf(tmp, "guard%d.in", i + 1);
        ofstream out(tmp);
        build(i, out);
        out.close();
        sprintf(tmp, "guard.exe < guard%d.in > guard%d.ans", i + 1, i + 1);
        system(tmp);
    }
    return 0;
}