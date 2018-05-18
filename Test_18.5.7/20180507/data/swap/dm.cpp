#include<cstdio>
#include<cstdlib>
#include<algorithm>
int A[200010],B[200010],P[200010];
void make(int n,bool e1,bool e2,bool e3=0,bool e4=0){
	if(e1){
		for(int i=0;i<n;i++)A[i]=i,B[i]=(i+1)%n;
	}
	else if(e2){
		for(int i=0;i<n;i++)A[i]=P[i]=i;
		if(e3){
			for(int s=0,t=n-1,i=0;i<n;)P[i++]=s++,P[i++]=t--;
		}
		else{
			std::random_shuffle(A,A+n);
			std::random_shuffle(P+1,P+n);
		}
		for(int i=0,x=0;i<n;i++)B[P[(i+1)%n]]=A[x],x=P[(i+1)%n];
	}
	else{
		for(int i=0;i<n;i++)A[i]=B[i]=i;
		if(e4){
			std::reverse(A,A+n);
			std::random_shuffle(A,A+n/2);
			std::random_shuffle(A+n/2,A+n);
			std::random_shuffle(B,B+n/2);
			std::random_shuffle(B+n/2,B+n);
		}
		else{
			std::random_shuffle(A,A+n);
			std::random_shuffle(B,B+n);
		}
	}
	printf("%d\n",n);
	for(int i=0;i<n;i++)printf("%d%c",A[i]+1," \n"[i==n-1]);
	for(int i=0;i<n;i++)printf("%d%c",B[i]+1," \n"[i==n-1]);
}
int main(){
	srand(748727243);
	for(int i=9;i<=20;i++){
		char fn[100];sprintf(fn,"%d.in",i);
		freopen(fn,"w",stdout);
		if(i==9)make(500,1,0);
		if(i==10)make(2000,1,0);
		if(i==11)make(200000,1,0);
		if(i==12)make(500,0,1);
		if(i==13)make(2000,0,1);
		if(i==14)make(200000,0,1,1);
		if(i==15)make(500,0,0);
		if(i==16)make(500,0,0);
		if(i==17)make(2000,0,0);
		if(i==18)make(2000,0,0);
		if(i==19)make(200000,0,0);
		if(i==20)make(200000,0,0,0,1);
	}
}
