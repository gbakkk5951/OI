#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include <ctime>
#define N 1200005
#define M 300005
#define pi acos(-1)
#define E complex
using namespace std;
struct complex
{
    double x,y;
    complex(double _x,double _y){x=_x;y=_y;}
    complex(){;}
    friend complex operator * (const complex &a,const complex &b)
    {
        complex c;c.x=a.x*b.x-a.y*b.y;c.y=a.x*b.y+a.y*b.x;return c;
    }
    friend complex operator / (complex a,double b)
    {
        return complex(a.x/b,a.y/b);
    }
    friend complex operator + (complex a,complex b)
    {
        return complex(a.x+b.x,a.y+b.y);
    }
    friend complex operator - (complex a,complex b)
    {
        return complex(a.x-b.x,a.y-b.y);
    }
};
int R[N];int n;
void fft(E *a,int f)
{
    for(int i=0;i<n;i++)if(i<R[i])swap(a[i],a[R[i]]);
    for(int i=1;i<n;i<<=1)
    {
        E wn(cos(pi/i),f*sin(pi/i));
        for(int j=0;j<n;j+=(i<<1))
        {
            E w(1,0);
            for(int k=0;k<i;k++,w=w*wn)
            {
                E x=a[j+k],y=w*a[j+k+i];
                a[j+k]=x+y;a[j+k+i]=x-y;
            }
        }
    }
    if(f==-1)for(int i=0;i<n;i++)a[i]=a[i]/n;
}
int nn,mm;
char s1[M],s2[M],s3[M];
E a1[N],b1[N],c1[N];
int ans[N];
int st[M],top;
int main()
{
    /*
    nn = 150000, mm = 300000;
    for (int i = 0; i < nn; i++) {
        s3[i] = '*';
    } 
    for (int j = 0; j < mm; j++) {
        s2[j] = '*';
    }
    float ta = clock();
    */
    scanf("%d%d",&nn,&mm);
    scanf("%s",s3);scanf("%s",s2);
    
    int l=0;
    for(n=1;n<2*mm;n<<=1)l++;
    for(int i=0;i<n;i++)R[i]=(R[i>>1]>>1)|((i&1)<<(l-1));
    for(int i=0;i<nn;i++)s1[i]=s3[nn-i-1];
    for(int i=0;i<mm;i++)
    {
        int tmp=s2[i]-'a'+1;double p=tmp+0.0;
        if(s2[i]=='*')p=0;
        b1[i].x=p;
    }
    for(int i=0;i<nn;i++)
    {
        int tmp=s1[i]-'a'+1;double p=tmp+0.0;
        if(s1[i]=='*')p=0;
        a1[i].x=p*p*p;
    }
    fft(a1,1);fft(b1,1);
    for(int i=0;i<n;i++)c1[i]=a1[i]*b1[i];
    for(int i=0;i<n;i++)a1[i].x=a1[i].y=b1[i].x=b1[i].y=0;
    
    for(int i=0;i<mm;i++)
    {
        int tmp=s2[i]-'a'+1;double p=tmp+0.0;
        if(s2[i]=='*')p=0;
        b1[i].x=p*p;
    }
    for(int i=0;i<nn;i++)
    {
        int tmp=s1[i]-'a'+1;double p=tmp+0.0;
        if(s1[i]=='*')p=0;
        a1[i].x=p*p;
    }
    fft(a1,1);fft(b1,1);
    for(int i=0;i<n;i++)c1[i]=c1[i]-(a1[i]*b1[i]),c1[i]=c1[i]-(a1[i]*b1[i]);
    for(int i=0;i<n;i++)a1[i].x=a1[i].y=b1[i].x=b1[i].y=0;

    for(int i=0;i<mm;i++)
    {
        int tmp=s2[i]-'a'+1;double p=tmp+0.0;
        if(s2[i]=='*')p=0;
        b1[i].x=p*p*p;
    }
    for(int i=0;i<nn;i++)
    {
        int tmp=s1[i]-'a'+1;double p=tmp+0.0;
        if(s1[i]=='*')p=0;
        a1[i].x=p;
    }
    fft(a1,1);fft(b1,1);
    for(int i=0;i<n;i++)c1[i]=c1[i]+(a1[i]*b1[i]);
    
    fft(c1,-1);

    for(int i=nn-1;i<mm;i++)
    {
        if(fabs(c1[i].x)<0.5)
        {
            st[++top]=i-nn+2;
        }
    }
    
    printf("%d\n",top);
    for(int i=1;i<=top;i++)
    {
        if(i!=top)printf("%d ",st[i]);
        else printf("%d\n",st[i]);
    }
    /*
    printf("uese %lf", clock() - ta);
    */
    return 0;
}
