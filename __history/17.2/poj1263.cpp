#include <cstdio>
#define eps 1e-10
#include<cmath>
struct circle_class{
	int x,y,r;
};

struct qdzcx{
int n;
double x,y,dx,dy;
int hit[20];
int num;
circle_class circle[30];


qdzcx{
	readin();
	calc();
	output();
}

void readin(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d",&circle[i].x,&circle[i].y,&circle[i].r );
	}
	scanf("%lf%lf%lf%lf",&x,&y,&dx,&dy);	
}

double pf(double in){
	return in*in;
}

void calc(){
	int i,j,k;
	double temp[10];
	int nu=-1;double dis=2147483647;
	
for(k=0;k<11;k++)
{
	nu=-1;dis=2147483647;
	
	
	for(i=0;i<n;i++){
		temp[0]=(circle[i].x -x)*(circle[i].x -x) + (circle[i].y-y)*(circle[i].y-y)  //到圆心距离 的平方 
		temp[1]=((circle[i].x-x)*(dy-y)-(dx-x)*(circle[i].y-y));//两点叉乘 
		if(temp[1]<0)
		continue;//不可能相交 
		//求是否小于r 
		temp[2]=pf(circle[i].x-x)+pf(circle[i].y-y)-pf(temp[1])/(pf(dx-x)+pf(dy-y));//c^2
		if(sqrt(temp[2])>circle[i].r){
			continue;
		}
		temp[3]=pf(circle[i].r)-temp[2];//d^2
		temp[4]=sqrt(pf(temp[1])/(pf(dx-x)+pf(dy-y)) )-sqrt(temp[3]);//到圆的距离 
		if(temp[4]<dis){
			nu=i;
			dis=temp[4];
		}
	}
	hit[k]=nu;
	if(!nu^-1){
		return; 
	}
	num++;
/* new cosΘ*/ temp[5]=(dx-x)/sqrt(pf((dy-y))+pf(dx-x));
/*new x*/	temp[6]=x+temp[4]*temp[5];
/*new y*/   temp[7]=y+temp[6]*(dy-y)/(dx-x);
	
	
	
	
	
}
	
	
}






}exe;

int main(){}
