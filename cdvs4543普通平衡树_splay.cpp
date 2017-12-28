/* ‘≠ ¿Ì */ 

using namespace std;
int main(){}
#include<cstdio>
#include<cctype>

namespace Protector {
const int MAXN = 200010;

template<typename Type>
    void read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '-') {
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
    
struct Node {
    int val;
    int size;
    Node *son[2], *fa;
    void inline update() {
        size = (son[0] ? son[0]->size : 0)
             + (son[1] ? son[1]->size : 0)
             + 1;
    }
}pool[MAXN];
int poolIdx;

inline Node * newNode() {
    return &pool[poolIdx++];
}

class Tree {

private:
    Node *root; 
    Tree() {
        root = newNode();
    }
    void inline buildNode (Node *fa, int pos, int val) {
        fa->son[pos] = newNode();
        fa->son[pos]->fa = fa;
        fa->son[pos]->val = val;
    }
    void splay (Node *nd, Node *root) {
        if( nd->fa == root) {
            return ;
        } 
        Node *fa;
        while ((fa = nd->fa) != root) {
            if(fa->fa != root && (fa->son[0] == fa) == (fa->fa->son[0] == fa)) {
                rotate(fa);
            }
            rotate(nd);
        }
    }
public:
    void insert(int val) {
        if (!root) {
            root = newNode();
            root->val = val;
            return ;
        }
        Node *nd = root;
        int pos;
        while (1) {
            if (nd->son[ pos = (nd->val <= val) ] == 0) {
                build (nd, pos, val);
                splay (nd->son[pos] , root);
                return;
            } else {
                nd = nd->son[nd->val <= val];
            }
        }
    }
    void erase(int val) {
        find(val);
        Node *nd;
        
    }
    void find(int val) {
        
        
    }
    
}tree;



struct _Main {
    
    
};










}
