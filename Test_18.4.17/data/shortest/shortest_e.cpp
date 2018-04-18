#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)

using namespace std;

typedef	long long	int64;


FILE	*Finn, *Fout, *Fstd, *Fres, *Fmsg;
int score;

const	int	maxn = 100005;

int	n,m,K,first[100001],where[2000001],l,v[2000001],next[2000001],type[2000001],c[2000001],dist[100001];
bool b[100001],B[100001];

void	Return(int p, char* s)
{
	fprintf(Fres, "%d\n", p);
	fprintf(Fmsg, "%s\n", s);
	exit(0);
}

inline void makelist(int x,int y,int z,int Q){
    where[++l]=y;
    v[l]=z;
    type[l]=Q;
    next[l]=first[x];
    first[x]=l;
}

inline void spfa(){
    memset(B,false,sizeof(B));
    memset(dist,127,sizeof(dist));
    dist[1]=0;c[1]=1;
    for (int k=1,l=1;l<=k;l++)
    {
        int m=c[l];
        B[m]=false;
        for (int x=first[m];x;x=next[x])
            if (!b[type[x]] && dist[m]+v[x]<dist[where[x]])
            {
                dist[where[x]]=dist[m]+v[x];
                if (!B[where[x]]) B[where[x]]=true,c[++k]=where[x];
            }
    }
}

int	main(int args, char** argv)
{
	Finn = fopen(argv[1], "r");
	Fstd = fopen(argv[3], "r");
	Fout = fopen(argv[2], "r");
	Fres = fopen(argv[5], "w"); 
	Fmsg = fopen(argv[6], "w"); 
	sscanf(argv[4], "%d", &score);
/*
	Finn = fopen("hamming1.in", "r");
	Fstd = fopen("hamming1.out", "r");
	Fout = fopen("hammingx.out", "r");
	Fres = fopen("res.txt", "w");
*/	
	int s1,s2,s3,s4;
	fscanf(Fstd,"%d%d%d%d",&s4,&s3,&s2,&s1);
	memset(first,0,sizeof(first));
	l=0;
	fscanf(Finn,"%d%d%d",&n,&m,&K);
	for (int i=1;i<=m;i++)
	{
        int x,y,z;
	    fscanf(Finn,"%d%d%d",&x,&y,&z);
	    makelist(x,y,z,i);
	    makelist(y,x,z,i);
     }
     int Q;
	 fscanf(Fout,"%d",&Q);
	 if (Q>K) Return(0,"删边太多"); 
     memset(b,false,sizeof(b));
     for (int i=1;i<=Q;i++) 
     {
         int x;
	     fscanf(Fout,"%d",&x);
	     if (x<1 || x>m) Return(0,"边越界");
	     if (b[x]) Return(0,"一条边删多次");
         b[x]=true;
     }
     spfa(); 
     if (dist[n]>1<<30) Return(0,"不连通");
     else
     if (dist[n]>s4) Return(12,"你太强了"); 
     else
     if (dist[n]==s4) Return(10,"正确");
     else 
     if (dist[n]>=s3) Return(8,"不是最优解");
     else 
     if (dist[n]>=s2) Return(5,"不是最优解");
     else 
     if (dist[n]>=s1) Return(3,"不是最优解");
     else  Return(1,"不是最优解");
}
