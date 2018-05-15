#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=2000005;
int n,wa[N],wb[N],wv[N],wsu[N],sa[N],rk[N],he[N],b[N],st[25][N];
char s[N];
bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void saa(char *r,int n,int m)
{
    int *x=wa,*y=wb;
    for(int i=0;i<m;i++)
        wsu[i]=0;
    for(int i=0;i<n;i++)
        wsu[x[i]=r[i]]++;
    for(int i=1;i<m;i++)
        wsu[i]+=wsu[i-1];
    for(int i=n-1;i>=0;i--)
        sa[--wsu[x[i]]]=i;
    for(int j=1,p=1;j<=n&&p<=n;j<<=1,m=p)
    {
        p=0;
        for(int i=n-j;i<n;i++)
            y[p++]=i;
        for(int i=0;i<n;i++)
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        for(int i=0;i<n;i++)
            wv[i]=x[y[i]];
        for(int i=0;i<m;i++)
            wsu[i]=0;
        for(int i=0;i<n;i++)
            wsu[wv[i]]++;
        for(int i=1;i<m;i++)
            wsu[i]+=wsu[i-1];
        for(int i=n-1;i>=0;i--)
            sa[--wsu[wv[i]]]=y[i];
        swap(x,y);
        x[sa[0]]=0;
        p=1;
        for(int i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(int i=0;i<n;i++)
        rk[sa[i]]=i;
    int k=0,j;
    for(int i=0;i<n-1;he[rk[i++]]=k)
        for(k?k--:0,j=sa[rk[i]-1];r[i+k]==r[j+k];k++);
}
int ques(int x,int y)
{//cerr<<x<<" "<<y<<endl;
	int l=min(x,y)+1,r=max(x,y),k=b[r-l+1];
	if(r>n||l>r)
		return 0;
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
bool pd(int k)
{
    for(int i=1;i<=n;i++)
		if((sa[i]+k<=n&&ques(i,rk[sa[i]+k])>=k)||(sa[i]>k&&ques(i,rk[sa[i]-k])>=k))
			return 1;
	return 0;
}
bool ok(int k)
{
    int mx=sa[1],mn=sa[1];
    for(int i=2;i<=n;i++)
	{
        if(he[i]<k)
			mx=mn=sa[i];
        else
		{
            mn=min(mn,sa[i]);
            mx=max(mx,sa[i]);
            if(mx-mn>k)
				return 1;
        }
    }
    return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	gets(s);
	n=strlen(s);
    saa(s,n+1,200);
	// for(int i=0;i<=n;i++)
		// cerr<<sa[i]<<" "<<he[i]<<endl;
	b[0]=-1;
	for(int i=1;i<=n;i++)
		b[i]=b[i>>1]+1;
	for(int i=1;i<=n;i++)
		st[0][i]=he[i];
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);//cerr<<"ok"<<endl;
	if(n<=10000)
	{
		int ans;
		for(ans=n/2;ans>=0;ans--)
			if(pd(ans))
				break;
		printf("%d\n",ans*2);
		return 0;
	}
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;//cerr<<mid<<endl;
		if(ok(mid))
			l=mid+1,ans=mid;
		else
			r=mid-1;
	}
	for(;ans>=0;ans--)
		if(pd(ans))
			break;
	printf("%d\n",ans*2);
	return 0;
}