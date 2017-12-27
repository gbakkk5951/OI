#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#define int long long
using namespace std;
int read()
{
    int sum;char c;bool neg=0;
    while(!isdigit(c=getchar()))if(c=='-')neg=1;sum=c-'0';
    while(isdigit(c=getchar())){sum*=10;sum+=c-'0';}
    return neg?-sum:sum;
}
int mp[2210][2210],row[2210],col[2210];
signed main()
{
//	freopen("torch0.in","r",stdin);
//	freopen("lyd0.out","w",stdout);
    int i,j,n,m,l,r,a,b,tmp,ans=0,p,q;
    n=read();m=read();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            a=read(),b=read();
            if(!b)continue;
             
            //bottom
            tmp=min(i+b-1,n);l=max(j-(b-(tmp-i)-1),1LL),r=min(j+(b-(tmp-i)-1),m);
            if(tmp==n)
            {
                row[r-1]+=a;row[l-1]-=a;
            }
            mp[tmp][r]+=a;mp[tmp-1][r]+=a;
             
            //right
            tmp=min(j+b-1,m);l=max(i-(b-(tmp-j)-1LL),1LL),r=min(i+(b-(tmp-j)-1),n);
            if(tmp==m)
            {
                col[r-1]+=a;col[l-1]-=a;
            }
            mp[r-1][tmp+1]-=a;mp[r-1][tmp]-=a;
             
            //left
            tmp=max(j-b+1,1LL);l=max(i-(b-(j-tmp)-1),1LL);
            mp[l-1][tmp-1]-=a;mp[l-1][tmp]-=a;
             
            //top
            tmp=max(i-b+1,1LL);l=max(j-(b-(i-tmp)-1),1LL);
            if(tmp>1)mp[tmp-2][l]+=a;mp[tmp-1][l]+=a;
        }
    }
    for(i=0;i<=n+1;i++)
    {
        int lim=min(m+1,i);
        for(j=1;j<=lim;j++)
        {
            mp[i-j][j]+=mp[i-j+1][j-1];
        }
    }
    for(i=1;i<=m+1;i++)
    {
        int lim=min(n+1,m+1-i);
        for(j=1;j<=lim;j++)
        {
            mp[n+1-j][i+j]+=mp[n+1-j+1][i+j-1];
        }
    }
    for(i=m+1;i>=0;i--)
    {
        row[i]+=row[i+1];
        mp[n][i]+=row[i];
    }
    for(i=n+1;i>=0;i--)
    {
        col[i]+=col[i+1];
        mp[i][m]+=col[i];
    }
    for(i=1;i<=m;i++)
    {
        int lim=min(n,i);
        for(j=1;j<lim;j++)
        {
            mp[n-j][i-j]+=mp[n-j+1][i-j+1];
        }
    }
    for(i=1;i<n;i++)
    {
        int lim=min(i,m);
        for(j=1;j<lim;j++)
        {
            mp[i-j][m-j]+=mp[i-j+1][m-j+1];
        }
    }/*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
           	printf("%lld ",mp[i][j]);
        }
        printf("\n");
    }*/
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(mp[i][j]<=read())ans++;
        }
    }
    printf("%lld\n",ans);
//    fclose(stdout);
	return 0;
}
