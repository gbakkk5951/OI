using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
const long long mod=99999997LL;
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}	
int a[100010];
int b[100010];
int sa[100010];
int sb[100010];
int ra[100010];
int rb[100010];
int pa[100010];
int n;
long long ans;
_Main(){
	int i,j,k;
	read(n);
	for(i=0;i<n;i++){
		read(a[i]);
	}
	for(i=0;i<n;i++){
		read(b[i]);
	}	
	memcpy(sa,a,(n+1)*sizeof(int));
	memcpy(sb,b,(n+1)*sizeof(int));
	sort(sa,sa+n);sort(sb,sb+n);
	for(i=0;i<n;i++){
		ra[i]=lower_bound(sa,sa+n,a[i])-sa;
		rb[i]=lower_bound(sb,sb+n,b[i])-sb;
		pa[ra[i]]=i;
	}
	mergesort(n,0);
	printf("%lld\n",ans%mod);
}	

void mergesort(int size,int begin){
	if(size==1){
		return;
	}
	mergesort(size/2,begin);
	mergesort(size-(size/2),begin+size/2);
	merge(begin,begin+size/2-1,begin+size-1);
}	
int Temp[100010];
void merge(int l,int mid,int r){
	
	memcpy(Temp+l,rb+l,(r-l+1)*sizeof(int));
	int i,j,cnt;
	int left;
	for(i=l,j=mid+1,cnt=0,left=0;i<=mid && j<=r; ){
		if(pa[rb[i]]<pa[rb[j]]){
			ans+=left;
			Temp[l+(cnt++)]=rb[i];
			i++;
		}else{
			Temp[l+(cnt++)]=rb[j];
			left++;
			j++;
		}
	}
	while(j<=r){
		Temp[l+(cnt++)]=rb[j];
		j++;
	}
	while(i<=mid){
		ans+=left;
		Temp[l+(cnt++)]=rb[i];	
		i++;	
	}
	memcpy(rb+l,Temp+l,(r-l+1)*sizeof(int));
}	
	
	
}ezoj1107;
