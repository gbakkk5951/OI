using namespace std;
int main(){}
#include<cstdio>


struct _Main{

	_Main(){
		int n,i;
		scanf("%d",&n);
		if(n>=4){
			if(n&1){
				printf("16400");
				for(i=1;i<=n-5;i++){
					putchar('0');
				}				
			}else{
				printf("1144");
				for(i=1;i<=n-4;i++){
					putchar('0');
				}
			}

		}else{
			printf("-1");
		}
		
	}
	
}doublediv;

/*
1144
2288
2392
16400
#include<cmath>
const double eps=1e-4;

struct _Main{
long long inline pf(long long a){
	return a*a;
}
long long pow[20];

_Main(){
	long long i,j;
	long long cnt=0,b;
	long long s1,s2,b2;
	pow[0]=1;
	for(i=1;i<20;i++){
		pow[i]=pow[i-1]*10;
	}
	for(i=100;i<=3e4;i++){
		cnt=0;
		for(j=1;pow[j]<i;j++){
			s1=i/pow[j];s2=i%pow[j];

			if(s2%s1==0 && s2>=pow[j-1]){
				b2=s2/s1;				
				
				if(b2!=0 && pf((long long)floor(sqrt(b2)+eps))==b2){
//					printf("s1=%lld s2=%lld b2=%lld\n",s1,s2,b2);
					cnt++;
				}
			}
		}
		if(cnt>1){
			printf("%lld\n",i);
		}
	}

}


}doublediv;

*/


//b2 / sq(b2) == sq(b2) ������==b2
//�����У���Ҫpf(sq(b2))==b2 

//С��ǰ����
//������������ȱ��Ѵ��������չ 
//ÿһ����Ӧ������˼���ǵĶ����Ǽ������ 
