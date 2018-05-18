#include<cstdio>
#define mod 1000000000
struct _Main{
_Main(){
	int i;
	scanf("%lld",&n);
	ini();
	printf("%d",newdfs(0,n));
}

inline long long lb(long long x){
	return x&(-x);
}

long long mem[67][65];//��2^iΪ��β����2^j������λ���ķ�������������� 
long long dp[67][66][67];//��2^iΪ��ͷ,2^kΪ��β,��Ϊ2^j�ķ����� 
int ini(){
	//��Сö�ٷ�Χ 
	long long maxbit=62;
	for(;!((1LL<<maxbit)&n);maxbit--);

	int i,j,k,l,m,r;
	dp[0][0][0]=1;
	for(j=1;j<=maxbit;j++){
		//��ʼֵ 
		dp[j][j][j]=1;
		for(i=0;i<j;i++){
			for(k=i;k<j;k++){
				//����
				for(l=i;l<=k;l++){
					for(m=l;m<=k;m++){	
						dp[i][j][k]+=dp[i][j-1][l]*dp[m][j-1][k];
						dp[i][j][k]%=mod;	
					}
				}
			}
		}
	}
}

int newdfs(long long last,long long rem){

	
	if(rem==0)return 1;
	long long i,j=0,k=0;
	long long ans=0;
	long long sum1=0,sum=0;
	long long i2=0;
	//�ҵ����λ 
	for(i=last;!((1LL<<i)&rem);i++);
	rem=rem-lb(rem);

	
	if(rem){//�ҳ�ɾ����λ֮��ʣ��λ�����λ ���ڼ��仯 
		for(i2=i+1;!((long long)(1LL<<i2)&lb(rem));i2++);
	}
	
	for(k=last;k<=i;k++){//ö�ٽ�β
	 
		//���仯���� ʣ��λ����Ϸ��� k��ʾ��kΪ��С��ͷ��i2��ʾʣ�����λΪ2^i2 
		if(!mem[k][i2]){
			ans=newdfs(k,rem);
			mem[k][i2]=ans+1;
		}else ans=mem[k][i2]-1;
		
		//��ǰλ����Ϸ���  ö�ٿ�ͷ 
		for(j=last;j<=k;j++){
			sum+=dp[j][i][k];
			sum%=mod;
		}
		//��������˼ӵ��ܺ��� 
		sum1=(sum1+ans*sum)%mod;
		sum=0;
	}

	return sum1;
	
}
long long n;
}ztime;int main(){}
