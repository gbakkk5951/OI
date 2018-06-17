#include<fstream>
#include<cmath>
using namespace std;
ifstream cin("homework.in");
ofstream cout("homework.out");
int main()
{
	int n; cin>>n;
	long double f=1.0l-exp(-1.0l);
	for(int i=1;i<=n;++i) f=1.0l-i*f;
	cout<<f<<endl;
	return 0;
}
