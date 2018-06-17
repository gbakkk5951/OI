using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
namespace OI {
struct Test {
	int arr[10000000];
}p[11];
struct _Main {
	_Main() {
		for (int j = 1; j <= 10; j++)
		for (int i = 1; i <= 10; i++) {
			p[i] = p[i - 1];
		}
	}
}instance;
}
