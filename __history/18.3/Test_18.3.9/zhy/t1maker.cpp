#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
int lrand() {
	return rand() << 15 | rand();
}
int lrand(int mn, int mx) {
	return rand() % (mx - mn + 1) + mn;
}
const char sp[] = " ";
int main() {
	srand(time(0));
	while (1) {
	int mx = 500, mn = 0;
	int n = 10000, m = 40000;
	ofstream cout("data.in");
	cout << n << sp << m << endl;
	for (int i = 1; i <= n; i++) {
		cout << lrand(mn, mx) << sp << lrand(mn, mx) << endl;
	}
	for (int i = 1; i <= m; i++) {
		cout << lrand(1, n) << sp << lrand(1, n) << sp << lrand(mn, mx) << sp << lrand(mn, mx) << sp <<
		lrand(mn, mx) << endl;
	}
	cout.close();
	float t1 = clock();
	system("t1¾ÅÎ²Ñýºü > std.out < data.in");
	float t2 = clock();
	cerr << "std uses " << t2 - t1 << endl;
	/*
	system("t1brute > brute.out < data.in");
	cerr << "brute uses " << clock() - t2 << endl;
	if (system("fc std.out brute.out")) {
		system("pause");
	}
	*/
	}
}
