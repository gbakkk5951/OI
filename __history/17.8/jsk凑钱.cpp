using namespace std;
int main(){}
#include<cctype>
#include<cstdio>
#include<bitset>
bitset<100010>got;
int h;
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}	
int val[105];short num[105];
int low;
int n,m;
_Main(){
	int i,j,k;
	read(n);read(m);
	got[0]=1;
	for(i=0;i<n;i++){
		read(val[i]);
	}
	for(i=0;i<n;i++){
		read(num[i]);
	}
	for(i=0;i<n;i++){
		if(val[i]>m)continue;
		for(j=0;j<val[i];j++){
			
			if(got[j]) h=j;
			else	   h=-1;
			low=j-num[i]*val[i];
			for(k=j+val[i];k<=m;k+=val[i]){
				low+=val[i];
				if(got[k]){
					h=k;
				}else if(h<low){
					h=-1;
				}else if(h!=-1){
					got[k]=1;
				}
			}
		}
	}
	printf("%d",(int)got.count()-1);
	
}
	
	
}jsk;

