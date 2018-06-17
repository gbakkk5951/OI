#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(){
	int n,i;
	long double f=1.0*expl(-1.0);
	freopen ("homework.in","r",stdin);
	freopen ("homework.out","w",stdout);
	scanf ("%d",&n);
	if (n==0){
	   printf ("0.6321");
	   return 0;
	}
	for (i=2;i<=n;i++){
		f=1.0-f*i;
	}
	printf ("%.4lf",(double)f);
	return 0;
}
