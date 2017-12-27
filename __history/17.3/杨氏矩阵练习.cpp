#include<cstdio>
#include<limits>
#include<algorithm>
using namespace std;
struct yo_ma{
	int mx=numeric_limits<int>::max();
	yo_ma(){
		int i,j;
			for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			arr[i][j]=mx;
		}	
	}
	}
	int m=10,n=10;
	int arr[400][400];
	void print(){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",arr[i][j] );
		}
		printf("\n");
	}
}
void del(int i,int j){
	change(i,j,mx);
}
void change(int i,int j,int val){
	if(arr[i][j]<val){
		arr[i][j]=val;
		while(i<m&&j<n){
				if(i<m-1&&arr[i+1][j]<arr[i][j]){
			if(j<n-1&&arr[i][j+1]<arr[i+1][j]){
				swap(arr[i][j+1],arr[i][j]);
				j++;
			}else{
				swap(arr[i+1][j],arr[i][j]);
				i++;
			}
		}
		else 	if(j<n-1&&arr[i][j+1]<arr[i][j]){
			if(i<m-1&&arr[i][j+1]>arr[i+1][j]){
				swap(arr[i+1][j],arr[i][j]);
				i++;
			}else{
				swap(arr[i][j+1],arr[i][j]);
				j++;
			}	
		}else return;
		}
	}else
	if(arr[i][j]>val)
		{
		arr[i][j]=val;
		while(i>=0&&j>=0){
				if(i&&arr[i-1][j]>arr[i][j]){
			if(j&&arr[i][j-1]>arr[i-1][j]){
				swap(arr[i][j-1],arr[i][j]);
				j--;
			}else{
				swap(arr[i-1][j],arr[i][j]);
				i--;
			}
		}
		else if(j&&arr[i][j-1]>arr[i][j]){
			if(i&&arr[i-1][j]>arr[i][j-1]){
				swap(arr[i-1][j],arr[i][j]);
				i--;
			}else{
				swap(arr[i][j-1],arr[i][j]);
				j--;
			}
		}else return;	
		}
	}
}
bool insert(int val){

	if(arr[m-1][n-1]!=mx){
		return false;
	}
	change(m-1,n-1,val);
}
bool find(int val){
	int i,j;
	i=0,j=n-1;
	while(i>=0&&j>=0){
		if(val==arr[i][j])
		return true;
		if(arr[i][j]>val){
			j--;
		}else{
			i++;
		}
	}
	return false;
}

}instance;
int main(){
	#define m instance
	char s[10];		
	int t,t2,t1;
	while(1){
		scanf("%s",s);
		switch(s[0]){
			case 'q':{
				scanf("%d",&t);
				if(instance.find(t)){
					printf("yes\n");
				}else{
					printf("no\n");
				}
				break;
			}
			case 'i':{
				scanf("%d",&t);
				m.insert(t);
				break;
			}case 'd':{
				scanf("%d%d",&t,&t1);
				m.del(t,t1);	
				break;
			}
			case'c':{
				scanf("%d%d%d",&t,&t1,&t2);
				
				m.change(t,t1,t2);
				break;
			}
			case'p':{
				m.print();
				break;
			}
			
		}
	}
}
