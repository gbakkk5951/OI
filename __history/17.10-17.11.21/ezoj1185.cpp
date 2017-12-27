using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<bitset>
typedef bitset<1005> set;
const double eps=1e-3;
int n,m;
set kind[10005];
int disk_need,block_need;
int cst[10005];
double nowval;
int mo[10005],kid[10005];
bool cmp(int a,int b){
	return kid[a]-nowval*mo[a] < kid[b]-nowval*mo[b];
}
int arr[10005];

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
double Delkinbach(){
	yanzheng.reset();
	sort(arr+1,arr+n+1,cmp);
	double fz=0,fm=0;
	int i;
	for(i=1;i<=n;i++){
		fz+=kid[arr[i]];fm+=mo[arr[i]];
		yanzheng|=kind[arr[i]];
		if(i>=disk_need && yanzheng.count()>=block_need){
			break;
		}
	}
	return fz/fm;
}	
set yanzheng;
_Main(){
	int i,j,k;
	int a,b,c;
	read(n);read(m);read(block_need);read(disk_need);
	if(n<disk_need || m<block_need){
		printf("-1");
		goto EndMain;
	}
	for(i=1;i<=n;i++){
		read(kid[i]);
		arr[i]=i;
	}
	for(i=1;i<=n;i++){
		read(mo[i]);
		for(j=1;j<=mo[i];j++){
			read(a);
			kind[i][a]=1;
		}
		yanzheng|=kind[i];
	}
	if(yanzheng.count()<block_need){
		printf("-1");
		goto EndMain;
	}
	nowval=1;
	double tmp;
	while(1){
		tmp=Delkinbach();
		if(fabs(tmp-nowval)<eps){
			break;
		}else{
			nowval=tmp;
		}
	}
	printf("%.2lf",nowval);
	EndMain:
		fclose(stdout);
}

	
	
	
}ezoj1185;


