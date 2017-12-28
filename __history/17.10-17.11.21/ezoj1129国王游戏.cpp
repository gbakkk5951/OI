using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
const long long mod=(long long)1e9;


struct Officer{
	int l;int r;
	bool friend operator < (const Officer &a,const Officer &b){
		return a.l*a.r<b.l*b.r;
	}

}person[1010];
struct Big{
	int high;
	long long num[500];
	void operator = (int a){
		high=0;num[0]=a;
	}
	void operator *=(int a){
		int i;
		for(i=0;i<=high;i++){
			num[i]*=a;
		}
		for(i=0;i<=high;i++){
			num[i+1]+=num[i]/mod;
			num[i]%=mod;
		}
		for(i=high+1;i>=0;i--)if(num[i]){
			high=i;break;
		}
	}
	bool friend operator < (const Big &a,const Big &b){
		if(a.high!=b.high){
			return a.high<b.high;
		}
		int i;
		for(i=a.high;i>=0;i--)if(a.num[i]!=b.num[i]){
			return a.num[i]<b.num[i];
		}
		return false;
	}
	long long & operator [] (int a){
		return num[a];
	}
	Big operator / (int a){
		Big ret=*this;
		int i;int rem=0;
		for(i=high;i>=0;i--){
			ret[i]+=rem*mod;
			rem=ret[i]%a;
			ret[i]/=a;
		}
		ret.high=0;
		for(i=high;i>=0;i--)if(ret[i]){
			ret.high=i;break;
		}
		return ret;
	}
	void print(){
		int i;i=high;
		printf("%lld",num[i]);
		for(i--;i>=0;i--){
			printf("%09lld",num[i]);
		}
		
	}
};

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

int n;




Big mul;
Big ans;
Big temp;
_Main(){
	int i,j,k;
	int a,b;
	read(n);
	read(person[0].l);read(person[0].r);
	for(i=1;i<=n;i++){
		read(person[i].l);read(person[i].r);
	}
 	sort(person+1,person+n+1);
	mul=person[0].l;
	for(i=1;i<=n;i++){
		temp=mul/person[i].r;
		ans=max(ans,temp);
		mul*=person[i].l;
	}
	ans.print();
	
	
}	
	
	
	
}ezoj1129;
