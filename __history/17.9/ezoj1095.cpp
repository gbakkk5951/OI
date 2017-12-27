using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
const double eps=1e-8;
 
struct _Main{
	
	
	
double inline pf(double a){
    return a*a;
}
bool getformula(int bird1,int bird2,double &a,double &b){
    b=  (y[bird2]-(pf(x[bird2])*y[bird1])/pf(x[bird1])) 
       /(x[bird2]-pf(x[bird2])/x[bird1]);
    a=(y[bird1]-b*x[bird1])/pf(x[bird1]);
    return a<-eps;
}
 	int hit[400];int hcnt;
    double x[20],y[20];
    int dp[(1<<18)+50];
    int tot[(1<<18)+50];
    _Main(){
        int T;int i,j,k;int n;int m;int I;double a,b;int cnt;int s;bool fail;
        int lim;int mn;
        for(I=(1<<18)-1;I;I--){

		}
		
		scanf("%d",&T);
        memset(dp,63,sizeof(dp));
        
        
        while(T--){
        	hcnt=0;
            scanf("%d%d",&n,&m);
            for(i=0;i<n;i++){
                scanf("%lf%lf",&x[i],&y[i]);
            }
            for(i=0;i<n-1;i++){
                for(j=i+1;j<n;j++){
                    if(getformula(i,j,a,b)){
                        for(k=0,cnt=0,s=0;k<n;k++){
                            if(fabs(y[k]-(a*pf(x[k])+b*x[k]))<eps){
                                cnt++;
                                s|=(1<<k);
                            }
                        }
                        hit[hcnt++]=s;
                    }
                }
            }
            sort(hit,hit+hcnt);
            hcnt=unique(hit,hit+hcnt)-hit;
            lim=n;mn=2;
            dp[(1<<n)-1]=0;
            if(m==1){
                lim=ceil(n/3.0+1);
            }else
            if(m==2){
                mn==n/3;
                if(mn<2)goto EndIf;
                lim=n-(mn)+1;
            }
            EndIf:
            for(I=((1<<n)-1);I;I--)if(dp[I]+1<lim){
            	if(tot[I]==0){
            		for(i=0;i<n;i++) if(I&(1<<i)){
    					tot[I]++;
					}
				}
				for(i=0;i<hcnt;i++)if(I&hit[i]){
					dp[I^(I&hit[i])]=min(dp[I^(I&hit[i])],dp[I]+1);
					if(I&hit[i]==I){
						lim=min(lim,dp[I]+1);
					}
				}
                lim=min(lim,dp[I]+tot[I]);
            }
            memset(dp,63,sizeof(int)*((1<<n)+10));
            printf("%d\n",lim);
        }
    }
    
}ezoj1095;
