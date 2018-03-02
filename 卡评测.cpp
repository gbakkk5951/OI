long long a;
double b;
template <typename t1, typename t2, typename t3, typename t4> 
	void bomb(int len, t1 a1, t2 a2, t3 a3, t4 a4) {
		if (len == 4) return ;
		bomb(len + 1, a, a2, a3, a4);
		bomb(len + 1, b, a2, a3, a4);
		bomb(len + 1, a1, a, a3, a4);
		bomb(len + 1, a1, b, a3, a4);
		bomb(len + 1, a1, a2, a, a4);
		bomb(len + 1, a1, a2, b, a4);
		bomb(len + 1, a1, a2, a3, a);
		bomb(len + 1, a1, a2, a3, b);	
	}

int main() {
	bomb(0, a, b, a, b);
}
