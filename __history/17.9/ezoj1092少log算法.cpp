using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
int height[50005];
struct MFset{
	int fa;int idx;
	void insert(int val,int time){
		fa=val;idx=time;
	}
}mfset[50005];
int n,m;

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int getfa(int nd,int time){
	if(mfset[nd].idx<=time && mfset[nd].fa){
		return getfa(mfset[nd].fa,time);
	}return nd;
	
}

struct _Main{
	
_Main(){
	int i;int a,b;int f1,f2;
	read(n);read(m);int l,r;
	for(i=1;i<=m;i++){
		read(a);read(b);
		if((f1=getfa(a,i))!=(f2=getfa(b,i))){
			if(height[f1]>height[f2]){
				mfset[f2].insert(f1,i);
			}else if(height[f1]<height[f2]){
				mfset[f1].insert(f2,i);
			}else{
				mfset[f1].insert(f2,i);height[f2]++;
			}
		}else{
			l=0;r=i-2;
			while(l<r){
				if(getfa(a,((l+r)>>1)+1)==getfa(b,((l+r)>>1)+1)){
					r=((l+r)>>1);
				}else{
					l=((l+r)>>1)+1;
				}
			}
			printf("%d\n",l);
		}
	}
}

}ezoj1092;	
