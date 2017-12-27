using namespace std;
int main(){}
#include<cstdio>
#include<cstdlib>
#include<algorithm>
struct Main{
int n;
int a[100];
int b[100];	
int sa,sb;
Main(){
	
	
	bool finish=false;
	scanf("%d",&n);
	
	
	for (int i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		sa+=a[i];sb+=b[i];
	}
	while(!finish){
		finish=true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(abs((sa-a[i]+b[i])-(sb+a[i]-b[i]))<abs(sa-sb)){
					swap(a[i],b[i]);
					finish=false;
				}
				
			}
			
		}
	}
	printf("%d",abs(sa-sb));
	
	
}	
	
	
}c;
