#include<cstdio>
#include<cctype>
using namespace std;
struct _Main{
int read(){//�����Ż� 
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

int inline abs(int a){//ȡ����֧�ľ���ֵ 
	return a>>31^((a>>31)+a);
}
int inline max (int a,int b){//ȡ����֧�����ֵ 
	return (a+b+abs(a-b))>>1;
}
int inline min (int a,int b){//ȡ����֧����Сֵ 
	return (a+b-abs(a-b))>>1;
}
int n,m;
int k[200010];
int t[200017];
void fresh(){
	int i;
	goal++;
	for(i=lar;i>goal;){//ѭ��չ����ֻ������Ҫ���µ� 
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
	for(;i>=goal;i--){//��β 
		if(i+k[i]>=n){
			t[i]=1;
		}else{
			t[i]=1+t[i+k[i]];
		}
	}
}
int goal;//��Ҫ���µ���Сλ�� 
int lar;//��Ҫ���µ����λ�� 
_Main(){
	int i,j,l;
	n=read();
	for(i=0;i<n;i++){
		k[i]=read();
	}
	lar=n-1;
	goal=0;
	fresh();//��֪��Ϊʲôһ����ˢһ��Ȳ�ˢҪ�� 
	lar=-1; 
	m=read();
	for(i=0;i<m;i++){
		l=read();
		j=read();
		if(l==1){
			goal=j;//���µ���Ҫ���λ�ü���
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
			if(l!=t[j])//ֻ�в����ı�Ÿ������ֵ 
				lar=max(lar,j-1);
		}
	}
}
}cdvs2333;int main(){}
