#include<cstdio>
#include<cstdlib>
#include<ctime>
char a[100010];
char b[100010];
char sum[100010];
char FileNameIn[50],FileNameOut[50];
int main(){
	int i,j,k;int I;int mx;
	srand(time(0));	
	for(I=1;I<=10;I++){
		sprintf(FileNameIn,"high%d.in",I);
		sprintf(FileNameOut,"high%d.out",I);
		freopen(FileNameIn,"w",stdout);
		for(j=0;j<100000;j++){
			a[j]=rand()%10;
			b[j]=rand()%10;
		}
		for(i=99999;i>=0;i--){
			putchar(a[i]);
		}putchar('\n');
		for(i=99999;i>=0;i--){
			putchar(b[i]);
		}		
		fclose(stdout);
		for(i=0;i<100000;i++){
			sum[i]=a[i]+b[i];
			if(sum[i]>=10){
				sum[i]-=10;
				sum[i+1]+=10;
				mx=i+1;
			}else{
				mx=i;
			}
		}
		freopen(FileNameOut,"w",stdout);
		for(i=mx;i>=0;i--){
			putchar(sum[i]);
		}fclose(stdout);
		
	}
	
	
	
	
	
}
