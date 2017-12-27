#include<cstdio>
int main()
{ unsigned long long i,j,n=0,a[9999]={0,1},c,b;
    printf("请输入计算行数，注意不要太大，不然电脑都给你算爆！！");
    printf("\n             少年，检验你电脑的时候到了！！");
    printf("\n");
         scanf("%d",&n);


   for(i=1;i<=n;i++)
   { c=0;
     for(j=1;j<=i;j++)
     { b=a[j];
       a[j]=c+b;  
       c=b;
       printf("%llu  ",a[j]);  
     }
     printf("\n");
   }
                   if(n<30)
       printf("                     明智的输入" );
       else
           printf("                 你TM作死啊");
}
