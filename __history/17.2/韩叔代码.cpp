#include <cstdio>  
#include <cstring> 
#include <string> 
#include <iostream>
#include <algorithm>
using namespace std;
int const MAX = 21000000;
int const MAXN = 20000000;
int n, m, dp[200010], _end[200010] = { 0 };
string tmp, txt;
char w[200010];
char c[5];
class Trie {
public:
	int next[200010][27], tot, root;
	int Newnode() {
		memset(next[tot], -1, sizeof(next[tot]));
		//cout << "tot: " << tot << endl;
		return tot++;
	}
	void init() {
		tot = 0;
		root = Newnode();
	}
	void insert(string s) {
		int len = s.length();
		int p = root;
		for (int i = 0; i < len; i++) {
			int idx = s[i] - 'a';
			//cout << "here" << idx << endl;
			if (next[p][idx] == -1)
				next[p][idx] = Newnode();
			p = next[p][idx];
			if (i == len - 1) {
				_end[tot] = 1;
			}
		}
		return;
	}
	int search(int strp,int p) {
		int a, b;
		int idx = c[strp] - 'a';
		if (strp == strlen(c)+1) {
			if (_end[strp]) return 0;
			else return MAX;
		}
		if (next[p][idx]) {
			a = search(strp + 1, next[p][idx]);
			b = search(strp + 1, next[p][26]) + 1;
			return min(a, b);
		}
		else return search(strp + 1, next[p][26]) + 1;
	}
} trie;
void kinsert(int p, string in) {
	if (p == in.length()) {
		w[p + 1] = '\0';
		//cout << "---->" << w << endl;
		trie.insert(w);
		return;
	}
	w[p] = in[p];
	kinsert(p + 1, in);
	w[p] = 'z' + 1;
	kinsert(p + 1, in);
}
#pragma warning(disable:4996)
int main() {
	memset(dp, 0x7f, sizeof dp);
	trie.init();
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		kinsert(trie.root, tmp);
	}
	int m;
	scanf("%d\n", &m);
	getline(cin, txt);
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= min(i, 4); j++) {
			for (int k = i - j; k <= i; k++) c[k - i + j] = txt[k];
			c[j] = '\0';
			int ans = trie.search(0,trie.root);
			dp[i] = min(dp[i], dp[i - j] + ans);
		}
	}
	if (dp[m] > MAXN) printf("No");
	else printf("%d", dp[m]);
	return 0;
}
