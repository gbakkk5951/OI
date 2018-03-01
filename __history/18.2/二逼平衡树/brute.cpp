#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
int arr[50010];
const int inf=0x3f3f3f3f;
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
		a*=f;
	}
int main(){
	int n,m;
	int i,j,k;
	int Q,a,b,c;
	int Qtype;
	int ans;
	read(n);read(m);
	for(i=1;i<=n;i++){
		read(arr[i]);
	}
	
	for(Q=1;Q<=m;Q++){
		read(Qtype);
		switch(Qtype){
			case 1:{
				read(a);read(b);read(c);
				ans=1;
				for(i=a;i<=b;i++){
					if(arr[i]<c){
						ans++;
					}
				} 
				printf("%d\n",ans);
				break;
			}
			case 2:{
				read(a);read(b);read(c);
				int sa,sb;
				for(i=a;i<=b;i++){
					sa=sb=0;
					for(j=a;j<=b;j++){
						if(arr[j]<arr[i]){
							sa++;sb++;
						}
					}
					for(j=a;j<=b;j++){
						if(arr[j]==arr[i]){
							sb++;
						}
					}	
					if(sa+1<=c && sb>=c){
						printf("%d\n",arr[i]);
						break;
					}				
				}
				break;
			} 
			case 3:{
				read(a);read(b);
				arr[a]=b;
				break;
			}
			case 4:{
				
				int ans=-inf;
				read(a);read(b);read(c);
				for(i=a;i<=b;i++){
					if(arr[i]<c){
						ans=max(ans,arr[i]);
					}
				}				
				printf("%d\n",ans);
				break;
			}
			case 5:{
				read(a);read(b);read(c);
				int ans=inf;
				for(i=a;i<=b;i++){
					if(arr[i]>c){
						ans=min(ans,arr[i]);
					}
				}				
				printf("%d\n",ans);				
				break;
			}			
			
			
			
		}
		
		
		
	}















}
