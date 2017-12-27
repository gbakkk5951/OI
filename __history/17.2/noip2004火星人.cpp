#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int n,m;
int data[10010];
void ex(int &a,int &b);
int min(int a,int b){
	return a<b?a:b;
}
void down(int l);
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	int r=n-1;
	for(i=0;i<n;i++){
		scanf("%d",data+i);
	}
	
	
	i=0;
	while(i<m){

	for(j=n-2;j>=0;j--){
		if(data[j]<data[j+1]){
			break;
		}
	}
	int mn=2147483647;
	int mnu=k;	
	for(k=j+1;k<n;k++){
		if(data[k]<mn&&data[k]>data[j])
		{
		mnu=k;
		mn=data[k];
		}
		
	}
	
	
	

	ex(data[j],data[mnu]);
	
	down(j+1);
	
i++;
}
	
	
	
	
	
	
	
	
	
	
	
		
		
	
	
for(i=0;i<n;i++){
	printf("%d ",data[i]);
}
	
	
	
	
	
}
void ex(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void down(int l){
	int i=l;
	int j=n-1;
	while(i<j){
		ex(data[i],data[j]);	
		i++;j--;
	}
}
