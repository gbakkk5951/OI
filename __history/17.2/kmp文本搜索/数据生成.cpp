#include<cstdio>
int main(){
	char ot[20];
	printf("out:");
	scanf("%s",ot);
	FILE *fa=fopen(ot,"w");
	char in1[1000];
	int nu;
	printf("nu:");
	while(~scanf("%d",&nu)){
	if(nu==-1)
	{fclose(fa);return 0;
	}
	printf("string:");
	int i;
	scanf("%s",in1);
	for(i=0;i<nu;i++){
		fprintf(fa,"%s",in1);
	}
	
	
		
		printf("finish\n");
		printf("nu:");
	}
	fclose(fa);
}
