int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
long long mod=(long long)1e9;
long long pow[11]={1,10,100,1000,10000,100000
					,1000000,10000000,100000000
					,1000000000LL,10000000000LL
				};
struct big{
	
	int high;
	long long num[13];
	void clear(){
		memset(this,0,sizeof(big));
	}
	big friend operator * (big a,big b){
		big ret;ret.clear();
		int i,j;
		for(i=0;i<=a.high ;i++){
			for(j=0;j<=b.high ;j++){
				if(i+j>11)break;
				ret[i+j+1]+=ret[i+j]/mod;
				ret[i+j]%=mod;
				ret[i+j]+=a[i]*b[j];
				ret[i+j+1]+=ret[i+j]/mod;
				ret[i+j]%=mod;				
			}
		}
		ret.high =0;
		for(i=min(11,a.high+b.high+1);i>=0;i--){
			if(ret[i]){
				ret.high =i;
				break;
			}
		}
		return ret;
	}
	big friend operator + (big a,big b){
		int i,j;big ret;ret.clear() ;
		for(i=0;i<=max(a.high,b.high );i++){
			ret[i]+=a[i]+b[i];
			ret[i+1]+=ret[i]/mod;
			ret[i]%=mod;
		}
		ret.high =0;
		for(i=min(11,a.high+b.high);i>=0;i--){
			if(ret[i]){
				ret.high =i;
				break;
			}
		}
		return ret;
	}
	
	bool friend equal(big &a,big &b,int goal){
		int i,j,k;
		for(i=0;goal>=0;i++){
			if(goal>=9){
				if(a[i]!=b[i])
				return false;
			}else {
				for(j=0;j<=goal;j++){
					if(a[i]/pow[j]%10 != b[i]/pow[j]%10){
						return false;
					}
				}
				break;
			}
			goal-=9;
		}
		return true;
	}
	long long & operator [] (int a){
		return num[a];
	} 
	void print(){
		int i;
		printf("%lld",num[high]);
		for(i=high-1;i>=0;i--){
			printf("%09lld",num[i]);
		}
	}
};

big ten;
big add;
big lst;
big org;big ans;
big tmp;big t1,t2,t3;

struct _Main{

bool fail;
int need;
int len;
char str[10105];

_Main(){
	
	scanf("%s%d",str,&need);
	len=strlen(str);
	ten[0]=10;ans[0]=1;
	int i,j,k;int a,b,c;
	for(i=0;i<len;i++){
		add[0]=str[i]-'0';
		lst=(lst*ten);
		lst=(lst+add);
	}org=lst;
	for(i=1;i<=need;i++){
		for(j=0,t1=lst;j<=10;j++){
			tmp=t1*org;
			if(equal(tmp,org,i-1)){
				break;
			}
			t1=t1*lst;
		}
		if(j>10){
			fail=true;
			break;
		}
		t2[0]=j+1;
		lst=t1;
		ans=ans*t2;
	}
	if(fail)printf("%d",-1);
	else ans.print();	
}	
	
	
}cdvs1103;

