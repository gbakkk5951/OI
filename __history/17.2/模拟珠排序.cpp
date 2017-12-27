#include<cstdio>
#include<cstdlib>
#include<cstring>
bool BeadSort( int size);
    int array[10000];
int main()
{
FILE *a=freopen("随机数.out","r",stdin);
FILE *b=freopen("模拟珠排序.txt","w",stdout);
BeadSort(10000) ;
int i=0;
for(i=0;i<10000;i++)
 printf("%d ",array[i]);
fclose(a);fclose(b);

}


bool BeadSort( int size)  
{  

    

    
	char **bead;  
    int i, j, k, n, len;  
      for(i=0;i<10000;i++)
      scanf("%d",&array[i] );
      
      
    if(array == NULL) {  
        return false;  
    }  
  
//确定每行珠子的最大个数  

    len=32768;  

//初始化  
    bead = (char **)calloc(size, sizeof(char *));  
    if(bead == NULL) {  
        return false;  
    }  
  
    for(i = 0; i < size; i++) {  
        bead[i] = (char *)calloc(len, sizeof(char));  
        if(bead[i] == NULL) {  
            return false;  
        }  
    }  
  
    for(i = 0; i < size; i++) {   
        for(j = 0; j < array[i]; j++) {  
            bead[i][j] = 1;  
        }  
    }  
//初始化完毕，将所有的数按顺序用珠子表示。  
  
//让珠子自由下落  
        for(j = 0; j < len; j++) {  
        i = k = size-1;  
        while(i >= 0) {  
            if(bead[i--][j] == 1) {  
                bead[k--][j] = 1;  
            }  
        }  
  
        while(k >= 0) {  
            bead[k--][j] = 0;  
        }  
    }  
//自由下落完毕  
  
//收集珠子，统计每一行有多少个珠子  
        for(i = 0; i < size; i++) {  
        j = n = 0;  
        while(j < len) {  
            if(bead[i][j++] == 0) {  
                break;  
            }  
            n++;  
        }  
  
        array[i] = n;  
       
    }  
//排序完成  
//

    return true;  
}
