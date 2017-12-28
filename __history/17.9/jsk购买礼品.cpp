using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}

struct _Main{
int arr;
int v  [100005];	
	
_Main(){
	int sum=0;int n;int num=0;
	int i,j;
	read(n);
	v[0]=0;
	for(i=1;i<=n;i++){
		read(num);
		sum+=num;sum%=n;
		if(v[sum]){
			printf("%d\n",i-v[sum]);
			for(j=v[sum]+1;j<=i;j++){
				printf("%d ",j);
			}break;
		}else{
			v[sum]=i;
		}
	}
	fclose(stdout);
	
	
}	
	
	
	
	
	
}jsk;
