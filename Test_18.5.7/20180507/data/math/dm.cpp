#include<cstdio>
#include<cstdlib>
#include<set>
#include<algorithm>
int a[2010];
void makecase(int id){
	int ns[11]={0,10,15,20,75,100,250,500,1000,1500,2000},
		as[11]={0,20,20,20,75,100,500,500,2000,2000,2000},
		n=ns[id],A=as[id];
	printf("%d\n",n);
	if(id<=5)for(int i=0;i<n;i++)a[i]=rand()%A+1;
	else{
		int s=0;
		if(id==7||id==9||id==10){
			for(int i=100+rand()%10;i--;)a[s++]=1;
		}
		else a[s++]=1;
		std::set<int>st;
		while(s<n){
			int x=2+rand()%(A-1);
			if(st.find(x)==st.end())st.insert(x),a[s++]=x;
		}
		if(id==7||id==9||id==10)for(int i=0;i<100;i++)a[n-100+i]=a[n-200+rand()%(100+i)];
		std::random_shuffle(a,a+n);
	}
	for(int i=0;i<n;i++)printf("%d%c",a[i]," \n"[i==n-1]);
}
int main(){
	srand(163432743);
	int case_num=10;
	for(int i=1;i<=case_num;i++){
		char fn[100];
		sprintf(fn,"%d.in",i);
		freopen(fn,"w",stdout);
		makecase(i);
	}
}
