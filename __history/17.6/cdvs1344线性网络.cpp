int main(){}
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>

const int max_rand=2333333;
const double max_tmp=10000;
const double dec=0.999;
struct _Main{

double x[21],y[21];
double map[21][21];
int arr[2][22];

int n;	
double ans;	
inline double power(double a){
	return a*a;
}


bool accept(double delta,double tmp)
{
    if (delta <= 0) return true;
    return rand() % max_rand <= exp((-delta)/tmp) * max_rand;
}

double num;
int iter;
double tmp;
_Main(){tmp=max_tmp;
	int i,j;
	srand(time(0));
	iter=0;
	int T;
	ans=2000000.0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf%lf",x+i,y+i);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			map[i][j]=sqrt( power(x[i]-x[j]) + power(y[i]-y[j])  );
			map[j][i]=map[i][j];
		}
	}
	
	for(i=0;i<n;i++){
		arr[iter][i]=i;
	}
	num=0;
	for(i=1;i<n;i++){
		num+=map[arr[0][i-1]][arr[0][i]];
	}
	ans=num;
	memcpy(arr[1],arr[0],n<<2);
	iter=1;
	for(T=0;T<100;T++){
		for(i=0;i<n;i++){
			swap(arr[iter][i],arr[iter][rand()%(i+1)]);
		}
		
		solve();
	}printf("%.2f",ans);
	
}
void solve(){
	int j;
	double res=100000000;
	num=0;
	for(j=1;j<n;j++){
		num+=map[arr[iter][j-1]][arr[iter][j]];
	}
	res=num;
	tmp=max_tmp;
	while(tmp>0.01){
		swap(arr[iter][rand()%n],arr[iter][rand()%n]);
		num=0;
		for(j=1;j<n;j++){
			num+=map[arr[iter][j-1]][arr[iter][j]];
		}
		if(accept(num-res,tmp)){
			iter^=1;
			res=num;
			ans=min(num,ans);
		}
		memcpy(arr[iter],arr[iter^1],88);	
		tmp*=dec;
	}
	
	
}







}cdvs1344;
