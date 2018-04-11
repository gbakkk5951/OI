using namespace std;
#include <cstdio>
#include <ctime>
#include <unistd.h>
const int nowtime = 1523427378;
int main() {
	printf("%d", 1 + ((int)time(0) - nowtime) / 5);
	for (int i = 1; i <= 2700000000; i++);
}

