#include<cstdio>
  int invert(int e, int f)  ;
    int main(){
        int a,b;
        while(1)
        {scanf("%d%d",&a,&b);
        printf("%d\n",invert(a,b));
        }
    }
    
    
    int invert(int e, int f)  
    {  
        int a = f, b = e, t1 = 0, t2 = 1;  
          
        while(b != 0)  
        {  
            int t = a;  
            a = b;  
            int q = t / b;  
            b = t % b;  
              
            t = t1 - q * t2;  
            t1 = t2;  
            t2 = t;  
        }  
          
        if(t1 < 0)  //��չŷ������㷨�õ��Ľ������Ϊ������������Ҫ������������  
            t1 += f;  
        return t1;  
    }  
