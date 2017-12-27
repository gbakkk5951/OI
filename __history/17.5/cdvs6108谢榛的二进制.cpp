#include<cstdio>
struct _Main{
char in[100010];	
_Main(){
	char t;
	fgets(in,100005,stdin);
	t=in[0];
	int i;
	for(i=1;in[i];i++){
		if(in[i]=='0'){
			putchar(t);
			puts(in+i+1);
			return;
		}else if(in[i]=='1') {
			putchar(t);
			t=in[i];
		}
	}
}	
}cdvs6108;int main(){}
