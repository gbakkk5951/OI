using namespace std;
int main() {}
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>

struct _Main {
	_Main() {
		srand(time(0));
		while (1) {
			static int cnt = 0;
			printf("Now = %d\n", ++cnt);
			ofstream cout("data0.in");
			int n = 1000000, m = rand() % ((int) 1e9);
			cout << n << " " << m << endl;
			for (int i = 1; i <= n - 1; i++) {
				cout << rand() % ((int)1e9) << " ";
			}
			cout << endl;
			for (int i = 1; i <= n; i++) {
				cout << rand() % ((int)1e9) << " ";
			}
			cout.close();
			system("time ./std > data0.out < data0.in");
			/*
			system("./brute > brute0.out < data0.in");
			if (system("diff data0.out brute0.out")) {
				getchar();
			}*/
		}
	}
}mker;
