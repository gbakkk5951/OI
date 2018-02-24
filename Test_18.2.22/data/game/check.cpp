#include<fstream>
using namespace std;

const int N = 200 + 5;

ifstream fin, fout, fstd;
ofstream flog;
int n, i, j, k, p[N], t , st;
bool u[N], g[N][N];
string s_msg;

void wrong()
{
	flog.open(s_msg.c_str() );
	flog << "0" <<endl;
	flog.close();
}

int main(int argc, char *argv[])
{
	s_msg = string(argv[5]);
    wrong();
	fin.open(argv[1]);
	fin >> n;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
		{
			fin >> k;
			g[i][j] = k == 1;
		}
	fin.close();
	fout.open(argv[2]);
	fout >> t;
	for (i = 1; i <= n; ++i)
		fout >> p[i];
	fout.close();
	fstd.open(argv[3]);
	fstd >> st;
	fstd.close();
	if (t == st)
	{
		for (i = 1; i <= n; ++i)
			u[i] = 1;
		for (i = 1; i <= n; ++i)
			if (p[i] < 1 || p[i] > n || !u[p[i]] || (i < n && !g[p[i]][p[i + 1]]))
			{
				wrong();
				return 0;
			}
		if (!t && !g[p[n]][p[1]])
		{
			wrong();
			return 0;
		}
		flog.open(argv[5]);
		flog << argv[4] <<endl;
		flog.close();
	}
	else if (st==0&&t==1){
		for (i = 1; i <= n; ++i)
			u[i] = 1;
		for (i = 1; i <= n; ++i)
			if (p[i] < 1 || p[i] > n || !u[p[i]] || (i < n && !g[p[i]][p[i + 1]]))
			{
				wrong();
				return 0;
			}
		double x;
		sscanf(argv[4],"%lf",&x);
		flog.open(argv[5]);
		flog << (int)(x*0.4) <<endl;
		flog.close();
	}
	else{
		wrong();
		return 0;
	}
	return 0;
}
