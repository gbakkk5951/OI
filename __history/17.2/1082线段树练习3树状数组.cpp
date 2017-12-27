#include<cstdio>
#define lw(x) x&(-x) 
int n,q;
long long delta[200010],deltai[200010],sum[200010];
void updata(long long *det,int pos,int x){
	for(;pos<=n;)
	{
	///	printf("pos=%d;",pos);
		det[pos]+=x;
		pos+=lw(pos);
	}
	
}

long long query(long long *det,int pos){
	long long v=0;
	for(;pos;){
		v+=det[pos];
		pos-=lw(pos);
	}
	return v;
}

int main(){
	int i,k;
	long long j;
	int in1,in2,in3;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&in1);
		sum[i]=sum[i-1]+in1;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%lld",&j);
		if(!(j^1)){
			scanf("%d%d%d",&in1,&in2,&in3);
			updata(delta,in1,in3);
			updata(delta,in2+1,-in3);
			updata(deltai,in1,in1*in3);
			updata(deltai,in2+1,-(in2+1)*in3);
			
		}else{
			scanf("%d%d",&in1,&in2);
			j=sum[in1-1]+in1*query(delta,in1-1)-query(deltai,in1-1);
			j=sum[in2]+(in2+1)*query(delta,in2)-query(deltai,in2)-j;
			printf("%lld\n",j);
		}
		
		
		
		
	}
	
	
}
