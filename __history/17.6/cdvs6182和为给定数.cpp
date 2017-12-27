using namespace std;
int main(){}
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cstdlib>

struct _Main{
void read(int &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}
int n,m;
int arr[100010];
_Main(){
	int i,j,k;
	read(n);
	for(i=0;i<n;i++){
		read(arr[i]);
	}sort(arr,arr+n);
	read(m);
	for(i=0;i<n-1;i++){
		if(*lower_bound(arr+i+1,arr+n,m-arr[i]) == m-arr[i]){
			printf("%d %d",arr[i],m-arr[i]);
			return;
		}
	}
	printf("No");
}
	
	
	
	
}cdvs6182; 
