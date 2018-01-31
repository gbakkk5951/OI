using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>

namespace OI {





struct _Main {
    int readStr(int *buf) {
        int idx = 0;
        int t; 
        while (!isalpha(t = getchar()));
        do {
            buf[idx++] = t;
        } while (isdigit(t = getchar()));
        return idx;
    }
    
    
    
    _Main() {
        readStr( )
        
        
    }
    
};




}


