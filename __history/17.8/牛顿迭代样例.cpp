#include<cstdio> 
double a,b,c,d;
#include<cmath>
double func (double x){
	return 3*a*x*x+2*b*x+c;
}
double func1(double x){
	return a*x*x*x+b*x*x+c*x+d;
}	

/*
double func(double x) //函数
{return x*x*x*x-3*x*x*x+1.5*x*x-4.0;}  
double func1(double x) //导函数 　　
{return 4*x*x*x-9*x*x+3*x;}
*/

int Newton(double *x,double precision,int maxcyc)


//初始值，          精度，       迭代次数 　　
{
double x1,x0;
int k;
x0=*x;
for(k=0;k<maxcyc;k++)
{
if(func1(x0)==0.0)//若通过初值，函数返回值为0 　　	
{
printf("迭代过程中导数为0!\n");
return 0;
}
x1=x0-func(x0)/func1(x0);//进行牛顿迭代计算 　　
if(fabs(x1-x0)<precision || fabs(func(x1))<precision) //达到结束条件 　　
{*x=x1;//返回结果 　　
return 1; }
else //未达到结束条件 　　
x0=x1;//准备下一次迭代 　　
}
printf("迭代次数超过预期!\n"); //达到迭代次数，仍没有达到精度 　　
return 0;
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	
double x,precision;
int maxcyc;
printf("输入初始迭代值x0:"); 
x=10;//scanf("%lf",&x);
printf("输入最大迭代次数:"); 
maxcyc=1000000;//scanf("%d",&maxcyc); 
printf("迭代要求的精度:"); 
//scanf("%lf",&precision); 
precision=1e-4;
if(Newton(&x,precision,maxcyc)==1) //若函数返回值为1 　　		

printf("该值附近的根为:%lf\n",x); 
else //若函数返回值为0 　
printf("迭代失败!\n");
getchar(); 
return 0; 
}
