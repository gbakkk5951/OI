#include<cstdio>
#include<cstdlib>
#include<cstring>
int main(){}
int base=8192;	

int inline getrand(){
	return ((rand()&1 )?1:1) *(rand())%10;
}
int inline abs(int a){
	return ((a>>31)+a)^(a>>31);
}
int inline min(int a,int b){
	return ((a+b)-abs(a-b))>>1;
}
int inline max(int a,int b){
	return ((a+b)+abs(a-b))>>1;
}
namespace ZkwA{
	int Node[16500];	
    int GetMin(int s,int t,int L=100000000,int R=100000000){  
        for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){  
            L+=Node[s];R+=Node[t];  
            if(~s&1) L=min(L,Node[s^1]);  
            if( t&1) R=min(R,Node[t^1]);  
		}
		L=min(L+Node[s],R+Node[t]);
		while(s) L+=Node[s>>=1];
		return L;
	}  	
    void Add(int s,int t,int v,int A=0){
        for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){  
            if(~s&1) Node[s^1]+=v;if(t&1) Node[t^1]+=v;  
            A=min(Node[s],Node[s^1]);Node[s]-=A,Node[s^1]-=A,Node[s>>1]+=A;  
            A=min(Node[t],Node[t^1]);Node[t]-=A,Node[t^1]-=A,Node[t>>1]+=A;  
        }
        while(s) {
			A=min(Node[s],Node[s^1]);
			Node[s]-=A;Node[s^1]-=A;Node[s>>=1]+=A; 
		}
	}
}
namespace BruteForce{
	int Data[5003];	
	void Add(int l,int r,int v){
		for(;l<=r;l++){
			Data[l]+=v;
		}
	}
	int GetMin(int l,int r){
		int ans=Data[l];
		for(l++;l<=r;l++){
			ans=min(ans,Data[l]);
		}return ans;
	}
}
struct _Main{


int n;
_Main(){
	int i,j,k;int l,r,v;int l2,r2;
	n=5000;srand(22333);base=8192;
		memset(BruteForce::Data,0,sizeof(BruteForce::Data));
		memset(ZkwA::Node,0,sizeof(ZkwA::Node));
		for(i=1;i<=50000;i++){
			l=rand()%n+1;r=l+(rand()%(n-l+1));v=getrand();
		
			BruteForce::Add(l,r,v);
			ZkwA::Add(l,r,v);
			l2=rand()%n+1;r2=l2+(rand()%(n-l2+1));
	//		printf("Add(%d,%d,%d)\n",l,r,v);
			if(BruteForce::GetMin(l2,r2) != ZkwA::GetMin(l2,r2)){
				printf("GetMin(%d,%d)\n",l2,r2);
				printf("BF:%d,Zkw:%d\n",BruteForce::GetMin(l2,r2),ZkwA::GetMin(l2,r2));
			}
		}
}	

	
}MAIN;
