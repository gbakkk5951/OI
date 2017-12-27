#include<cstdio>
#include<cctype>
using namespace std;
typedef __int128 _int128;
struct _Main{

_int128 read(){
	static char t;
	static _int128 ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}
_int128 inline _max(_int128 a,_int128 b){
	return a>b?a:b;
}
_Main(){
	_int128 n,i;
	_int128 self[3];
	_int128 max[3];
	self[0]=read();
	max[0]=self[0];
	self[1]=read();
	max[1]=self[1];
	self[2]=read();
	max[2]=self[2];
	
	
	n=read();
	for(i=0;i<n;i++){
		max[0]=_max(max[0],read());
		max[1]=_max(max[1],read());
		max[2]=_max(max[2],read());
	}
	output(max[0]-self[0]);
	putchar(' ');
	output(max[1]-self[1]);
	putchar(' ');	
	output(max[2]-self[2]);
	putchar(' ');	

}
void output(_int128 num){
	static char stk[40];
	static char cnt;
	cnt=0;
	static _int128 t;
	t=num/10;
	while(t){
		stk[cnt++]=num-t*10+'0';
		num=t;
		t/=10;
	}
	stk[cnt++]=num+'0';
	
	while(cnt--){
		putchar(stk[cnt]);
	}

}
	
}cdvs6107;
int main(){} 
