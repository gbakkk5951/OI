int main(){}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;


const int list[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
struct big{
	
	long long num[80];
	int lenth;
	big (){
		lenth=0;
		memset(num,0,sizeof(num));
	}
	void operator = (big &b){
		memcpy(this,&b,sizeof(big));
	}
	big operator - (big &b){
		long long i;
		big temp;
		temp=*this;
		for(i=0;i<b.lenth;i++){
			temp.num[i]-=b.num[i];
		}
		for(i=0;i<temp.lenth ;i++){
			if(temp.num[i]>>63){
				temp.num[i]+=list[8];
				temp.num[i+1]-=1;
			}
		}
		return temp;
		
	}
	
	void operator = (char *b){
		short i=0,j,la;
		while(b[i]){
			i++;
		}
		la=i;
		lenth=ceil(i/8.0f);
		for(i=0;i<lenth;i++){
			for(j=0;j<8&&(i*8+j!=la);j++){
				num[i]+=(b[la-i*8-j-1]-'0')*list[j];
			}
		}
	}
	
	long long operator [](unsigned int a){
		return num[a];
	}

	void operator = (const big &b){
		memcpy(this,&b,sizeof(big));
	}
	void operator = (long long b){
		lenth=1;
		memset(num,0,sizeof(num));
		num[0]=b;
	}
	void operator = (int b){
		lenth=1;
		memset(num,0,sizeof(num));
		num[0]=b;
	}	 
	big operator * (const big &b){
		long long i,j;
		big temp;
		temp.lenth =lenth+b.lenth;
		for(i=0;i<lenth;i++){
			for(j=0;j<b.lenth;j++){
				temp.num[i+j]+=num[i]*b.num[j];
			}
		}
		for(i=0;i<=temp.lenth;i++){
			if(j=temp.num[i]/list[8]){
				temp.num[i]-=j*list[8];
				temp.num[i+1]+=j;
			}
		}
		for(i=temp.lenth;i;i--){
			if(temp.num[i]){
				break;
			}
		}
		temp.lenth = i + 1;
		return temp;
	}
	big operator * (long long b){
		big temp;
		temp=b;
		temp*=*this;
		return temp;
	}
	void operator *= (const big &b){
		*this=*this*b;
	}
	
	void print(){
		int i;
		printf("%d",num[lenth-1]);
		for(i=lenth-2;i>=0;i--){
			printf("%08d",num[i]);
		}
	}
	bool operator < (const big &b){
		int i;
		if(lenth<b.lenth ){
			return true;
		}else if(lenth>b.lenth ){
			return false;
		}else{
			for(i=lenth-1;i>=0;i--){
				if(num[i]<b.num[i]){
					return true;
				}else if(num[i]>b.num[i]){
					return false;
				}
			}
			return false;
		}
	}
	bool operator > (big &b){
		return b<(*this);
	}
	big operator + (int b){
		big temp;
		temp=b;
		return (*this)+temp;
	}
	bool operator <=(big &b){
		return *this<b||*this==b;
	}
	bool operator == (big &b){
		if(lenth==b.lenth ){
			int i;
			for(i=0;i<lenth;i++){
				if(num[i]!=b[i]){
					return false;
				}
			}
			return true;
		}
		return false;
	}
	big operator - (int b){
		big temp;
		temp=b;
		return *this-temp;
	}
	big operator + (big &b){
		int i;
		big temp;
		long long j;
		int l=min(lenth,b.lenth);
		if(l<lenth){
			temp=*this;
			for(i=0;i<l;i++){
				temp.num[i]+=b[i];
				j=temp[i]/list[8];
				temp.num[i]-=j*list[8];
				temp.num[i+1]+=j;
			}
			
		}else{
			temp=b;
			for(i=0;i<l;i++){
				temp.num[i]+=num[i];
				j=temp[i]/list[8];
				temp.num[i]-=j*list[8];
				temp.num[i+1]+=j;
			}			
		}
		
		for(i=temp.lenth ;i>0;i--){
			if(temp.num[i]){
				break;
			}
		}
		temp.lenth =i+1;
		return temp;
	}


};

struct _Main{
	
int testlegal(){
	minus=0;
	int ret=0,iter=0;
	temp[iter]=(use+ret+4)*(ret+4);
	if(temp[iter]<rem){
		ret+=4;
		minus=&temp[iter];
		iter^=1;
	}else if((temp[iter] == rem)){
		minus=&temp[iter];
		return 4;
	}
	temp[iter]=(use+ret+2)*(ret+2);
	if(temp[iter]<rem){
		ret+=2;
		minus=&temp[iter];
		iter^=1;
		temp[iter]=(use+ret+2)*(ret+2);
		if(temp[iter]<rem){
			minus=&temp[iter];
			iter^=1;
			ret+=2;
		}else if(temp[iter]==rem){
			minus=&temp[iter];
			return ret+2;
		}
	}else if(temp[iter]==rem){
		minus=&temp[iter];
		return ret+2;
	}
	temp[iter]=(use+ret+1)*(ret+1);
	if(temp[iter]<rem ||temp[iter]==rem){
		minus=&temp[iter];
		return ret+1;
	}
	return ret;
}	

char a[1007],ans[600];
int atot;
big rem,use,temp[2],*minus;
_Main(){

	int l,i;
	scanf("%s",a);
	l=strlen(a);
	if(l&1){
		rem=(a[0]-'0');
		ans[atot]=sqrt(a[0]-'0');
		putchar(ans[atot]+'0');
		use=ans[atot++]*20;
		i=1;
	}else{
		rem=(a[0]-'0')*10+a[1]-'0';
		ans[atot]=sqrt((a[0]-'0')*10+a[1]-'0');
		putchar(ans[atot]+'0');
		use=ans[atot++]*20;
		i=2;
	}
	rem=rem-(ans[atot-1]*ans[atot-1]);
	while(i<l){
		rem=rem*100;
		rem=rem+((a[i]-'0')*10+a[i+1]-'0');
		ans[atot]=testlegal();
		putchar(ans[atot]+'0');
		use=(use+(ans[atot++]*2))*10;

		if(minus){
			rem=rem-(*minus);
		}
		i+=2;
	}

	
	
}	
}cdvs3119;
