#include<cstdio>
int main()
{int t1,t2,t3,t4;
scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
if(t1<t2&&t2<t3&&t3<t4)
printf("Fish Rising");
else if(t1>t2&&t2>t3&&t3>t4)
printf("Fish Diving");
else if(t1==t2&&t2==t3&&t3==t4)
printf("Fish At Constant Depth");
else printf("No Fish");
}
