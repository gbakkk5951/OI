#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
const double PI=acos(-1);
using namespace std;
double f[105][105],pos[105][2];
void GetPos(int k,int flag){
	double a=f[1][2],b=f[1][k],c=f[2][k];
	pos[1][0]=0;pos[1][1]=0;
	pos[2][0]=a;pos[2][1]=0;
	pos[k][0]=(c*c-b*b-a*a)/-2/a;pos[k][1]=sqrt(b*b-pos[k][0]*pos[k][0]);
	if(flag&1)pos[k][0]*=-1;
	if(flag>>1)pos[k][1]*=-1;
}
inline double GetDis(int x,int y){
	return sqrt((pos[x][0]-pos[y][0])*(pos[x][0]-pos[y][0])+(pos[x][1]-pos[y][1])*(pos[x][1]-pos[y][1]));
}
bool Check(int n){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(fabs(GetDis(i,j)-f[i][j])>1e-3)
				return false;
	return true;
}
int main(){
	srand(time(NULL));
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>f[i][j];
	if(n==3)
		GetPos(3,0);
	else if(n<=21)
		for(int i=0;;i++){
			int t=i;
			for(int j=3;j<=n;j++){
				GetPos(j,t&3);
				t>>=2;
			}
			if(Check(n))
				break;
		}
	else
		do
			for(int i=3;i<=n;i++)GetPos(i,rand()&3);
		while(!Check(n));
	for(int i=1;i<=n;i++)
		printf("%.6f %.6f\n",pos[i][0],pos[i][1]);
}
