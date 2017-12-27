int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<cstring>
#include<bitset>

struct _Main{
int inline getbit (int data,int pos){
	return (data & 3<<(pos<<1))>>(pos<<1);
}
void inline writebit(int &data,int pos,int val){
//	printf("wb(%d,%d)",pos,val);
	data&=~(3<<(pos<<1));
	data|=(val<<(pos<<1));
}
int inline abs(int a){
	return a>>31^((a>>31)+a);
}
int inline max(int a,int b){
	return (a+b+abs(a-b))>>1;
}
int inline min(int a,int b){
	return (a+b-abs(a-b))>>1;
}
char map[100][5];
int dp[2][2170];
int  que[2][2171];
bitset<2050>in[2];
int front[2];
int n;
void inline insert(int kt,int num,int iter){
//	printf("kt=%d\n",kt);
//	printf("insert(%d,%d,%d)\n",kt,num,iter);
	if(!in[iter][kt]){
//		printf("!in[%d][%d]",iter,kt);
		in[iter][kt]=1;
		dp[iter][kt]=num;
//		printf("give dp[%d][%d] %d\n",iter,kt,num);
		que[iter][front[iter]++]=kt;
	}else{
//		printf("min(%d,%d)=",dp[iter][kt],num);
		dp[iter][kt]=min(dp[iter][kt],num);
//		printf("%d\n",dp[iter][kt]);
	}
	
}
void updata(int &a,char pos){
	int i,j,k;
	k=getbit(a,pos);
	bool flag;
	j=pos+10;//+10;
	if(getbit(a,pos)){
		j=min(pos+1,getbit(a,pos));
	}
	for(i=pos-1;i>=0;i--){
		if(getbit(a,i)){
			j=min(j,getbit(a,i));	
		}else{
			break;
		}
	}
	int g=i;
	for(i=pos-1;i>g;i--){
		if(getbit(a,i)!=j && getbit(a,i)){
			//for(k=0;k<5;k++){
		//		if(getbit(a,k)==getbit(a,i)){
			writebit(a,i,j);
//					printf("set %d %d\n",k,j);
		//		}
		//	}
		}
	}
	if(k){
	
		for(i=pos+1;i<5;i++){
			if(getbit(a,i)==k){
				writebit(a,i,j);
			}
		}
	}
	if(j==pos+10){
		j=1;
		for(i=0;i<pos;i++){
			if(getbit(a,i)==j){
				j++;
			}
		}
//		k=j+1;
		for(i=pos+1;i<5;i++){
			if(getbit(a,i)==j){
				writebit(a,i,j+1);
				for(k=i+1;k<5;k++){
					if(getbit(a,k)==j+1){
						writebit(a,k,j+2);
					}
				}
			}
		}
	}
	
	
	writebit(a,pos,j);
	
	/*char t = num;
	if( a & 3 << pos*2){
		t=min( num , a&3<< pos*2);
	}
	if( pos ){
		if(a & 3 << (pos-1)*2 ){
			t = min( t, updata(a,pos-1,t) );
		}
	}
	t=min( t ,a & 3 << pos*2);
	a &=  ~ (3 << (pos)*2 );
	a |= t;
	return  (a & 3 << (pos)*2)>> pos*2;*/
}

_Main(){
	bool flag;
	int i,j,k,s,iter;
	int kt;
	kt=0;
	/*
	while(1){
		scanf("%d%d",&i,&j);
	//	scanf("%d",&j);
	//	printf("i=%d ",i);
		writebit(kt,i,j);
	//	printf("%d\n",k);
		for(s=0;s<5;s++){
			printf("%d",getbit(kt,s));
		}
		putchar(' ');
		printf("%d",kt);
		printf("\n");
	}
	*/
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			while(!isdigit(map[i][j]=getchar()));
			map[i][j]-='0';
		}
	}
	
	for(i=n-1;i>=0;i--){
		k=0;
		for(j=0;j<5;j++){
			k|=map[i][j];
		}
		if(k==0){
			n--;
		}else{
			break;
		}
	}/*
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			printf("%d",map[i][j]);
		}
		printf("\n");
	}*/
	iter=0;
	dp[iter][0]=0;
	que[iter][front[iter]++]=0;
	flag=false;
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			if(map[i][j]){
				flag=true;
				break;
			}
		}
		if(flag){
			break;
		}
	}
	int t1,t2;
	for(/*i=0*/;i<n;i++){
		for(j=0;j<5;j++){
	/*		printf("[%d,%d]n=%d\n",i,j,n);
			for(k=0;k<front[iter];k++){
				for(s=0;s<5;s++){
					printf("%d",getbit(que[iter][k],s));
				}
				printf(": %d \n",dp[iter][que[iter][k]]);
			//	printf("que[%d][%d]=%d",iter,k,que[iter][k]);
			//	printf("\n");
			}
	*/		iter^=1;
			memset(dp[iter],127,8196);
		    memset(que[iter],0,front[iter]<<2);
			in[iter].reset();
			front[iter]=0;
			for(k=0;k<front[iter^1];k++){
				
				s=que[iter^1][k];
//				printf("s=que[%d][%d]=%d\n",iter^1,k,s);
				if(map[i][j]){
//					printf("a1");
					kt=s;
					updata(kt,j);
					insert(kt,dp[iter^1][s],iter);
//					printf("insert(%d,%d,%d)\n",kt,dp[iter^1][s],iter);
					
				}else{
//					printf("b1");
					kt=s;
					updata(kt,j);
					insert(kt,dp[iter^1][s]+1,iter);
					t1=44;
					if(getbit(s,j)){
						flag=false;
						for(kt=0;kt<5;kt++){
							if(kt!=j && getbit(s,kt) == getbit(s,j) /* s & 3<<kt*2 ==s & 3 << j*2*/ ){
								flag=true;
								t1=min(t1,kt);
							}
						}
					}else{
						flag=true;
					}
					if(flag){
//						printf("b2");
						kt=s;
						/*if(t1>j){
							for(t1++;t1<5;t1++){
								if(getbit(kt,t1)==getbit(kt,j)){
									write
								}
							}
						}*/
						
						/*for(t2=max(t1,j+1);t2<5;t2++){
							if(getbit(kt,t2)==getbit(s,))
						}*/
						
						
						writebit(kt,j,0);
						
						
						insert(kt,dp[iter^1][s],iter);
					}
				}
			}

		}
	}
/*	printf("//////////////////");
	for(k=0;k<front[iter];k++){
		for(s=0;s<5;s++){
			printf("%d",getbit(que[iter][k],s));
		}
		printf(":%d\n",dp[iter][que[iter][k]]);
	//	printf("que[%d][%d]=%d",iter,k,que[iter][k]);
	//	printf("\n");
	}	
*/	
//	iter^=1;
	int ans=3000;
	for(i=0;i<front[iter];i++){
		s=que[iter][i];
		flag=true;
		k=0 ;
		/*for ( j = 0 ; j < 5 ;j ++){
			if(!k && s & 3<<j ){
				k=s & 3<<j;
			}else if( k && s & 3 << j ){
				if(k!=s&3<<j){
					flag=false;
				}
			}
		}*/
		
		for(j=0 ;j< 5 ;j++){
			if( k==0 && getbit(s,j)){
				k=getbit(s,j);
			}else if(k!=0 && getbit(s,j)){
				if(k!=getbit(s,j)){
					flag=false;
				}
			}
		}
		if(flag){
	/*		printf("fresh with");
			for(j=0;j<5;j++){
				printf("%d",getbit(s,j));
			}printf("\n");
	*/		
			ans=min(ans,dp[iter][s]);
		}
	}
	printf("%d",ans);
	
}	
	
	
	
	
	
	
	
	
	
	
	
}cdvs1050;
