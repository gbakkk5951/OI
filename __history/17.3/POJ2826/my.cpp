#include<cstdio>
#define eps 1e-8
int main(){}
struct begin{
	double min(double inx,double iny){
		return inx<iny?inx:iny;
	}
	double max(double a,double b){
		return a>b?a:b;
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
		
		scanf("%d",&l);
		while(l--){
			readin();
			calc();
			printf("%.2f\n",ans+eps);
		}
	}
	void readin()
	{	double temp[10];
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
		double fz=  abs((double)((x3-x1)*(y4-y1)-(x4-x1)*(y3-y1)));
		double fm=  abs((double)((x3-x2)*(y4-y2)-(x4-x2)*(y3-y2)));
		//跨立判定 
		if((double)((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1))*((x4-x1)*(y2-y1)-(x2-x1)*(y4-y1))>0)
		{
			return ;
		}
		//第二次跨立判定 
		if((double)((x1-x3)*(y4-y3)-(x4-x3)*(y1-y3))*((x2-x3)*(y4-y3)-(x4-x3)*(y2-y3))>0)
		{
			return ;
		}

		
		
		//真 快速排斥
		double xm=max(x1,x2);
		double xi=min(x1,x2);
		double yi=min(y1,y2);
		double ym=max(y1,y2);
		if(x3>xm&&x4>xm||x3<xi&&x4<xi||y3>ym&&y4>ym||y3<yi&&y4<yi) 
		{return;
		}
		
		
		
		double bili=abs((double)((x3-x1)*(y4-y1)-(x4-x1)*(y3-y1))/((x3-x2)*(y4-y2)-(x4-x2)*(y3-y2)));

		if(x2>x1)
		jx=(double)x1+(x2-x1)*fz/(fz+fm);
		else jx=(double)x1-(x1-x2)*fz/(fz+fm);
		jy=(double)y1+(y2-y1)*fz/(fz+fm);
	
	
	
		if(jx<x1&&jx<x2||jx>x1&&jx>x2||jx<x3&&jx<x4||jx>x3&&jx>x4)
		{
			return;
		 } 
		if(jy<y1&&jy<y2||jy>y1&&jy>y2||jy<y3&&jy<y4||jy>y3&&jy>y4)
		{
			return;
		}
		
		
		double fg=(double)(x2-jx)*(y4-jy)-(x4-jx)*(y2-jy);
			if(eq(fg,0))
			return;
		
		
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
