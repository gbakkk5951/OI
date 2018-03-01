#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    char tmp[100];
    for (int i=1;i<=20;++i){
        sprintf(tmp,"rename animal%d.in game%d.in",i,i);
        system(tmp);
        sprintf(tmp,"rename animal%d.out game%d.ans",i,i);
        system(tmp);
    }
}