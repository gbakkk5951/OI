#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define For(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long double LD;

const int MAXN=105;
const LD eps=1e-8;
int n,q[MAXN],same[MAXN],pos[MAXN],no;
LD d[MAXN][MAXN],d12,di1,di2,mx,cosa,sina;
struct Point{LD x,y;}a[MAXN],ans[MAXN];

inline LD sqr(LD x){return x*x;}

inline LD dist(const Point &x,const Point &y){
	return sqrtl(sqr(x.x-y.x)+sqr(x.y-y.y));
}

/*void checker(){
	puts("check:");
	For(i,1,n){
		For(j,1,n) printf("%.6Lf ",sqrtl(sqr(ans[i].x-ans[j].x)+sqr(ans[i].y-ans[j].y)));
		puts("");
	}
}*/

int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	
	scanf("%d",&n);
	For(i,1,n){
		no=0;
		For(j,1,n){
			scanf("%Lf",&d[i][j]);
			if(i>j&&d[i][j]<eps) no=j;
		}
		if(!no) q[++q[0]]=i, pos[i]=q[0], same[i]=i; else same[i]=same[no];
	}
	a[1]=(Point){0,0}; a[2]=(Point){d[q[1]][q[2]],0};
	d12=a[2].x;
	no=1;
	For(i,3,q[0]){
		di1=d[q[i]][q[1]]; di2=d[q[i]][q[2]];
		mx=max(d12,max(di1,di2));
		if(fabsl(2*mx-(d12+di1+di2))>eps){
			swap(q[3],q[i]);
			swap(pos[q[3]],pos[q[i]]);
			no=0;
			break;
		}
	}
	if(no){			//in one line
		//puts("one line");
		For(i,3,q[0]){
			di1=d[q[i]][q[1]]; di2=d[q[i]][q[2]];
			if(di1+di2<d12+eps) a[i]=(Point){di1,0};
			else if(di1<di2) a[i]=(Point){-di1,0};
			else a[i]=(Point){di1,0};
		}
	}else{
		di1=d[q[3]][q[1]]; di2=d[q[3]][q[2]];
		cosa=(sqr(d12)+sqr(di1)-sqr(di2))/(2*d12*di1);
		//printf("cos: %lf\n",cosa);
		sina=sqrtl(1-sqr(cosa));
		a[3]=(Point){di1*cosa,di1*sina};
		
		For(i,4,q[0]){
			di1=d[q[i]][q[1]]; di2=d[q[i]][q[2]];
			cosa=(sqr(d12)+sqr(di1)-sqr(di2))/(2*d12*di1);
			sina=sqrtl(1-sqr(cosa));
			Point tmp1=(Point){di1*cosa,di1*sina};
			Point tmp2=(Point){tmp1.x,-tmp1.y};
			if(fabsl(dist(tmp1,a[3])-d[q[3]][q[i]])<fabsl(dist(tmp2,a[3])-d[q[3]][q[i]])) a[i]=tmp1; else a[i]=tmp2;
		}
	}
	
	For(i,1,n){
		ans[i]=a[pos[same[i]]];
		printf("%.6Lf %.6Lf\n",ans[i].x,ans[i].y);
	}
	
	//checker();
	
	return 0;
}
