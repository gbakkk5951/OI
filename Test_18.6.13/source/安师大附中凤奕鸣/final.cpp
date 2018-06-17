#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(){
	int n,x,y;
	freopen ("final.in","r",stdin);
	freopen ("final.out","w",stdout);
	scanf ("%d",&n);
	if (n==1){
	   scanf ("%d",&x);
	   if (x==1){
		  cout<<1;
	   }
	   else{
			cout<<"no solution";
	   }
	   return 0;
	}
	if (n>=2){
	   scanf ("%d%d",&x,&y);
	   for (register int i=-2000;i<=2000;i++){
		   for (register int j=-2000;j<=2000;j++){
			   if (x*j-y*i==1){
				  printf ("%d %d\n%d %d",x,y,i,j);
				  return 0;
			   }
		   }
	   }
	   return 0;
	}
	cout<<"no soution";
	return 0;
}
