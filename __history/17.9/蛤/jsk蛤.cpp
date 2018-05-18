using namespace std;
int main(){}
#include<cstdio>
#include<cstring> 
#include<cctype>
#include<algorithm>

struct _Main{
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

long long n,m;	

long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
int lcm[1000][1000];
long long excl[2][1000];int iter;
void getlcm(){
	int i,j;
	for(i=0;i<fidx-1;i++){
		for(j=i+1;j<fidx;j++){
			lcm[j][i]=lcm[i][j]=
				lower_bound(factor,factor+fidx,
				factor[i]/gcd(factor[i],factor[j])*factor[j])
				-factor;
		}
	}
}
void getadd(){
	int i;long long t;
	for(i=0;i<fidx;i++){
		t=m/factor[i];
		add[i]=t*(t-1)/2*factor[i];
	}
}
long long add[1000];
long long factor[1000];int fidx;
void fenjie(){
	int i;
	for(i=1;i*i<=m;i++){
		if(m%i==0){
			factor[fidx++]=i;
			if(i*i!=m){
				factor[fidx++]=m/i;
			}
		}
	}sort(factor,factor +fidx);
}
long long arr[10005];
long long ans;
_Main(){
	int T;int I;read(T);
	for(I=1;I<=T;I++){
		
		

	bool ok;ans=0;fidx=0;memset(excl[iter],0,sizeof(excl[iter]));
	read(n);read(m);int i,j,k;bool one=false;
	fenjie();
	for(i=0;i<n;i++) read(arr[i]),arr[i]=gcd(arr[i],m),one=one || arr[i]==1;
	sort(arr,arr+n);n=unique(arr,arr+n)-arr;
	if(one){
		printf("%lld",m*(m-1)/2);
		goto EndMain;
	}
	for(i=0;i<n-1;i++)if(arr[i]!=-1){
		for(j=i+1;j<n;j++){
			if(arr[j]%arr[i]==0){
				arr[j]=-1;
			}
		}
	}
	for(i=0;i<n;i++)if(arr[i]==-1){
		swap(arr[i],arr[n-1]);
		i--;n--;
	}sort(arr,arr+n);
	for(i=0;i<n;i++){
		arr[i]=lower_bound(factor,factor+fidx,arr[i])-factor;
		excl[iter][arr[i]]++;
	}
	getlcm();getadd();
	
	ok=true;
	while(ok){
		ok=false;
		if(iter==0){
			for(i=0;i<fidx;i++)if(excl[iter][i]){
				ans+=excl[iter][i]*add[i];
			}
		}else{
			for(i=0;i<fidx;i++)if(excl[iter][i]){
				ans-=excl[iter][i]*add[i];
			}
		}
		memset(excl[iter^1],0,fidx*sizeof(int));
		for(i=0,k=0;i<fidx-1;i++)if(excl[iter][i]){
			while(k+1<n && arr[k]<=i)k++;
			for(j=k;j<n;j++)if(factor[i]%factor[arr[j]] ){
				excl[iter^1][lcm[i][arr[j]]]+=excl[iter][i];
				ok=true;
			}
		}
		iter^=1;
	}
	printf("Case #%d: %lld\n",I,ans);
	EndMain:;
	
	}
}
	
	
	
}jsk;
