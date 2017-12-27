#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
char in[1000010]
, ib[1000010];
int it[1000010];
int read(){
	char f=1,t;
	int ans=0;
	while((t=getchar())<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
	}
	do{
		ans*=10;
		ans+=t-'0';
	}while((t=getchar())>='0'&&t<='9');
	return ans;
}
int main(){
	float a,b,c,d;
	int i,j,k;
	i=1000000;
	freopen("int.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	a=clock();
	while(i--){
		it[i]=read();
		printf("%d ",it[i]);
	}
	b=clock();
	printf("%f\n",b-a);	 
/*	a=clock();
	std::ios::sync_with_stdio(false);
	freopen("te.txt","r",stdin);
	cin>>ib;
	fclose(stdin);
	b=clock();
	printf("%f\n",b-a);
	freopen("ta.txt","r",stdin);
	//scanf("%s",in);
	int i=0;
	while(~(in[i++]=getchar()));
	in[i-1]=0;

	

	c=clock();
	printf("%f\n",c-b);
	puts(ib);
	FILE *fa=fopen("ta.txt","r");
	fscanf(fa,"%s",in);
	d=clock();
	printf("%f\n",d-c);*/
}
