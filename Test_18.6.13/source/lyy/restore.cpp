#include <bits/stdc++.h>

using namespace std;
  
const int N = 111;

struct vec {
  double x;
  double y;

  vec(double _x = 0, double _y = 0): x(_x), y(_y) {};

  vec operator - (vec a) {
    return vec(x - a.x, y - a.y);
  }

  vec operator + (vec a) {
    return vec(x + a.x, y + a.y);
  }

  double operator * (vec a) {
    return x * a.y - y * a.x;
  }

  vec operator * (double a) {
    return vec(x * a, y * a);
  }

  double operator ^ (vec a) {
    return x * a.x + y * a.y;
  }

  vec operator / (double a) {
    return vec(x / a, y / a);
  }

  double len() {
    return sqrt(*this ^ *this);
  }
};

int sgn(double x) {
  if (abs(x) <= 1e-5) {
    return 0;
  }
  return x < 0 ? -1 : 1;
}

int n;

vec g[N];
double dist[N][N];

int main() {
  freopen("restore.in", "r", stdin);
  freopen("restore.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> dist[i][j];
    }
  }
  g[1] = vec(0, 0);
  g[2] = vec(dist[1][2], 0);
  

  for (int i = 3; i <= n; ++i) {
    vec cur = vec(3, 3);
    while (true) {
      double mx = 0;
      int k = -1;
      for (int j = 1; j < i; ++j) {
        double cur_dist = (cur - g[j]).len();
        if (sgn(cur_dist - dist[i][j]) == 0) {
          continue;
        }
        if (cur_dist > mx) {
          mx = cur_dist;
          k = j;
        }
      }
      if (k == -1) {
        g[i] = cur;
        break;
      }
      vec g_cur = cur - g[k];
      double det_x = cur.x - g[k].x;
      double det_y = cur.y - g[k].y;

      det_x *= (dist[i][k] - g_cur.len()) / g_cur.len();
      det_y *= (dist[i][k] - g_cur.len()) / g_cur.len();
      cur.x += det_x;
      cur.y += det_y;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%.10f %.10f\n", g[i].x, g[i].y);
  }
  return 0;
}
