#include"bits/stdc++.h"

using namespace std;

int n,h0,h1,h2,h3;

int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	cin >> n;
	if (n == 2){
		cin >> h0 >> h1;
		for (h2 = -2000; h2 <= 2000; h2 ++)
			for (h3 = -2000; h3 <= 2000; h3 ++)
				if (h0 * h3 - h1 * h2 == 1){
					printf ("%d %d\n%d %d\n", h0, h1, h2, h3);
					exit(0);
				}
	}
	return 0;
}
