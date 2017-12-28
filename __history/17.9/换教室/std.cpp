//It is made by ljh2000
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;
typedef long long LL;
const int MAXN = 2011;
const int MAXD = 311;
const int inf = (1<<29); 
int n,m,D,bian,c[MAXN],d[MAXN],dis[MAXD][MAXD];
double f[MAXN][MAXN][2],k[MAXN],ans;

inline int getint(){
    int w=0,q=0; char c=getchar(); while((c<'0'||c>'9') && c!='-') c=getchar();
    if(c=='-') q=1,c=getchar(); while (c>='0'&&c<='9') w=w*10+c-'0',c=getchar(); return q?-w:w;
}

inline void work(){
    n=getint(); m=getint(); D=getint(); bian=getint(); int x,y,z,lim; double minl;
    for(int i=1;i<=n;i++) c[i]=getint(); for(int i=1;i<=n;i++) d[i]=getint(); for(int i=1;i<=n;i++) scanf("%lf",&k[i]);
    for(int i=1;i<=D;i++) for(int j=1;j<=D;j++) dis[i][j]=inf;
    for(int i=1;i<=bian;i++) {
        x=getint(); y=getint(); z=getint();    if(dis[x][y]==inf) dis[x][y]=dis[y][x]=z;
        else dis[x][y]=min(dis[x][y],z),dis[y][x]=dis[x][y];
    }
    for(int l=1;l<=D;l++) for(int i=1;i<=D;i++) if(i!=l) for(int j=1;j<=D;j++) if(j!=l&&i!=j) dis[i][j]=min(dis[i][l]+dis[l][j],dis[i][j]); 
    for(int i=1;i<=n;i++) for(int j=0;j<=m;j++) f[i][j][0]=f[i][j][1]=1e30;
	
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			f[i][j][0]=f[i][j][1]=1000000000.0;
		}
	}	
	
	f[1][0][0]=f[1][1][1]=0; 
    for(int i=1;i<=D;i++) dis[i][i]=0;
    for(int i=2;i<=n;i++) {
        lim=min(i,m);
        for(int j=0;j<=lim;j++) {
            minl=f[i-1][j][1]+dis[c[i-1]][c[i]]*(1.0-k[i-1])+dis[d[i-1]][c[i]]*k[i-1];
            minl=min(minl,f[i-1][j][0]+dis[c[i-1]][c[i]]);
            f[i][j][0]=min(f[i][j][0],minl);
            if(j>=1) {
                minl=f[i-1][j-1][1]+dis[c[i-1]][c[i]]*(1.0-k[i])*(1.0-k[i-1])+dis[c[i-1]][d[i]]*(1.0-k[i-1])*k[i];
                minl+=dis[d[i-1]][c[i]]*k[i-1]*(1-k[i])+dis[d[i-1]][d[i]]*k[i-1]*k[i];
                minl=min(minl,f[i-1][j-1][0]+dis[c[i-1]][d[i]]*k[i]+dis[c[i-1]][c[i]]*(1.0-k[i]));
                f[i][j][1]=min(f[i][j][1],minl);
            }
        }
    }
    
    printf("%d %d %f %f\n",dis[c[4-1]][c[4]],dis[d[4-1]][c[4]],k[4-1],k[4]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf("%d %d %lf %lf; ",i,j,f[i][j][0],f[i][j][1]);
		}
		printf("\n");
	}
    ans=1e30; for(int i=0;i<=m;i++) ans=min(ans,min(f[n][i][0],f[n][i][1]));
    printf("%.2lf",ans);
}

int main()
{
	freopen("classroom9.in","r",stdin);
    work();
    return 0;
}
