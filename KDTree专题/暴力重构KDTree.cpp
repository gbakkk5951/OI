using namespace std;
int main() {}
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
template <int Dim = 2, typename Type = int>
struct Vec {
public:    
    Type val[Dim];
    Type operator () (int idx) {
        return val[idx];
    }
    Type & operator [] (int idx) {
        return val[idx];
    }
    template<typename Type2>
    bool operator < (const Vec<Dim, Type2> &b) const {
        int i;
        for (i = 0; i < Dim; i++) {
            if (b(i) != val[i]) {
                return b(i) < val[i];
            }
        }
        return false;
    }
};



struct _Main{
    
template <typename Type>
    void read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '0') {
                f = -1;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
        a *= f;
    }    
    
    _Main() {
      
        
    }
    
};


