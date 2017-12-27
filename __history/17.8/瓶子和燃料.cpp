using namespace std;
int main() {}

#include<cstdio>
#include<cmath>
#include<cctype>
#include<vector>
#include<algorithm>
struct StGcd{
	int Gcd,Cnt;
	bool friend operator < (StGcd a,StGcd b){
		return a.Gcd<b.Gcd;
	}
};
vector<StGcd>list;
struct _Main {
template <typename Type1>
void read(Type1 &a) {
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while(isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}
int N,K;
void inline Insert(int Num){
	StGcd Temp;
	Temp.Cnt=1;
	Temp.Gcd =Num;
	int Idx=lower_bound(list.begin(),list.end(),Temp)-list.begin();
	if(Idx==list.size()){
		list.push_back(Temp);
	}else if(list[Idx].Gcd==Num){
		list[Idx].Cnt++;
	}else{
		list.insert(list.begin()+Idx,Temp);
	}
}
_Main(){
	int temp;
	int i,j;
	read(N);read(K);
	int goal;
	for(i=0;i<N;i++){
		read(temp);
		goal=sqrt(temp);
		for(j=1;j<=goal;j++){
			if(temp%j==0){
				Insert(j);
				if(temp/j!=j){
					Insert(temp/j);
				}
			}
		}
	}
	for(i=list.size()-1;i>=0;i--){
		if(list[i].Cnt>=K){
			printf("%d\n",list[i].Gcd);
			return;
		}
	}
}










} bzoj2257;
