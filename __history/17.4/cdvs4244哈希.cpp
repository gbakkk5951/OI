#include<cstdio>
#include<bitset>
int h[7]={9999929,2333119,9483347,7979779,8987777,9191111,8871113};
using namespace std;
bitset<9999929>h1;
bitset<2333119>h2;
bitset<9483347>h3;
bitset<7979779>h4;
bitset<8987777>h5;
bitset<9191111>h6;
bitset<8871113>h7;
struct _main{
int n,m;
_main(){
	n=read();m=read();
	int i;
	for(i=0;i<n;i++){
		insert(read());
	}
	for(i=0;i<m;i++){
		find(read())?(putchar('1'),putchar(' ')):(putchar('0'),putchar(' '));
		
	}
	
}	
	
void insert(int in){
	int i;
	h1[hash(in,0)]=1;
	h2[hash(in,1)]=1;
	h3[hash(in,2)]=1;
	h4[hash(in,3)]=1;
	h5[hash(in,4)]=1;
	h6[hash(in,5)]=1;
	h7[hash(in,6)]=1;						
}
int hash(int in,int nu){
	return in%h[nu];	
}

	
bool find(int in){
	if(	h1[hash(in,0)]&&
	h2[hash(in,1)]&&
	h3[hash(in,2)]&&
	h4[hash(in,3)]&&
	h5[hash(in,4)]&&
	h6[hash(in,5)]&&
	h7[hash(in,6)])
	{
		return true;
	}
	return false;
}	
	
int read(){
	int ret=0,f=1;
	char t;
	while((t=getchar())<'0'||t>'9'){if(t=='-'){f=-1;}}
	ret=t-'0';
	while((t=getchar())>='0'&&t<='9'){ret*=10;ret|=t-'0';}
	return ret*f;
}
	
	
	
	
	
	
}instance;int main(){}

