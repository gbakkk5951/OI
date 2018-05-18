/**************************************************************
    Problem: 3165
    User: idy002
    Language: C++
    Result: Accepted
    Time:1492 ms
    Memory:4244 kb
****************************************************************/
 
#include <cstdio>
#include <cmath>
#include <vector>
#define lson nd<<1
#define rson nd<<1|1
#define maxn 100010
#define modx 39989
#define mody 1000000000
#define eps 1e-10
using namespace std;
 
int sg( double x ) {
    return (x>-eps)-(x<eps);
}
struct Line {
    int lf, rg;
    double k, b;
    Line(){}
    Line( int x0, int y0, int x1, int y1 ) {
        lf = min( x0, x1 );
        rg = max( x0, x1 );
        if( x0==x1 ) {
            k = 0.0;
            b = max( y0, y1 );
        } else {
            k = (y1-y0+0.0)/(x1-x0);
            b = y1-x1*k;
        }
    }
    inline double f( int x ) {
        return k*x+b;
    }
    inline double cx( Line &c ) {
        return (c.b-b)/(k-c.k);
    }
};
 
int n;
int ltot;
Line lns[maxn];
int v[(modx+10)<<2];
int wi[modx+10];
double wy[modx+10];
 
void update( int x, int i ) {
    double ny = lns[i].f(x);
    int s=sg(ny-wy[x]);
    if( !wi[x] || (s>0 || (s==0&&i<wi[x])) ) {
        wi[x] = i;
        wy[x] = ny;
    }
}
void modify( int i, int nd, int lf, int rg ) {
    if( lns[i].lf<=lf && rg<=lns[i].rg ) {
        if( !v[nd] ) {
            v[nd] = i;
            return;
        }
        bool lu = sg( lns[i].f(lf)-lns[v[nd]].f(lf) )>0;
        bool ru = sg( lns[i].f(rg)-lns[v[nd]].f(rg) )>0;
        int mid=(lf+rg)>>1;
        if( lu && ru ) {
            v[nd] = i;
        } else if( lu || ru ) {
            int lm = floor( lns[i].cx( lns[v[nd]] ) );
            if( lm<=mid && lu ) {
                modify( i, lson, lf, mid );
            } else if( lm<=mid && ru ) {
                modify( v[nd], lson, lf, mid );
                v[nd] = i;
            } else if( lu ) {
                modify( v[nd], rson, mid+1, rg );
                v[nd] = i;
            } else {
                modify( i, rson, mid+1, rg );
            }
        } else {
            update( lf, i );
            update( rg, i );
        }
        return;
    }
    int mid = (lf+rg)>>1;
    if( lns[i].lf<=mid ) modify( i, lson, lf, mid );
    if( lns[i].rg>mid ) modify( i, rson, mid+1, rg );
}
int query( int x ) {
    int nd = 1;
    int lf = 1, rg = modx;
    int rt = 0;
    double cury = -1.0;
    while(1) {
        if( v[nd] ) {
            double ny = lns[v[nd]].f(x);
            int s = sg( ny-cury );
            if( s>0 || (s==0&&v[nd]<rt) ) {
                rt = v[nd];
                cury = ny;
            }
        }
        if( lf==rg ) break;
        int mid=(lf+rg)>>1;
        if( x<=mid ) {
            nd = lson;
            rg=mid;
        } else {
            nd = rson;
            lf=mid+1;
        }
    }
    int s = sg( wy[x]-cury );
    if( s>0 || (s==0&&wi[x]<rt) )
        return wi[x];
    return rt;
}
 
int main() {
	freopen("seg0.in", "r", stdin);
    int T, lastans=0;
    scanf( "%d", &T );
    while( T-- ) {
        int opt;
        scanf( "%d", &opt );
        if( opt==0 ) {
            int x;
            scanf( "%d", &x );
            x = ((x+lastans-1)%modx+1);
            printf( "%d\n", lastans=query(x) );
        } else {
            int x0, y0, x1, y1;
            scanf( "%d%d%d%d", &x0, &y0, &x1, &y1 );
            x0 = (x0+lastans-1)%modx+1;
            y0 = (y0+lastans-1)%mody+1;
            x1 = (x1+lastans-1)%modx+1;
            y1 = (y1+lastans-1)%mody+1;
            lns[++ltot] = Line(x0,y0,x1,y1);
            modify( ltot, 1, 1, modx );
        }
    }
}
