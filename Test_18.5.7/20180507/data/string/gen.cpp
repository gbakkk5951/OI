#include<cstdio>
#include<cstdlib>
int main(){
	int case_num=25;
	for(int i=1;i<=case_num;i++){
		char fn[100];
		sprintf(fn,"./std<%d.in>%d.ans",i,i);
		system(fn);
	}
}
