using namespace std;
int main () {}
#include<cstdio>
#include<cctype>
namespace Protector {

const int UP = 1;
const int DOWN = 0;
const int NXT = 2;
const int IDX = 1;
const int DST = 0;

struct _Main {

template <typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isidigt(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
    }    
char color[1000010];
char is_del[1000010];
char even[1000010][2];
char odd[1000010][2];
int head[1000010];    
int edge[1000010][3];
int e_idx;
void inline add(int from, int to, int idx) {
    e_idx++;
    edge[e_idx][DST] = to;
    edge[e_idx][IDX] = idx;
    edge[e_idx][NXT] = head[from];
    head[from] = e_idx;
}   


 
_Main() {
    
    
    
}
    
    
    
    
    
    
};


}
