#include<cstdio>
#include<cstring>
#include<cctype>
struct begin{
int alg;
int apo;	
int index[40001];
char nw[40001];	
char org[40020];	
int re[40001];
int nl;
begin(){
scan();
deal();
manacher();
print();
}
int min(int a,int b){
	return a<b?a:b;
}
int min(int a,int b,int c){
	return min(a,min(b,c));
}


void scan(){
 	char temp;
	int l,i,j=0,k;
	
	while(~(temp=getchar())){

		org[j]=temp;
		j++;
	}
//	printf("%s",org);	
}
void deal(){
	int i,j=1,k,l;
	l=strlen(org);
	nw[0]='#';

	for(i=0;i<l;i++){
		if(isalpha(org[i])){
			index[j]=i;
			index[j+1]=i;
			nw[j+1]='#';
			nw[j]=tolower(org[i]);
			j+=2;
		}
	}
	nw[j]=0;
//	printf("%s",nw);
	nl=j;
}
void manacher(){
	int bi=0,mx=1;
	int i,j,k;
	re[0]=1;
	for(i=1;i<nl;i++){
		j=0;
		if(i<mx){
			j=min(mx-i,re[bi-(i-bi)]);
		}
		if(i>=mx){
			j=1;
		}
		
		for(;i+j<nl;j++){
			if(nw[i+j]!=nw[i-j]||i+j>nl-1||i-j<0){
				break;
			}
		}
		re[i]=j;
		if(i+j>mx){
			mx=i+j;
			bi=i;
		}
		if(re[i]>alg){
			alg=re[i];
			apo=i;
		}	
	}	
}
void print(){
	int i=0;


			printf("%d\n",alg-1);
	for(i=index[apo-alg+2];i<=index[apo+alg-1];i++){
	putchar(org[i]);
	}

	
}
	
}instance;int main(){}
