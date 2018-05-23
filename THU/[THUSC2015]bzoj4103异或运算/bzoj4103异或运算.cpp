using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e3 + 5;
const int MXM = 3e5 + 10;
struct Node {
    Node *s[2];
    int size;
}*null;
struct Trie {
    Node pool[MXM * 32];
    Node *root[MXM];
    int pidx;
    inline Node* new_(Node* org) {
        Node *nd = &pool[pidx++];
        memcpy(nd, org, sizeof(Node));
        nd->size++; 
        return nd;
    }
    Trie() {
        null = &pool[pidx++];
        null->s[0] = null->s[1] = null;
        root[0] = null;
    }
    void insert(int ia, int ib, int val) {
        Node *nd;
        int spo;
        nd = root[ib] = new_(root[ia]);
        for (int I = 30; I >= 0; I--) {
            spo = val >> I & 1;
            nd->s[spo] = new_(nd->s[spo]);
            nd = nd->s[spo];
        }
    }
}trie;
 
 
struct _Main {
    int an[MXN], am[MXM];
    int arr[MXN];
    Node *nr[MXN], *nl[MXN];
    int query(int n1, int n2, int m1, int m2, int rk) {
        int spo, sum, tspo, ret = 0;
        fill(nr + n1, nr + n2 + 1, trie.root[m2]);
        fill(nl + n1, nl + n2 + 1, trie.root[m1 - 1]);
        for (int I = 30; I >= 0; I--) {
            sum = 0;
            for (int i = n1; i <= n2; i++) {
                tspo = an[i] >> I & 1 ^ 1;
                sum += nr[i]->s[tspo]->size - nl[i]->s[tspo]->size;//神TM写成了指针减
            }
            if (spo = sum >= rk) {
                ret |= 1 << I;
            } else {
                rk -= sum;
            }
            for (int i = n1; i <= n2; i++) {
                tspo = an[i] >> I & 1 ^ spo;
                nr[i] = nr[i]->s[tspo];
                nl[i] = nl[i]->s[tspo];
            }
        }
        return ret;
    }
    _Main() {
        int n, m, a, n1, n2, m1, m2, rk, Qn;
        read(n); read(m);
        for (int i = 1; i <= n; i++) {
            read(an[i]);
        }
        for (int i = 1; i <= m; i++) {
            read(a);
            trie.insert(i - 1, i, a);
        }
        read(Qn);
        for (int Q = 1; Q <= Qn; Q++) {
            read(n1); read(n2); 
            read(m1); read(m2);
            read(rk);
            printf("%d\n", query(n1, n2, m1, m2, rk));
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
}bzoj4130;
}
