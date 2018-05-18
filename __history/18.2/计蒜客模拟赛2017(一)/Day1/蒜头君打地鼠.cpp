using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}	
int n,r;	
int even[2010][2010],odd[2010][2010];
int inline oddx(const int &x,const int &y){
	return (x+y)/2;
}
int inline oddy(const int &x,const int &y){
	return (n/2)+(x>y?((1+x-y)/2):((x-y)/2));
}

int inline query(int arr[2010][2010],int a,int b,int c,int d){
	int x1, x2, y1, y2;
	x1=min(a,b);x2=max(a,b);y1=min(c,d);y2=max(c,d);
	x1=max(1,x1);x2=min(x2,n);y1=max(1,y1);y2=min(y2,n);
	return arr[x2][y2]-arr[x1-1][y2]-arr[x2][y1-1]+arr[x1-1][y1-1];
}

int inline evenx(const int &x,const int &y){
	return (x+y)/2;
}
int inline eveny(const int &x,const int &y){
	return (n+1)/2+(x-y)/2;
}

_Main(){
	int i,j;
	int tmp;int ans=0;
	read(n);read(r);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			read(tmp);
			
			ans=max(ans,tmp);
			if((i+j)&1){
				odd[oddx(i,j)][oddy(i,j)]=tmp;
			}else{
				even[evenx(i,j)][eveny(i,j)]=tmp;
			}
		}
	}
	if(r==1){
		printf("%d",ans);
		goto EndMain;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			even[i][j]+=even[i-1][j]+even[i][j-1]-even[i-1][j-1];
			odd[i][j]+=odd[i-1][j]+odd[i][j-1]-odd[i-1][j-1];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			tmp=0;
			if((i+j)&1){
				tmp+=query(odd,oddx(i,j)-(r-1)/2,oddx(i,j)+(r-1)/2,oddy(i,j)-(r-1)/2,oddy(i,j)+(r-1)/2);
				tmp+=query(even,evenx(i-1,j)-(r-2)/2,evenx(i+1,j)+(r-2)/2,eveny(i,j+1)-(r-2)/2,eveny(i,j-1)+(r-2)/2);
				ans=max(ans,tmp);
			}else{
				tmp+=query(even,evenx(i,j)-(r-1)/2,evenx(i,j)+(r-1)/2,eveny(i,j)-(r-1)/2,eveny(i,j)+(r-1)/2);
				tmp+=query(odd,oddx(i-1,j)-(r-2)/2,oddx(i+1,j)+(r-2)/2,oddy(i,j+1)-(r-2)/2,oddy(i,j-1)+(r-2)/2);
				ans=max(ans,tmp);
			}
		}
	}
	printf("%d",ans);
	EndMain:
		fclose(stdout);
}	
	
	
	
	
	
	
}mole;
