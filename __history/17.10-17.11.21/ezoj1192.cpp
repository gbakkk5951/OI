using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
struct _Main{
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}a*=f;
	}	
	long long xorarr[1050000],andarr[1050000];
	int n;
	int mxbit;
template<typename Type>	
	void revtrans(Type *arr){
		int i,j,k,step,mid;
		long long x,y;
		for(i=mxbit;i>=1;i--){
			step=1<<i;
			mid=1<<(i-1);
			for(j=0;j<n;j+=step){
				for(k=0;k<mid;k++){
					x=arr[j+k];y=arr[j+mid+k];
					arr[j+k]=(x+y)/2;
					arr[j+k+mid]=(x-y)/2;
				}
			}
		}
	}
	long long sum;
	_Main(){
		int i,j,k;
		read(n);
		for(mxbit=0;(1<<mxbit)<n;mxbit++);
		for(i=0;i<n;i++){
			read(xorarr[i]);
		}
		for(i=0;i<n;i++){
			read(andarr[i]);
		}
		revtrans(andarr);revtrans(xorarr);
		for(i=0;i<n;i++){
			sum+=andarr[i]*2+xorarr[i];
		}
		sum/=2*n;
		for(i=0;i<n;i++){
			printf("%lld ",(andarr[i]*2+xorarr[i]-sum)/n);
		}

	}
	
	
	
}ezoj1192;
