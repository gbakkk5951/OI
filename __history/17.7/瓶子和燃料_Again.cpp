using namespace std;
int main() {}

#include<cstdio>
#include<cmath>
#include<cctype>
#include<map>
map<int,int>Cnt;
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
	Cnt[Num]++;
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
	map<int,int>::iterator it;
	for(it=Cnt.end();it!=Cnt.begin() ;){
		it--;
		if(it->second>=K){
			printf("%d\n",it->first);
			return;
		}
	}
	
}










} bzoj2257;
