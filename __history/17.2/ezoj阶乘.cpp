#include<cstdio>
int t;
long long po[26];

long long getans(long long n){
	long long sum=0;
	int i;
	long long te;
	for(i=1;i<=25;i++){
		te=n/po[i];
		if(te==0)
		return sum;
		sum+=te;
	}
	return sum;
}


int main(){
	long long i,j,k,l;	
	po[0]=1;
	for(i=1;i<=25;i++){
		po[i]=po[i-1]*5;
	}
	scanf("%lld",&t);

	for(i=0;i<t;i++){
		scanf("%lld",&j);
		printf("%lld\n",getans(j));
		
	}

}
