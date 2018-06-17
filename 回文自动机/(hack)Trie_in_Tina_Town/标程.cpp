#pragma comment(linker, "/STACK:102400000,102400000")
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int low(int x) { return x&-x; }
const int INF = 0x7FFFFFFF;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 10;
int T, n, ft[maxn], nt[maxn], x;
char s[maxn], ch;
LL ans;

struct PalindromicTree
{
	const static int maxn = 2e6 + 10;
	const static int size = 4;
	int next[maxn][size], sz, tot;
	int fail[maxn], len[maxn], last[maxn], pre[maxn];
	LL cnt[maxn];
	char s[maxn];
	void clear()
	{
		len[1] = -1; len[2] = 0;
		fail[1] = fail[2] = 1;
		cnt[1] = cnt[2] = tot = 0;
		last[0] = (sz = 3) - 1;
		memset(next[1], 0, sizeof(next[1]));
		memset(next[2], 0, sizeof(next[2]));
	}
	int Node(int length)
	{
		memset(next[sz], 0, sizeof(next[sz]));
		len[sz] = length;      return sz;
	}
	int getfail(int x)
	{
		while (s[tot] != s[tot - len[x] - 1]) x = fail[x];
		return x;
	}
	LL add(char pos)
	{
		int x = (s[++tot] = pos) - 'a', y = getfail(last[tot - 1]);
		if (next[y][x]) { last[tot] = next[y][x]; pre[tot] = 0; }
		else {
			last[tot] = next[y][x] = Node(len[y] + 2);
			pre[tot] = y;
			fail[sz] = len[sz] == 1 ? 2 : next[getfail(fail[y])][x];
			cnt[sz] = cnt[fail[sz]] + len[sz];        ++sz;
		}
		return cnt[last[tot]];
	}
	void del(char pos)
	{
		int x = pos - 'a';
		if (pre[tot])
		{
			next[pre[tot]][x] = 0;
			--sz;
		}
		--tot;
	}
}solve;

inline int get()
{
	while ((ch = getchar()) < '0' || ch > '9');
	int x = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + ch - '0';
	return x;
}

void dfs(int x)
{
	for (int i = ft[x]; i != -1; i = nt[i])
	{
		ans += solve.add(s[i]);
		dfs(i);
		solve.del(s[i]);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		solve.clear();
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) ft[i] = -1;
		for (int i = 1; i <= n; i++)
		{
			//while ((s[i] = getchar()) < 'a' || ch > 'd');
			//x = get(); nt[i] = ft[x];    ft[x] = i;
			scanf("%s%d", s + i, &x);
			nt[i] = ft[x];    ft[x] = i;
		}
		dfs(ans = 0);
		printf("%lld\n", ans);
	}
	return 0;
}
