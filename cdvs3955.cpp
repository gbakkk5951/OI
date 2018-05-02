using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
int dp[1000010];	
int * (*erfen)(int );
int * erfen5(int val){
	int *i=dp+1;
	if(i[64]<val) i+=100-64;
	if(i[32]<val) i+=32;
	if(i[16]<val) i+=16;
	if(i[8]<val) i+=8;
	if(i[4]<val) i+=4;
	if(i[2]<val) i+=2;
	if(i[1]<val ) i+=1;
	if(i[0]<val) i++;
	return i;
}
int * erfen4(int val){
	int *i=dp+1;
	if(i[512]<val) i+=1000-512;
	if(i[256]<val) i+=256;
	if(i[128]<val) i+=128;
	if(i[64]<val) i+=64;
	if(i[32]<val) i+=32;
	if(i[16]<val) i+=16;
	if(i[8]<val) i+=8;
	if(i[4]<val) i+=4;
	if(i[2]<val) i+=2;
	if(i[1]<val ) i+=1;
	if(i[0]<val) i++;
	return i;
}
int * erfen3(int val){
	int *i=dp+1;
	if(i[8192]<val) i+=10000-8192;
	if(i[4096]<val) i+=4096;
	if(i[2048]<val) i+=2048;
	if(i[1024]<val) i+=1024;
	if(i[512]<val) i+=512;
	if(i[256]<val) i+=256;
	if(i[128]<val) i+=128;
	if(i[64]<val) i+=64;
	if(i[32]<val) i+=32;
	if(i[16]<val) i+=16;
	if(i[8]<val) i+=8;
	if(i[4]<val) i+=4;
	if(i[2]<val) i+=2;
	if(i[1]<val ) i+=1;
	if(i[0]<val) i++;
	return i;
}
int * erfen2(int val){
	int *i=dp+1;
	if(i[65536]<val) i+=100000-65536;
	if(i[32768]<val) i+=32768;
	if(i[16384]<val) i+=16384;
	if(i[8192]<val) i+=8192;
	if(i[4096]<val) i+=4096;
	if(i[2048]<val) i+=2048;
	if(i[1024]<val) i+=1024;
	if(i[512]<val) i+=512;
	if(i[256]<val) i+=256;
	if(i[128]<val) i+=128;
	if(i[64]<val) i+=64;
	if(i[32]<val) i+=32;
	if(i[16]<val) i+=16;
	if(i[8]<val) i+=8;
	if(i[4]<val) i+=4;
	if(i[2]<val) i+=2;
	if(i[1]<val ) i+=1;
	if(i[0]<val) i++;
	return i;
}
int * erfen1(int val){
	int *i=dp+1;
	if(i[524288]<val) i+=1000000-524288;
	if(i[262144]<val) i+=262144;
	if(i[131072]<val) i+=131072;
	if(i[65536]<val) i+=65536;
	if(i[32768]<val) i+=32768;
	if(i[16384]<val) i+=16384;
	if(i[8192]<val) i+=8192;
	if(i[4096]<val) i+=4096;
	if(i[2048]<val) i+=2048;
	if(i[1024]<val) i+=1024;
	if(i[512]<val) i+=512;
	if(i[256]<val) i+=256;
	if(i[128]<val) i+=128;
	if(i[64]<val) i+=64;
	if(i[32]<val) i+=32;
	if(i[16]<val) i+=16;
	if(i[8]<val) i+=8;
	if(i[4]<val) i+=4;
	if(i[2]<val) i+=2;
	if(i[1]<val ) i+=1;
	if(i[0]<val) i++;
	return i;
}
struct _Main{

int inline abs(int a){
	return a>>31^((a>>31)+a);
}
int inline max(int a,int b){
	return (a+b+abs(a-b))>>1;
}	
	
void read( int &ans){
	char t;
	while(!isdigit(t=getchar())){
//		if(t=='0') f=-1;
	}
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
}

int n;
_Main(){
	int i,j,k;
	int ans=0;
	read(n);
	if(n>100000){
		memset(dp,127,4000008);
	}else if(n>10000){
		memset(dp,127,400008);
	}else if(n>1000){
		memset(dp,127,40008);
	}else if(n>100){
		memset(dp,127,4008);
	}else {
		memset(dp,127,408);
	}
	erfen=&erfen5;
	int *it;
	read(j);
	dp[1]=j;
	ans=1;
	
	for(i=1;i<n;i++){
		read(j);
		it=erfen(j);
		*it=j;
		//k=max(ans,it-dp);
		if(it-dp>ans){
			ans=it-dp;
			if(ans<99){
				erfen=&erfen5;
			}else if(ans<999){
				erfen=&erfen4;
			}else if(ans<9999){
				erfen=&erfen3;
			}else if(ans<999999){
				erfen=&erfen2;
			}else {
				erfen=&erfen1;
			}
		}
	}
	printf("%d",ans);
	
	
}
	
	
	
	
}cdvs3955;
