using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
#include<bitset>

template <typename Type>
void read(Type &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while(isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}
class FWT{
public:
void Xor(int *a,int l){
	int i,j,k,t;int x,y;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				x=a[t=j+k];y=a[i+t];
				a[t]=x+y;a[i+t]=x-y;
			}
		}
	}
}
void nXor(int *a,int l){
	int i,j,k,t;int x,y;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				x=a[t=j+k];y=a[t+i];
				a[t]=(x+y)>>1;
				a[i+t]=(x-y)>>1;				
			}
		}
	}
}
void And(int *a,int l){
	int i,j,k,t;int x,y;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				x=a[t=j+k];y=a[t+i];
				a[t]=x+y;a[i+t]=y;
			}
		}
	}
}
void nAnd(int *a,int l){
	int i,j,k,t,x,y;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				x=a[t=j+k];y=a[i+t];
				a[t]=x-y;a[i+t]=y;
			}
		}
	}
}
void Or(int *a,int l){
	int i,j,k,t,x,y;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				x=a[t=j+k];y=a[i+t];
				a[t]=x;a[i+t]=y+x;
			}
		}
	}	
}	
void nOr(int *a,int l){
	int i,j,k,t,x,y;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				x=a[t=j+k];y=a[i+t];
				a[t]=x;a[i+t]=y-x;
			}
		}
	}
}	
	
}calc;
struct _Main{
int cnt[1050031];
bitset<1050031>v;
int num;
int n,c;int mx;
_Main(){
	freopen("maximum.in","r",stdin);freopen("maximum.out","w",stdout);
	int T;int i;
	read(T);
	while(T--){
		mx=1;
		read(n);read(c);
		for(i=0;i<n;i++){
			v[num]=1;
			read(num);
			cnt[num]++;
			while(num>=mx){
				mx<<=1;
			}
		}
		switch(c){
			case 1:{
				calc.And(cnt,mx);
				for(i=0;i<mx;i++){
					cnt[i]*=cnt[i];
				}
				calc.nAnd(cnt,mx);
				for(i=mx-1;i>=0;i--){
					if(cnt[i]>1 ||(cnt[i] && !v[i])){
						printf("%d\n",i);
						break;
					}
				}
				
				break;
			}
			case 2:{
				calc.Xor(cnt,mx);
				for(i=0;i<mx;i++){
					cnt[i]*=cnt[i];
				}
				calc.nXor(cnt,mx);
				for(i=mx-1;i>=0;i--){
					if(cnt[i]>0){
						printf("%d\n",i);
						break;
					}
				}
			
				break;
			}
			
			case 3:{
				calc.Or(cnt,mx);
				for(i=0;i<mx;i++){
					cnt[i]*=cnt[i];
				}
				calc.nOr(cnt,mx);
				for(i=mx-1;i>=0;i--){
					if(cnt[i]>0){
						printf("%d\n",i);
						break;
					}
				}
				break;
			}
		}
		
		
		v.reset();
		memset(cnt,0,mx*sizeof(int));			
	}
	fclose(stdout);
}
	
}maximum;
