const int MAXL = 1000000;
string s;
int n = 0, len, st;
int maxlen[2 * MAXL + 10], minlen[2 * MAXL + 10], trans[2 * MAXL + 10][26], slink[2 * MAXL + 10];
const int ALPHA_SIZE = 26;
int new_state(int _maxlen, int* _trans = 0) {
        maxlen[n] = _maxlen;
        minlen[n] = _minlen;
        if (_trans) {
			for(int i = 0; i < 26; i++) {
				memcpy(trans[n], _trans, sizeof(int) * ALPHA_SIZE);
			}    	
        }
        return n++;
}
void reparent(int s, int p) {
	slink[s] = p;
	minlen[s] = maxlen[p] + 1;
}  
int add_char(char ch, int u) {
        int c = ch - 'a';
        int z = new_state(maxlen[u] + 1);
        int v = u;
        while(v != -1 && trans[v][c] == -1) {
                trans[v][c] = z;
                v = slink[v];
        }
        if(v == -1) { //最简单的情况，suffix-path(u->S)上都没有对应字符ch的转移
                minlen[z] = 1;
                slink[z] = 0;
                return z;
        }
        int x = trans[v][c];
        if(maxlen[v] + 1 == maxlen[x]) { //较简单的情况，不用拆分x
                reparent(x, z);
                return z;
        }
        int y = new_state(maxlen[v] + 1, trans[x]); //最复杂的情况，拆分x
        reparent(y, slink[x]);
		reparent(x, y);
        reparent(z, y);
        int w = v;
        while(w != -1 && trans[w][c] == x) {
                trans[w][c] = y;
                w = slink[w];
        }
        return z;
}
