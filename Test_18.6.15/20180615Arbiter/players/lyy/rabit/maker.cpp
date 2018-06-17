#include <bits/stdc++.h>

using namespace std;

int main(int argv, char *argc[]) {
  stringstream ss;
  ss << argc[1];
  int seed;
  ss >> seed;
  srand(seed);
  cerr << seed;;

  int n = 100000;
  int m = 100000;
  cout << n << " " << m << endl;
  for (int i = 1; i < n; ++i) {
    cout << rand() % i + 1 <<" " << i + 1 << endl;
  }
  for (int i = 1; i <= m; ++i) {
    int op = rand() % 3;
    if (op == 0) {
      cout << "ChangeW ";
      cout << rand() % n + 1 << " " << rand() % 10 + 1 << endl;
    } else if (op == 1) {
      
      cout << "ChangeB ";
      cout << rand() % n + 1 << " " << rand() % 10 + 1 << endl;
    } else {
      cout << "Query ";
      int l = rand() % n + 1;
      int r = rand() % n + 1;
      cout << l << " " << r << " ";
      l = rand() % 10 + 1;
      r = rand() % 10 + 1;
      cout << min(l, r) << " " << max(l, r) << endl;
    }
                   
  }
  return 0;
  
}
