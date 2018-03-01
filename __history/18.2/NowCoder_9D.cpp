using namespace std;
int main() {}
#include<string>
#include<sstream>
#include<cstdio>
struct _Main {
    string nums;
    string toString(int a) {
        stringstream os;
        string ret;
        os << a;
        os >> ret;
        return ret;
    }
    
    _Main() {
        int i;
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            nums += toString(i);
        }
        printf("%c",nums[n-1]);
        
    }
    
    
}nowCoder9D;
