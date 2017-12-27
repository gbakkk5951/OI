#include<stdio.h>

using namespace std;
char * a="A",* b="B",* c="C";
int num;
int main()

{
	scanf("%d",&num);
	void suan(char *,char*,char*,int);
	suan(a,b,c,num);
	
	
	
	
	
 } 
 suan(char * A,char * B,char * C,int times)
 {

  void move(char*,char*);
  
  
  if (times==1)
  move(A,C);
else  {
suan(A,C,B,times-1);move(A,C);suan(B,A,C,times-1);
}
 	
 }
 
 
 
 
 move(char * A,char * B)
 {
 	printf("%s->%s",A,B);
 	
 	
 }
