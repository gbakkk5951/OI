using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
const char g[]="Left";
const char l[]="Right";
const char e[]="Balance";
const char no[]="Unknown";
bool link[305][305];//link[a][b] a>b
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}	
int n,p,q;
_Main(){
	int a,b,c;int i,j,k;
	read(n);read(p);read(q);
	for(i=1;i<=n;i++){
		link[i][i]=1;
	}
	for(i=1;i<=p;i++){
		read(a);read(b);read(c);
		switch (a){
			case 1:{
				link[b][c]=1;
				break;
			}
			case 2:{
				link[c][b]=1;
				break;
			}
			case 3:{
				link[b][c]=link[c][b]=1;
				break;
			}
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(link[i][k] && link[k][j]){
					link[i][j]=1;
				}
			}
		}
	}
	for(i=0;i<q;i++){
		read(a);read(b);
		if(link[a][b]){
			if(link[b][a]){
				printf("%s\n",e);
			}else{
				printf("%s\n",g);
			}
		}else{
			if(link[b][a]){
				printf("%s\n",l);
			}else{
				printf("%s\n",no);
			}
		}
		
	}
}	
		
}ezoj1012;
