#include<cstdio>
#include<cstring>
#include<fstream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<iostream>
using namespace std;
int main() {
    ifstream in("nxt.cpp");
    ofstream out("nxt.txt");
    string tot; stringstream os;
    os << in.rdbuf();
    tot = os.str();
    int i;
    for (i = 0; i < tot.size(); i++) {
        out<<(int)tot[i]<<",";
    }
    out<<"0";
//    system("pause");
}
