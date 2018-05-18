#include <bits/stdc++.h>
std :: priority_queue<int> lrg; std :: priority_queue<int, std :: vector<int>, std :: greater<int> > sml;
inline int kth(int k) {
    while(lrg.size() > k) sml.push(lrg.top()), lrg.pop();
    while(lrg.size() < k) lrg.push(sml.top()), sml.pop();
    return lrg.top();
}
int main() {
    freopen("mid.in", "r", stdin);
    freopen("mid.out", "w", stdout);
	register int i = 2, t1, t2, a1, xsum, ans, n; scanf("%d%d", &n, &a1), lrg.push(a1), xsum = ans = kth(1);
	for(i = 2 ; i <= n ; ++ i) {
        t1 = (714636908ll * a1 % 1000000007 + 681692770) % 1000000007;
        t2 = (846930886ll * ans % 1000000007 + 1804289383) % 1000000007;
        a1 = (long long) t1 * t2 % 1000000007;
        a1 <= lrg.top() ? lrg.push(a1) : sml.push(a1);
        xsum ^= (ans = kth((i + 1) >> 1));
    }
	printf("%d", xsum);
}
