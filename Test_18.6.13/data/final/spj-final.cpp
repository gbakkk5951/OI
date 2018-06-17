#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

FILE *SCORE,*flog,*frpt,*fin,*fpsn,*fstd;


#define maxn 250

int n;
long long a[maxn][maxn];

int z[120][5];
int d[5]; 
int pow(int x, int y);
int against(int a[]);
int fac(int a);
void swap(int a[], int i, int j);
void perm(int a[], int p, int q);


void close (int score, int reason)
{
  fprintf (flog, "%d\n", score);
  if (score == 0)
    switch (reason)
    {
     case 1: fprintf (frpt, "Wrong Answer\n"); break;
     case 2: fprintf (frpt, "Range Check Error!\n"); break;
     case 3: fprintf (frpt, "Output error\n"); break;
    }
  else
    fprintf (frpt, "Good Job!\n");
  
  fclose (fin);

  fclose (fstd);
  fclose (flog);
  fclose (frpt);
  exit(0);
}

bool check(long long &m)
{
	for (int i = 0; i < n; i++)  
        d[i] = i;  
    perm(d, 0, n - 1);  
    long long s;  
    m = 0;  
    for (int i = 0; i < fac(n); i++)
    {  
        s = 1;
        for (int j = 0; j < n; j++)
            s = s*a[j][z[i][j]];  
        m = m + pow(-1, against(z[i]))*s;  
    } 
    if(m == 1)
    	return 1;
    else
    	return 0;
}

int main(int argc, char *argv[])
{

     

    SCORE = fopen(argv[4],"r");
    flog = fopen(argv[5],"w");
    frpt = fopen(argv[6],"w");

    fin  = fopen (argv[1], "r");
    fpsn = fopen (argv[2], "r");
    fstd = fopen (argv[3], "r");

  fscanf(fin, "%d", &n);
  
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j)
  		fscanf(fpsn, "%lld", &a[i][j]);
  long long m;
  if(check(m))
  	close(10, 3);
  else
  	close(0, 1);
  return 0; 
}

int pow(int x, int y)  
{  
    int s = 1;  
    for (; y >= 1; y--)  
        s = s*x;  
    return s;  
}  

int fac(int a)  
{  
    int s = 1;  
    for (; a >= 1; a--)  
        s = s*a;  
    return s;  
}  
int against(int a[])  
{  
    int nn = 0;  
    for (int i = 0; i < n - 1; i++)  
    {  
        for (int j = i + 1; j < n; j++)  
        {  
            if (a[i] > a[j])  
            {  
                nn++;  
            }  
            else  
                ;  
        }  
    }  
    return nn;  
}  
void swap(int a[], int i, int j)  
{  
    int temp;  
    temp = a[i];  
    a[i] = a[j];  
    a[j] = temp;  
}  
void perm(int a[], int p, int q)  
{  
    static int g = 0;
    if (p == q)
    {  
        for (int i = 0; i < n; i++)  
        {  
            z[g][i] = a[i];  
        }  
        g++;  
    }  
    else  
    {  
        for (int i = p; i <= q; i++)
        {  
            swap(a, p, i);  
            perm(a, p + 1, q);  
            swap(a, p, i);  
        }  
    }  
}  

