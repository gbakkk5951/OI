#include<cstdio>
#include<cstdlib>
#include<ctime>
char out[20],in[20];
char cmd[100];

void getans(){
	int i,j,k;int I;int n;
	srand(time(0));
	for(I=0;I<20;I++){
		sprintf(in,"tree%d.in",I);
		sprintf(out,"tree%d.out",I);
		sprintf(cmd,"std.exe > %s < %s",out,in);
		system(cmd);
	}
}
void make(){
	int i,j,k;int I;int n;
	srand(time(0));
	for(I=0;I<20;I++){
		sprintf(out,"tree%d.in",I);
		freopen(out,"w",stdout);
		if(I<5)n=5;
		else if(I<10)n=800;
		else n=3000;
		printf("%d\n",n);
		for(i=0;i<n;i++){
			if(I<2){
				printf("%d ",rand()%10);
			}else if(I%5==0){
				printf("%d ",100-rand()%20);
			}else{
				printf("%d ",rand()%101);
			}
		}
		fclose(stdout);
	}
}

int main(){
	make();
	getans();
}
