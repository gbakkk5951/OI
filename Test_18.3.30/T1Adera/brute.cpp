using namespace std;
int main() {}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
namespace OI {
const int MXN = 100010;
vector<string> str[MXN];
int size[MXN];
int ans[MXN];
int val[MXN];
bool cmp(int a, int b) {
	return val[a] > val[b];
}

struct _Main {
	int n, Qn;
	_Main() {
		cin >> n >> Qn;
		for (int i = 1; i <= n; i++) {
			cin >> val[i];
			cin >> size[i];
			str[i].resize(size[i]);
			for (int j = 0; j < size[i]; j++) {
				cin>>str[i][j];
			}
		}
		int tot, t, aidx = 0;;
		string pre;
		for (int Q = 1; Q <= Qn; Q++) {
			cin >> t;
			cin >> pre;
			aidx = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < str[i].size(); j++) {
					if (str[i][j].length() >= pre.length() && str[i][j].substr(0, pre.length()) == pre) {
						ans[aidx++] = i;
						break;
					}
				}
			}
			sort(ans, ans + aidx, cmp);
			if (aidx == 0) {
				printf("0\n");
				continue;
			}
			printf("%d ", aidx);
			for (int i = 0; i < aidx && i < t; i++) {
				printf("%d ", ans[i] - 1);
			}
			printf("\n");
		}
	}
	
}T1brute;
}
