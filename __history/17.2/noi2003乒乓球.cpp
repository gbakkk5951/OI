#include<cstdio>
int w1[100000],l1[100000];
int w2[100000],l2[100000];
int abs(int a,int b){
	return a>b?a-b:b-a;
}
int main(){
	char t;

	int i1=0,i2=0;
	int i=0;
	while((t=getchar())!='E'){
		if(t=='L'){
			l1[i1]++;
			l2[i2]++;
		}else{
			if(t=='W'){
				w1[i1]++;
				w2[i2]++;
			}
		}
		if((w1[i1]>=11||l1[i1]>=11)&&abs(w1[i1],l1[i1])>=2){
			i1++;
		}
		if((w2[i2]>=21||l2[i2]>=21)&&abs(w2[i2],l2[i2])>=2){
			i2++;
		}
	}
	for(i=0;i<=i1;i++){
		printf("%d:%d\n",w1[i],l1[i]);
	}puts("");
	for(i=0;i<=i2;i++){
		printf("%d:%d\n",w2[i],l2[i]);
	}
}
