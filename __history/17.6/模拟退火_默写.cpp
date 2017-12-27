using namespace std;
int main(){}
#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
const int max_tmp=10000;
const double dec=0.999;
const int max_rand=2333333;
struct _Main{
bool accept(double delta,double tmp){
	if(delta<=0){
		return true;
	}
	return (rand())%max_rand < exp(-delta/tmp)*max_rand;
}
void shuffle(){
	memcpy(temp,arr,80);
	swap(temp[rand()%n],temp[rand()%n]);
}



double calc(){
	double ret=0;
	int i;
	for(i=1;i<n;i++){
		ret+=dis[temp[i]][temp[i-1]];
	}
	return ret;
}
double inline pf(double a){
	return a*a;
}
int n,arr[20],temp[20];
int x[20],y[20];
double dis[20][20];
_Main(){
	srand(time(0));
	double ans;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",x+i,y+i);
		arr[i]=i;
		temp[i]=i;
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			dis[i][j]=dis[j][i]=sqrt(pf(x[i]-x[j])+pf(y[i]-y[j]));
		}
	}
	ans=calc();
	for(i=0;i<100;i++){
		ans=min(ans,fire());
	}
	printf("%.2f",ans);
}
double fire(){
	double ret=300000;
	double tmp,dis1,dis2;
	tmp=max_tmp;
	dis1=300000;
	while(tmp>0.01){
		
		shuffle();
		dis2=calc();
		if(accept(dis2-dis1,tmp)){
			
			memcpy(arr,temp,80);
			dis1=dis2;
			ret=min(ret,dis2);
		}else{
			memcpy(temp,arr,80);
		}
		tmp*=dec;
		
	}
	return ret;
}
	
	
}cdvs1344;
