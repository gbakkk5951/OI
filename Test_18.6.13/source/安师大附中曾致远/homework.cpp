
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long double LD;

const int Max_N(10050);

int N;
LD Ans;

int main()
{
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	cin >> N, ++N;
	LD qwq(1.0);
	for (int i = 1;i <= 100000;++i)
	{
		Ans += qwq / (N + 1.0);
		qwq = qwq / N / (N + 1.0), N += 2.0;
	}
	printf("%.4lf", static_cast<double>(Ans));
	return 0;
}
