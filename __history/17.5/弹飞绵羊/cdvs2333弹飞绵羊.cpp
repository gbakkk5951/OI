#include<cstdio>
#include<cctype>
using namespace std;
struct _Main{
int read(){//读入优化 
	char t;
	int ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}	

int inline abs(int a){//取消分支的绝对值 
	return a>>31^((a>>31)+a);
}
int inline max (int a,int b){//取消分支的最大值 
	return (a+b+abs(a-b))>>1;
}
int inline min (int a,int b){//取消分支的最小值 
	return (a+b-abs(a-b))>>1;
}
int n,m;
int k[200010];
int t[200017];
void fresh(){
	int i;
	goal++;
	for(i=lar;i>goal;){//循环展开，只更新需要更新的 
		if(i+k[i]>=n){
			t[i]=1;
		}else{
			t[i]=1+t[i+k[i]];
		}
		i--;
		if(i+k[i]>=n){
			t[i]=1;
		}else{
			t[i]=1+t[i+k[i]];
		}
		i--;	
		if(i+k[i]>=n){
			t[i]=1;
		}else{
			t[i]=1+t[i+k[i]];
		}
		i--;			
	}
	goal--;
	for(;i>=goal;i--){//收尾 
		if(i+k[i]>=n){
			t[i]=1;
		}else{
			t[i]=1+t[i+k[i]];
		}
	}
}
int goal;//需要更新的最小位置 
int lar;//需要更新的最大位置 
_Main(){
	int i,j,l;
	n=read();
	for(i=0;i<n;i++){
		k[i]=read();
	}
	lar=n-1;
	goal=0;
	fresh();//不知道为什么一上来刷一遍比不刷要快 
	lar=-1; 
	m=read();
	for(i=0;i<m;i++){
		l=read();
		j=read();
		if(l==1){
			goal=j;//更新到需要查的位置即可
			fresh();
			lar=min(j-1,lar);
			printf("%d\n",t[j]);
		}else{
			k[j]=read();
			l=t[j];
			if(j+k[j]>=n){ 
				t[j]=1;
			}else{
				t[j]=1+t[j+k[j]];
			}
			if(l!=t[j])//只有步数改变才更新最大值 
				lar=max(lar,j-1);
		}
	}
}
}cdvs2333;int main(){}
