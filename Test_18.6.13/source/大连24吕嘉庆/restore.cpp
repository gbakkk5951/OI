#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const double eps = 0.000001;
struct pot {double x,y;};
bool operator < (const pot &x,const pot &y) {if (fabs(x.x - y.x) < eps) return x.x < y.x;return x.y < y.y;}
pot sec[105];
double dis[105][105];
int n;
bool check_same(pot x,pot y) {return fabs(x.x - y.x) < eps && fabs(x.y - y.y) < eps;}
double sqr(double x) {return x * x;}
vector <pot> query_bin(int x,int y,int k)
{
	vector <pot> res;
	double r[2],len,p,q;
	pot mid;
	//求p,q
	r[0] = dis[x][k];r[1] = dis[y][k];
	len = sqrt(sqr(sec[x].x - sec[y].x) + sqr(sec[x].y - sec[y].y));
	p = (sqr(r[0]) - sqr(r[1]) + sqr(len)) / 2 * len;
	q = sqrt(sqr(r[0]) - sqr(p));
	//求mid的坐标
	mid.x = sec[x].x + p * (sec[y].x - sec[x].x) / len;
	mid.y = sec[x].y + p * (sec[y].y - sec[x].y) / len;
	// 
	res.resize(2);
	res[0].y = mid.y + q * (mid.x - sec[x].x) / p;
	res[1].y = mid.y - q * (mid.x - sec[x].x) / p;
	res[0].x = mid.x - q * (mid.y - sec[x].y) / p;
	res[1].x = mid.x + q * (mid.y - sec[x].y) / p; 
	return res;
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			scanf("%lf",&dis[i][j]);
	sec[1].x = sec[1].y = 0.0;
	sec[2].x = dis[1][2]; sec[2].y = 0.0;
	for (int o = 3;o <= n;o++)
	{
		vector <pot> trs;
		for (int i = 1;i <= o - 1;i++)
		{
			for (int j = i + 1;j <= o - 1;j++)
			{
				vector <pot> tmp = query_bin(i,j,o);
				if (trs.empty()) 
				{
					trs = tmp;
					continue;
				}
				for (int t = 0;t < trs.size();t++) tmp.push_back(trs[t]);
				trs.clear();
				sort(tmp.begin(),tmp.end());
				for (int t = 1;t < tmp.size();t++)
					if (check_same(tmp[t],tmp[t - 1]) && !check_same(tmp[t],trs[trs.size() - 1])) trs.push_back(tmp[t]);
			}
		}
		sec[o].x = trs[0].x; sec[o].y = trs[0].y;
	}
	for (int i = 1;i <= n;i++) printf("%.6f %.6f\n",sec[i].x,sec[i].y);
	return 0;
}
