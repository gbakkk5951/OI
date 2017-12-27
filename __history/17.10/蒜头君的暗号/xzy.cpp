#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug cout
using namespace std;
const int maxn=2e2+1e1;
 
int in[maxn],n,k;
char str[maxn],out[maxn];
class Matrix
{
private:
    int dat[maxn][maxn];
public:
    Matrix(const int &arg=0)
    {
        memset(dat,0,sizeof(dat));
        if(arg==1)
            for(int i=1;i<=n;i++)
                dat[i][i]=1;
    }
    int* operator [] (const int &x)
    {
        return dat[x];
    }
    void convert(int* x)
    {
        for(int i=1;i<=n;i++)
            dat[i][x[i]]=1;
    }
    friend Matrix operator * (Matrix &a,Matrix &b)
    {
        Matrix ret;
        for(int i=1;i<=n;i++)
            for(int k=1;k<=n;k++)
            {
                const register int t = a[i][k];
                for(int j=1;j<=n;j++)
                    ret[i][j] += t * b[k][j];
            }
        return ret;
    }
}base,ans;
 
inline Matrix fastpow(const Matrix &base,int tme)
{
    Matrix ret=Matrix(1),now=base;
    //for(int i=1;i<=n;i++) debug<<ret[i]<<" ";debug<<endl;
    while(tme)
    {
        if(tme&1) ret = ret*now;
        now = now * now;
        tme >>= 1;
    }
    return ret;
}
inline void getstr(char* dst,int s)
{
    char *pos=dst,*lim=dst+s,ch=getchar();
    while(ch=='\n') ch=getchar();
    while(ch!='\n' && pos <= lim)
        *pos++ = ch,
        ch=getchar();
}
 
int main()
{
	freopen("info19.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",in+i);
    //scanf("\n%[^\n]",str+1);
    getstr(str+1,n);
    for(int i=1;i<=n;i++)
        if( ! str[i] )
            str[i] = ' ';
    base.convert(in);
    //for(int i=1;i<=n;i++) debug<<in[i]<<" ";debug<<endl;
    ans = fastpow(base,k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(ans[i][j])
            {
                //debug<<"i = "<<i<<"j = "<<j<<endl;
                out[j] = str[i];
            }
    }
    //for(int i=1;i<=n;i++) debug<<(int)out[i]<<" ";debug<<endl;
    puts(out+1);
    return 0;
}
