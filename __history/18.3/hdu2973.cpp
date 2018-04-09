#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <cstdio>
#include <cctype>
typedef long long lld;
const int MXN = 3000020;
int sum[MXN];
char v[MXN];
int prime[227000];
int pcnt;
void getprime(int mx) {
	int t;
	v[0] = v[1] = 1;
	for (int i = 2; i <= mx; i++) {
		if (!v[i]) {
			prime[pcnt++] = i;
		}
		for (int j = 0; j < pcnt && (t = i * prime[j]) <= mx; j++) {
			v[t] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
template <typename Type> 
  void read(Type &a) {
    char t;
    while (!isdigit(t = getchar()));
    a = t - '0';
    while ( isdigit(t = getchar())) {
      a *= 10;
      a += t - '0';
    }
  }
int main() {
  int Qn, a;
  getprime(MXN - 5);
  v[1] = 1;
  for (int i = 1, t = 3 * i + 7; i <= 1000000; i++, t += 3) {
    sum[i] = sum[i - 1] + !v[t];
  }
  read(Qn);
  for (int Q = 1; Q <= Qn; Q++) {
    read(a);
    printf("%d\n", sum[a]);
  }
}
