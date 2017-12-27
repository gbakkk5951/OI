using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
struct _Main{
int read(int &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}

_Main(){

}








	
	
	
}poj3666;
