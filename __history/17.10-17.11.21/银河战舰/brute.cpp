using namespace std;
int main(){}
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>

namespace Protector{
	const double pi=acos(-1.0);
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
	int n,m;
	double x[100005],y[100005];
	_Main(){
		int I;
		int i,j,k;
		char oper[3];
		double agr[2];
		double nx,ny;
		int a,b,c;
		read(n);
		for(i=1;i<=n;i++){
			scanf("%lf",&x[i]);
			scanf("%lf",&y[i]);
		}
		read(m);
		for(I=0;I<m;I++){
			scanf("%s",oper);
			read(a);read(b);		
			switch(oper[0]){
		
				case 'M':{
					for(j=0;j<=1;j++){
						scanf("%lf",agr+j);
					}
					for(i=a;i<=b;i++){
						x[i]+=agr[0];
						y[i]+=agr[1];
					}
					break;
				}
				case 'X' :{
					for(i=a;i<=b;i++){
						y[i]=-y[i];
					}					
					break;
				}
				case 'Y' :{
					for(i=a;i<=b;i++){
						x[i]=-x[i];
					}				
					break;
				}
				case 'O' :{
					for(i=a;i<=b;i++){
						swap(x[i],y[i]);
					}						
					break;
				}
				case 'R' :{
					scanf("%lf",&agr[0]);
					for(i=a;i<=b;i++){
						nx=x[i]*cos(agr[0]/180.0*pi)+y[i]*(-sin(agr[0]/180.0*pi));
						ny=x[i]*sin(agr[0]/180.0*pi)+y[i]*cos(agr[0]/180.0*pi);
						x[i]=nx;y[i]=ny;
						
					}
					break;
				}
			}
		}
		for(i=1;i<=n;i++){
			printf("%.2lf %.2lf\n",x[i],y[i]);
		}
	}
	
}GalaxyBattleship;




}
