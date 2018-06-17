#include <bits/stdc++.h>

using namespace std;

const int N = 555;

int n;
int f[N];

void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= (a / b) * x;
}

int main() {
  freopen("final.in", "r", stdin);
  freopen("final.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
  }
  int x, y;
  exgcd(f[1], f[2], y, x);
  printf("%d %d\n", f[1], f[2]);
  printf("%d %d\n", -x, y);
  return 0;
}
