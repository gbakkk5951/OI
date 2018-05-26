using namespace std;
int main() {}
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
namespace OI {
const int MXN = 1e6 + 5;
const string sp = " ";
string to_string(int a) {
	string ans;
	stringstream os;
	os << a;
	os >> ans;
	return ans;
}
int a[MXN], b[MXN], c[MXN], d[MXN];
int id[MXN];
int srt[MXN];
bool cmp (int i, int j) {
	if (a[i] != a[j]) return a[i] < a[j];
	if (b[i] != b[j]) return b[i] < b[j];
	if (d[i] != d[j]) return d[i] < d[j];
	return c[i] < c[j];
}

struct _Main{
	_Main() {
			
		for (int I = 0; I <= 9; I++) {
			int idx = 0;
			int n, m;
			
			string file = "org/road" + to_string(I) + ".in";
			ifstream cin(file.c_str());
			cin >> n >> m;
			static int del[MXN], delcnt;
			memset(del + 1, 0, m * sizeof(int));
			delcnt = 0;
			for (int i = 1; i <= m; i++) {
				id[i] = i;
				cin >> a[i] >> b[i] >> c[i] >> d[i];
				if (a[i] > b[i]) swap(a[i], b[i]);
				srt[++idx] = d[i];
			}
			sort(srt + 1, srt + m + 1);
			idx = unique(srt + 1, srt + m + 1) - srt - 1;
			for (int i = 1; i <= m; i++) {
				d[i] = lower_bound(srt + 1, srt + idx + 1, d[i]) - srt;
			}
			cin.close();
			sort(id + 1, id + m + 1, cmp);
			for (int i = 2; i <= m; i++) {
				if (a[id[i]] == a[id[i - 1]] 
				 && b[id[i]] == b[id[i - 1]] 
				 && d[id[i]] == d[id[i - 1]]) {
					del[id[i]] = ++delcnt;
				}
			}
			file = "input/road" + to_string(I) + ".in";
			ofstream cout(file.c_str());
			cout << n << sp << m - delcnt << sp << idx << endl;
			for (int i = 1; i <= m; i++) {
				if (!del[id[i]]) {
					cout << a[id[i]] << sp << b[id[i]] << sp << c[id[i]] << sp << d[id[i]] 
					<< sp << id[i] <<endl;
				}
			}
			cerr <<"del " << delcnt << sp << " in "<< I << endl;
			cout.close();
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}input;
}
