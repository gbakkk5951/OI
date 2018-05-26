using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
namespace OI {
typedef long long lld;
const string sp = " ";
string to_string(lld a) {
	string ans;
	stringstream os;
	os << a;
	os >> ans;
	return ans;
}
struct _Main {
	
	_Main() {
		while (1) {
			for (int I = 0; I <= 9; I ++) {
				static int solver_id = 2;
				static int id = 0;
				static int iter = 0;
				id = I;
				string solver;
				solver = "solver/" + to_string(solver_id);
				lld ans = 9e18;
				string cmd = "newest/road" + to_string(id) + ".val";
				ifstream lstans(cmd.c_str());
	//:			if (!lstans.eof())
				lstans >> ans;
				cmd = "./" + solver + " " + to_string(ans) + " tmp/ans.val < input/road" + to_string(id) + ".in > tmp/ans.out";
				if (system(cmd.c_str()) != 0) {
					printf("failed\n");
					continue;
				}
				printf("iter = %d\n", ++iter);
				cerr << "copying" << endl;
				
				cmd = "cp tmp/ans.out newest/road" + to_string(id) + ".out";
				system(cmd.c_str());
				cmd = "cp tmp/ans.val newest/road" + to_string(id) + ".val";
				system(cmd.c_str());
				printf("newest updated\n");
				
				cmd = "cp newest/road" + to_string(id) + ".out history/road" + to_string(id) + ".out";
				system(cmd.c_str());
				cmd = "cp newest/road" + to_string(id) + ".val history/road" + to_string(id) + ".val";
				system(cmd.c_str());
				printf("history updated\n");
			}	
		}
	}
}runner;
}
