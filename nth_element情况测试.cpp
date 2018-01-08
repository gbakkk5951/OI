using namespace std;
int main () {}
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring>
namespace Protector {



void shuffle(int arr[], int size){
    int i;
    for(i = 1; i < size; i++) {
        swap(arr[i], arr[rand() % (i + 1)]);
    }
}
int arr1[5000050];
int arr2[5000050];
const int maxn = 5000000;
int lrand() {
    return (int)rand() << 15 ^ (int)rand();
}
struct _Main{
_Main(){
    int I; 
    float t_a, t_b;
    int i, j, k;
    for (I = 0; I <= 15; I++) {
        printf("I = %d\n", I);
        
        //随机数据
        if (I / 2 == 0) {
            for (i = 0; i < maxn; i++) {
                arr1[i] = lrand();
            }
        }
        //每种1000个
        if (I >> 1 == 1) {
            int t;
            for (i = 0 ; i < 5000; i++) {
                t = lrand();
                for (j = 0; j < 1000; j++) {
                    arr1[i * 1000 + j] = t;
                }
            }
        }
        
        //每种1000个 + 2个1000000个
        if (I >> 1 == 2) {
            int t;
            for (i = 0 ; i < 3000; i++) {
                t = lrand();
                for (j = 0; j < 1000; j++) {
                    arr1[i * 1000 + j] = t;
                }
            }
            for (i = 0; i < 2; i++) {
                t = lrand();
                for (j = 0; j < 1000000; j++) {
                    arr1[(i + 3) * 1000000 + j] = t;
                }
            }
        }        
        
        //每种50个
        
        if (I >> 1 == 3) {
            int t;
            for (i = 0 ; i < 100000; i++) {
                t = lrand();
                for (j = 0; j < 50; j++) {
                    arr1[i * 50 + j] = t;
                }
            }

        }        
        
        //每种50个 +  2个1000000个
        if (I >> 1 == 4) {
            int t;
            for (i = 0 ; i < 60000; i++) {
                t = lrand();
                for (j = 0; j < 50; j++) {
                    arr1[i * 50 + j] = t;
                }
            }
            for (i = 0; i < 2; i++) {
                t = lrand();
                for (j = 0; j < 1000000; j++) {
                    arr1[(i + 3) * 1000000 + j] = t;
                }
            }
        }                
        // 2个 2000000个 + rand
        if (I >> 1 == 5) {
            int t;
            for (i = 0 ; i < 3000000; i++) {
                arr1[i] = lrand();
            }
            for (i = 0; i < 2; i++) {
                t = lrand();
                for (j = 0; j < 1000000; j++) {
                    arr1[(i + 3) * 1000000 + j] = t;
                }
            }
        }                
        //4500000一样 
        if (I >> 1 == 6) {
            int t;
            for (i = 0 ; i < 500000; i++) {
                arr1[i] = lrand();
            }
            t = lrand();
            for (j = 0; j < 4500000; j++) {
                arr1[500000 + j] = t;
            }
        }
        //全一样
        if (I >> 1 == 7) {
            int t = lrand();
            for (j = 0; j < 5000000; j++) {
                arr1[j] = t;
            }         
        }
        EndFor:
        if  (I & 1) {
            shuffle(arr1,maxn);
        }
        for (i = 0; i < maxn; i += 1000000 - 1){
            memcpy(arr2, arr1, maxn * sizeof(int));
            t_a = clock();
            nth_element(arr2, arr2 + i,arr2 + maxn);
            t_b = clock();
            printf("nth[%d]:%f\n", i, t_b - t_a);                  
        }
        t_a = clock();
        sort(arr1, arr1 + maxn);
        t_b = clock();
        printf("sort:%f\n", t_b - t_a);        
    }

    
    
     
} 

}tst;

}


