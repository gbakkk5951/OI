using namespace std;
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
int arr[400010];
int n;
int lrand() {
	return rand() << 15 | rand();
}
int main() {
	while (1) {
		
		ofstream cout("counter.in");
		n = 200000;
		cout << n << endl;
		for (int i = 1; i <= n; i++) {
			arr[i] = n - i + 1;
		}
		
		for (int i = 2; i <= n; i++) {
			swap(arr[i], arr[lrand() % i + 1]);
		}
		
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << endl;
		}
//		system("brute.exe");
		float ta = clock();
		system("counter.exe");
		printf("uses %fms\n", clock() - ta);
//		if (system("fc brute.out counter.out")) {
//			system("pause");
//		}
	}
}
