/* ԭ �� */ 
using namespace std;
int main() {}
#include<cstdio>
#include<cctype>
#include<map>

map<pair<int,int>,int> dp;

namespace Protector{
const int SQ = 31622; // ��ȡ�� 
const int MAX = 1e9;
struct _Main {
template <typename Type>
    void read(Type &a) {
        char t;
        while(!isdigit(t = getchar()));
        a = t - '0';
        while( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
    }
int prime[3500];
char noPrime[SQ+5];
int pIdx;    
void getPrime(int maxn) {
    int i, j, t;
    for (i = 2; i <= maxn; i++) {
        if (noPrime[i] == 0) {
            prime[pIdx++] = i;
        }
        for (j = 0; j < pIdx && (t = i * prime[j]) <= maxn; j++) {
            noPrime[t] = 1;
            if (i % prime[j] == 0) {
               break; 
            }
        }
    }
}

int count(int n, int pos) { // 1~n �� prime[0] ~ prime[pos] ���ʵ��� 
    if( pos == -1) {
        return n;
    }
    if (prime[pos] >= n) {
        return 1;
    }
    if (dp.count(make_pair(n, pos)) == 0){
        dp[make_pair(n,pos)] = count(n, pos - 1) - count(n / prime[pos], pos - 1);
    }
    return dp[make_pair(n,pos)];
}
_Main() {
    getPrime(SQ);
    int x, y;
    int tmp; int p;
    read(x); read(y);
    int l = y, r = MAX + 1, mid;
    if (x == 1) {
        printf("%d", y);
        goto EndMain;
    }
    if (y > SQ) {
        printf("%d", 0);
        goto EndMain;
    }
    
    
    p = lower_bound(prime, prime + pIdx, y) - prime;
    while (l < r) {
        mid = l + r >> 1;
        tmp = count(mid / prime[p], p - 1);
        if (tmp > x ) {
            r = mid - 1;
        } else if(tmp < x){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    if ( l > MAX) {
        printf("0");
    } else {
        printf("%d", l);
    }
    EndMain:;
}    
    
    
    
}nowCoder9E;


}

//�г�ֵ�ı���Ҫ�ڳ�ֵ������֮������
//�����С��Ԥ����Ĵ�С��������Ӧ�õĴ�С
//��������һЩ��������֮��ķ�Χ�ŷ���
//��Щ�����Ǳ���� 
//����map���仯������ 

