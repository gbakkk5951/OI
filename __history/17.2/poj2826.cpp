#include<cstdio>
#define eps 1e-8
int main(){}
struct begin{
	double min(double inx,double iny){
		return inx<iny?inx:iny;
	}
	double abs(double inx){
		if(inx<0)
		inx=-inx;
		return inx;
	}
	bool eq(double inx,double iny){
		if((inx>iny&&inx>iny+eps)||(inx<iny&&inx<iny-eps))
		return false;
		return true;
	}
	int l;
	double x1,y1,x2,y2,x3,y3,x4,y4;
	double jx,jy;
	double ans;
	begin(){
		freopen("data.in","r",stdin);
		freopen("my.out","w",stdout);
		
		scanf("%d",&l);
		while(l--){
			readin();
			calc();
			printf("%.2f\n",ans+eps);
		}
	}
	void readin()
	{	int temp[10];
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);	
		if(y1>y2){
			temp[0]=y2;
			y2=y1;
			y1=temp[0];
			temp[0]=x2;
			x2=x1;
			x1=temp[0];
		}
		if(y3>y4){
			temp[0]=y4;
			y4=y3;
			y3=temp[0];
			temp[0]=x4;
			x4=x3;
			x3=temp[0];
		}		
	}
	void calc(){
		double tp[10];
		ans=0;
		double temp=((x3-x2)*(y4-y2)-(x4-x2)*(y3-y2));
		if(eq(temp,0))
		{
			ans=0;
			return;
		}
		//·Ö×Ó  abs(double)((x3-x1)*(y4-y1)-(x4-x1)*(y3-y1))
		//·ÖÄ¸  abs(double)((x3-x2)*(y4-y2)-(x4-x2)*(y3-y2))
		
		double bili=abs((double)((x3-x1)*(y4-y1)-(x4-x1)*(y3-y1))/((x3-x2)*(y4-y2)-(x4-x2)*(y3-y2)));
		if(x2>x1)
		jx=(double)x1+(x2-x1)*bili/(bili+1);
		else jx=(double)x1-(x1-x2)*bili/(bili+1);
		jy=(double)y1+(y2-y1)*bili/(bili+1);

		if(jx<x1&&jx<x2||jx>x1&&jx>x2||jx<x3&&jx<x4||jx>x3&&jx>x4)
		{
			return;
		 } 
		if(jy<y1&&jy<y2||jy>y1&&jy>y2||jy<y3&&jy<y4||jy>y3&&jy>y4)
		{
			return;
		}
		
		
		double fg=(double)(x2-jx)*(y4-jy)-(x4-jx)*(y2-jy);
			if(fg>0){
				if(x4>x2+eps||eq(x4,x2)){
					ans=0;
					return;
				}
				else{
					if(y2<y4)
					x4=(x4-jx)*(y2-jy)/(y4-jy)+jx;
					else
					x2=(x2-jx)*(y4-jy)/(y2-jy)+jx;			
					ans=(min(y2,y4)-jy)*abs(x2-x4);
					ans/=2;
					ans=abs(ans);
					return;
				}
				
			}else{
				if(x2>x4+eps||eq(x4,x2)){
					ans=0;
					return;
				}else{
					if(y2<y4)
					x4=(x4-jx)*(y2-jy)/(y4-jy)+jx;
					else
					x2=(x2-jx)*(y4-jy)/(y2-jy)+jx;
					ans=(min(y2,y4)-jy)*abs(x4-x2);
					ans/=2;
					ans=abs(ans);
					return;
				}
			}
	}
}instance;
