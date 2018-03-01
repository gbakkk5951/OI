#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    char tmp[100];
    for (int i=1;i<=10;++i){
        sprintf(tmp,"rename delight%d.in entertainment%d.in",i,i);
        system(tmp);
        sprintf(tmp,"rename delight%d.out entertainment%d.ans",i,i);
        system(tmp);
    }
}