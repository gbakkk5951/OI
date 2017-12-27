using namespace std;
int main(){}
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
struct _Main{
inline int power(int a){
	return a*a;
}
double dis[21][21];
int arr[20];
int x[20],y[20];
int n;
_Main(){
	srand(time(0));
	double ans=800000;
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",x+i,y+i);
		arr[i]=i;
	}
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			dis[j][i]=dis[i][j]=sqrt(power(x[i]-x[j])+power(y[i]-y[j]));
		}
	}
	for(i=0;i<1000;i++){
		ans=min(ans,rand_calc());
	}
	printf("%.2f",ans);
}
void shuffle(){
	int i;
	for(i=0;i<n;i++){
		swap(arr[i],arr[rand()%(i+1)]);
	}
}	
void reverse1(int *i,int *j){
	int temp;
	for(;i<j;i++,j--){
		temp=*i;
		*i=*j;
		*j=temp;
	}
}
double rand_calc(){
	double ret=0;
	shuffle();
	double temp;
	int i,j,k;
	bool flag=true;
	while(flag){
		flag=false;
		for(i=1;i<n;i++){
			for(j=i+2;j<n;j++){
				if(dis[arr[i-1]][arr[i]]+dis[arr[j-1]][arr[j]]>dis[arr[i-1]][arr[j-1]]+dis[arr[i]][arr[j]]){
					reverse1(&arr[i],&arr[j-1]);
					flag=true;
				}
			}
		}
	}
	for(i=1;i<n;i++){
		ret+=dis[arr[i]][arr[i-1]];
	}
	return ret;
}	
	
	
}cdvs1344;
