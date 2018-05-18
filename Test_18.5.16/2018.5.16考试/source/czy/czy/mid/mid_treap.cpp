#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

typedef pair<int,int> sp;

const int mod = 1000000007;
const int N = 3e7 + 10;

ll xsum;

int ran(ll a, ll ans) {
	return (1714636915ll % mod * (a % mod) % mod + 1681692777ll % mod) % mod * (846930886ll % mod * (ans % mod) % mod + 1804289383ll % mod) % mod;
}

int ch[N][2], v[N], fix[N], sz[N], tot, root;
int up(int x){ sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; return x; }
int newNode(int vv){ return v[++ tot]=vv, fix[tot] = rand(), sz[tot] = 1, tot; }
int merge(int a,int b){
    if(!a || !b) return a | b;
    if(fix[a] < fix[b]) return ch[a][1] = merge(ch[a][1], b), up(a);
    else return ch[b][0] = merge(a, ch[b][0]), up(b);
}
sp split(int a, int k){
    sp s;
    int ls = ch[a][0],rs = ch[a][1];
    if(k == 0) return make_pair(0, a);
    if(sz[ch[a][0]] == k)return ch[a][0] = 0, up(a), make_pair(ls, a);
    if(sz[ch[a][0]] + 1 == k)return ch[a][1] = 0, up(a), make_pair(a, rs);
    if(k < sz[ls]){
        s = split(ls, k);
        return ch[a][0] = s.second, up(a), make_pair(s.first, a);
    }
    s = split(rs, k - sz[ls] - 1);
    return ch[a][1] = s.first, up(a), make_pair(a, s.second);
}
 
int kth(int vv){
    sp x = split(root, vv - 1), y = split(x.second, 1);
    int ans = y.first;
    root = merge(merge(x.first, ans), y.second);
    return v[ans];
}

int rnk(int x, int k = root){
    int ans = 0, tmp=(int) 1e9 + 10;
    while(k) {
        if(x == v[k]) tmp = min(tmp, ans + sz[ch[k][0]] + 1);
        if(x > v[k]) ans += sz[ch[k][0]] + 1, k = ch[k][1];
        else k = ch[k][0];
    }
    return tmp == (int) 1e9 + 10 ? ans : tmp;
}

void ins(int vv){
    sp x = split(root, rnk(vv));
    root = merge(merge(x.first, newNode(vv)), x.second);
}

signed main() {
	int n, a1; scanf("%d%d", &n, &a1);
	ins(a1);
	int ans = kth((1 + 1) / 2);
	xsum ^= ans;
	// cout << ans << endl;
	for(int i = 2 ; i <= n ; ++ i) {
		a1 = ran(a1, ans);
		ins(a1);
		ans = kth((i + 1) / 2);
		xsum ^= ans;
		// cout << ans << endl;
	}
	printf("%lld\n", xsum);
}