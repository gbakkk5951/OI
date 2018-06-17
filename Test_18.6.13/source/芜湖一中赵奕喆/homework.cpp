#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int n;

void init(){
	scanf("%d", &n);
}

void work(){
	//if(n <= 10){
		double ans = 0.63212055882855155646417941457943;
		for(int i = 1; i <= n; i++)
			ans = 1 - i * ans;
		printf("%.4lf\n", ans);
	//}
}

int main(){
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	init();
	work();
	return 0;
}

