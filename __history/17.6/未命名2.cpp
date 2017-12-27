#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int m=50000,q=1,a,b,c,d,r=6,k,x,ran,h[233],n[233],s[233],f[233]={0,500,1000,2000,4000,8000,100,200,400,800},g[233]={0,100,200,300,400,500,3000,5000,7000,9000},p[233]={0,20,40,90,190,400,50,80,130,190},t;
char o;
int main()
{
 int i;
 srand(time(0));
 for(i=1;i<=9;i++)
 {
  h[i]=h[i]*0.95; 
 }
 for(;;t++)
 {
  a=r*r*r*(rand()%70+80);
  printf("day %d:you have %d blocks and %d yuan\n. a. buy a block(%d) b.plant something\nc.steal something d.sell something. others:do nothing\n",t,r,m,a);
  o=getch();
  if(o=='a')
  {
   if(m>=a)
   {
    m-=a;
    r++;
   }
   else
   {
    printf("money is not enough!\n");
    continue;
   }
   q=1;
  }
  else if(o=='b')
  {
   printf("what do you want to plant? 0 means plant nothing\n");
   for(i=1;i<=9;i++)
   {
    n[i]=f[i]+rand()%g[i];
    printf("%d: %d*%d=%d\n",i,n[i],r,n[i]*r);
   }
   do
   {
    o=getch();
   }
   while(o<'0'&&o>'9');
   if(o=='0')
   {
    m-=400*r;
    continue;
   }
   if(m>=n[o-'0']*r)
   {
    m-=n[o-'0']*r;
   }
   else
   {
    printf("money is not enough!\n");
    continue;
   }
   x=0;
   for(i=1;i<=1000;i++)
   {
    //Sleep(1000);
    ran=rand()%100;
    x+=rand()%(5*r);
    if(ran==13||ran==38||ran==0||ran==25)
    x/=2;
    if(ran==4||ran==44)
    x/=5;
    if(ran==66||ran==88||ran==99)
    x*=2;
    if(ran==96||ran==98||ran==69)
    x+=rand()%(20*r);
    printf("%d\n",x);
   }
   h[o-'0']+=x;
  }
  else if(o=='c')
  {
   if(rand()%5!=0)
   {
    printf("succeed!\n");
    m+=rand()%50000;
   }
   else
   {
    printf("fail\n");
    m/=3;
   }
  }
  else if(o=='d')
  {
   printf("what do you want to sell? 0 means sell nothing\n");
   for(i=1;i<=9;i++)
   {
    s[i]=rand()%(p[i]*2);
    printf("%d: %d*%d=%d\n",i,s[i],h[i],s[i]*h[i]);
   }
   do
   {
    o=getch();
   }
   while(o<'0'&&o>'9');
   if(o==0)
   {
       m-=400*r;
    continue;
   }
   m+=s[o-'0']*h[o-'0'];
   h[o-'0']=0;
  }
  m-=400*r;
  if(m<0)
  break;
 }
 printf("you haveno money!\n");
}
