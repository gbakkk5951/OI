#include<cstdio>
int main()
{ unsigned long long i,j,n=0,a[9999]={0,1},c,b;
    printf("���������������ע�ⲻҪ̫�󣬲�Ȼ���Զ������㱬����");
    printf("\n             ���꣬��������Ե�ʱ���ˣ���");
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
       printf("                     ���ǵ�����" );
       else
           printf("                 ��TM������");
}
