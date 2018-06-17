#include <cstdio>

using namespace std;

struct IO_Tp
{
	bool is_digit(char ch) const
	{
		return '0' <= ch && ch <= '9';
	}
	
	const IO_Tp& operator>>(int& buf)
	{
		buf = 0;
		static char ch;
		while (ch = getchar(), !is_digit(ch))
			;
		do
			(buf *= 10) += ch & 15;
		while (ch = getchar(), is_digit(ch));
		return *this;
	}
} IO;

int N;
double buf(-1.0), Ans(0.0);

int main(int argc, char** argv)
{
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	
	IO >> N;
	
	for (int i(N + 1); buf <= -1E-9 || 1E-9 <= buf; ++i)
		buf /= -i, Ans += buf;
	
	printf("%.4lf", Ans);
	
	return 0;
}
