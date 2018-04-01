using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
const string sp = " ";
int mn = 1, mx = 30;
void randstr(ofstream &cout, int mn, int mx) {
	int len = rand() % (mx - mn + 1) + mn;
	for (int i = 0; i < len; i++) {
		cout << (char)(rand() % 26 + 'a');
	}
	cout << endl;
}
int main() {
	int T = 0;
	while (1) {
		printf("%d\n", T);
		ofstream cout("data0.in");
		++T;
		int n = 10000, Qn = 1000;
		cout << n << sp << Qn << endl;
		for (int i = 1; i <= n; i++) {
			cout << i << sp << 1 << sp;
			randstr(cout, 10, 10);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			cout << n << sp;
			randstr(cout, 1, 10);
		}
		cout.close();
		system("T1Adera > std.out < data0.in");
		system("brute > brute.out < data0.in");
		if (system("fc std.out brute.out")) {
			system("pause");
		}
	}
}
