#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
const string sp = " ";
int main() {
	srand(time(0));
	while (1) {
 		ofstream cout("data.in");
		int n, k;
		n = 200; k = 3;
		for (int T = 1; T <= 10; T++) {
		cout << n << sp << k << endl;
		for (int i = 2; i <= n; i++) {
			int op = rand() % 3;
			if (op == 0)cout << i << sp << rand() % (i - 1) + 1 << endl;
			else if (op == 1) cout << i << sp << i - 1 << endl;
			else if (op == 2) cout << i << sp << 1 << endl;
		}			
		}

		
		system("T3树上求和_ac > data.out < data.in");
		system("T3树上求和_brute > brute.out < data.in");
//		if (system("fc data.out brute.out")) {
//			system("pause");
//		}
		printf("finish\n");
	}
}
