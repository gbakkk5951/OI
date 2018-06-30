#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define eps 1e-9
#define N 510
using namespace std;
struct point
{
    double x , y;
    point() {}
    point (double a , double b) {
		x = a ; y = b;
	}
    point operator + (const point &a) const {
		return point(x + a.x , y + a.y);
	}
    point operator - (const point &a) const {
		return point(x - a.x , y - a.y);
	}
    point operator * (const double &a) const {
		return point(a * x , a * y);
	}
}p[N];

struct line
{
    point p , v;
    double ang;
}a[N] , q[N] , c[N];

inline double cross(point a , point b) {
	return a.x * b.y - a.y * b.x;
}

inline bool left(line a , point b) {
	return cross(a.v , b - a.p) > eps;
}

inline point inter(line a , line b) {
    point u = a.p - b.p;
    double tmp = cross(b.v , u) / cross(a.v , b.v);
    return a.p + a.v * tmp;
}

bool cmp(const line &a , const line &b) {
	if (fabs(a.ang - b.ans) < eps) {
		return left(a, b.p);
	}
    return a.ang < b.ang;
}

int main() {
    int n , i , j , m , cnt = 0 , tot = 1 , l = 1 , r = 1;
    double ans = 0;
    scanf("%d" , &n);
    for(i = 1; i <= n; i++) {
        scanf("%d" , &m);
        for(j = 1; j <= m; j++) {
			scanf("%lf%lf" , &p[j].x , &p[j].y);
		}
        for(j = 1; j <= m; j++) {
			a[++cnt].p = p[j];
			a[cnt].v = p[j] - p[j % m + 1];
			a[cnt].ang = atan2(a[cnt].v.y , a[cnt].v.x);
		}
    }
    sort(a + 1, a + cnt + 1, cmp);
    for(i = 2; i <= cnt; i++) {
        if(fabs(a[i].ang - a[i - 1].ang) > eps) {
			a[++tot] = a[i];
		}
	}
    q[1] = a[1];
    for(i = 2; i <= tot; i++) {
        while (l < r && left(a[i], p[r - 1])) {
			r--;
		} 
        while (l < r && left(a[i], p[l])) {
			l++;
		}
        q[++r] = a[i];
        if(l < r) {
			p[r - 1] = inter(q[r - 1] , q[r]);
		}
    }
	while(l < r && left(q[l], p[r - 1])) {
		r--;
	}
    p[r] = inter(q[l], q[r]);
	p[r + 1] = p[l];
    for (i = l; i <= r; i++) {
		ans += cross(p[i], p[i + 1]);
	}
    printf("%.3lf\n" , ans / 2.0);
    return 0;
}
