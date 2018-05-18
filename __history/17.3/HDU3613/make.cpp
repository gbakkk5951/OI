#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
	freopen("data.in","w",stdout);
	printf("1\n");
	
	
	
	srand(time(NULL));
	int i;
	int s=1;

	for(i=0;i<26;i++){
			if(rand()%2)
	s=-1;
	else s=1;
		printf("%d ",s*(rand()%3));
	}
	int l=rand()%30+2;
	for(i=0;i<l;i++){
		putchar(97+(rand()%2));
	}
	fclose(stdout);
}
