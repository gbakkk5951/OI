using namespace std;
int main() {}
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
namespace OI {
typedef long long lld;
map<lld, string> mx, mn;
struct _Main {
	string in, tmp;
	
	_Main() {
		cin >> in;
		int len = in.length();
		int i, j, k;
		lld set;
		for (i = 0; i < len; i++) {
			for (j = 1; i + j <= len; j++) {
				tmp = in.substr(i, j);
				set = 0;
				for (k = 0; k <= len - j; k++) {
					if (tmp == in.substr(k, j)) {
						set |= 1LL << (k + j - 1); 
					}
				}
				if (mx[set] == "" || mx[set].length() < j) {
					mx[set] = tmp;
				}
				if (mn[set] == "" || mn[set].length() > j) {
					mn[set] = tmp;
				} 
			}
		}
		int Q, Qn;
		cin >> Qn;
		for (Q = 1; Q <= Qn; Q++) {
			string ask_str;
			cin >> ask_str;
			for (i = 0, set = 0; i <= len - ask_str.length(); i++) {
				if (ask_str == in.substr(i, ask_str.length())) {
					set |= 1LL << (i + ask_str.length() - 1);
				}
			}
			cout << mn[set] << " " << mx[set];
			for (i = 0; i < len; i++) {
				if (set & (1LL << i)) {
					cout << " " << i + 1;
				}
			}
			cout << endl;
		}
		
	}
}hiho1441;

}

