#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

FILE *SCORE,*flog,*frpt,*fin,*fpsn,*fstd;


#define maxn 250

int n;
double d[maxn][maxn];
double x[maxn][2];

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

double dist(double a[], double b[])
{
	double d0 = a[0]-b[0];
	double d1 = a[1]-b[1];
	return sqrt(d0*d0+d1*d1);
}

bool check()
{
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
		  if(fabs(dist(x[i], x[j])-d[i][j]) > 1e-3)
		    return 0;
	return 1;
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
  for(int i = 1 ;  i <= n ; ++i)
  	for(int j = 1 ; j <= n ; ++j)
	  fscanf(fin, "%lf", &d[i][j]);
  
  for(int i = 1 ; i <= n ; ++i)
  	fscanf(fpsn, "%lf %lf", &x[i][0], &x[i][1]);
  
  if(check())
  	close(10, 3);
  else
  	close(0, 1);
  return 0; 
}
