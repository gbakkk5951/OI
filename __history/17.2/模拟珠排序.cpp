#include<cstdio>
#include<cstdlib>
#include<cstring>
bool BeadSort( int size);
    int array[10000];
int main()
{
FILE *a=freopen("�����.out","r",stdin);
FILE *b=freopen("ģ��������.txt","w",stdout);
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
  
//ȷ��ÿ�����ӵ�������  

    len=32768;  

//��ʼ��  
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
//��ʼ����ϣ������е�����˳�������ӱ�ʾ��  
  
//��������������  
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
//�����������  
  
//�ռ����ӣ�ͳ��ÿһ���ж��ٸ�����  
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
//�������  
//

    return true;  
}
