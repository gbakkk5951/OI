#include <cstring>
#include <cstdio>
const int MXN = 305;
const int INF = 0x3f3f3f3f;
int match[MXN], lx[MXN], ly[MXN], slack[MXN];
int G[MXN][MXN];
char visx[MXN], visy[MXN];
int n, nx, ny, ans;

char dfs(int x) {
	int tmp;
    visx[x] = true;
    for (int y = 0; y < ny; ++y) {
        if (visy[y]) continue;
        tmp = lx[x] + ly[y] - G[x][y];
        if (tmp == 0){//(x,y)在相等子图中
            visy[y] = 1;
            if (match[y] == -1 || dfs(match[y])) {
                match[y] = x;
                return 1;
            }
        } else {//(x,y)不在相等子图中且y不在交错树中
			slack[y] = min(slack[y], tmp);
		}
    }
    return 0;
}
void KM() {

    for (int x = 0; x < nx; ++x) {
		memset(slack, 63, (ny + 1) * sizeof(int));
        fill(slack, slack + ny + 1, INF);//这里不要忘了，每次换新的x结点都要初始化slack
        while (1) {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));//这两个初始化必须放在这里,因此每次findpath()都要更新
            if (dfs(x)) {
				break;
			} else {
                int delta = INF;
                for (int j = 0; j < ny; ++j) {
					//因为dfs(x)失败了所以x一定在交错树中，y不在交错树中，第二类边
                    if (!visy[j]) {//记住这个if
						delta = min(delta, slack[j]);
					}
				}
                for (int i = 0; i < nx; ++i) {
					if (visx[i]) lx[i] -= delta;
				}
                for (int j = 0; j < ny; ++j) {
                    if (visy[j]) {
                        ly[j] += delta;
					} else {
                        slack[j] -= delta;
					}
                    //修改顶标后，要把所有的slack值都减去delta
                    //这是因为lx[i] 减小了delta
                    //slack[j] = min(lx[i] + ly[j] -w[i][j]) --j不属于交错树--也需要减少delta，第二类边
                }
            }
		}
    }
}
void solve() {
	memset(match, -1, sizeof(match));
	memset(ly, 0, sizeof(ly));
	for(int i = 0; i < nx; ++i){
		lx[i] = -INF;
		for(int j = 0; j < ny; ++j) {
			lx[i] = max(lx[i], G[i][j]);
		}
	}
	KM();
}
int main()
{
    while(scanf("%d",&n) != EOF){
        nx = ny = n;
        for(int i = 0 ; i < nx ; ++i)
            for(int j = 0 ; j < ny ; ++j)
                scanf("%d",&G[i][j]);
        solve();
        int ans = 0;
        for(int i = 0 ; i < ny ; ++i) {
            if(match[i] != -1) {
                ans += G[match[i]][i];
			}
		}
        printf("%d\n",ans);
    }
    return 0;
}
