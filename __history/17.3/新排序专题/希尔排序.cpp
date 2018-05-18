#include<cstdio>
#include<ctime>
struct begin{
int data[10010];
int step[1000];
begin(){
	freopen("Ëæ»úÊý.out","r",stdin);
	freopen("Ï£¶ûÅÅÐò.txt","w",stdout);
	readin();
	initialize();
	shell_sort();
	print();

}

void ex(int &a,int &b){
	int tm=a;
	a=b;
	b=tm;
}

int n;
int k=0;
void initialize(){
	int po4[500];
	int po2[500];
	int i=1,j=2;
	int t1=0,t2=0;
	po2[0]=1;
	po4[0]=1;
	t1=19;
	t2=5;
	step[k++]=1;
	if(!po4[i])
		po4[i]=po4[i-1]*4;
		if(!po2[i])
		po2[i]=po2[i-1]*2;
		if(!po4[j])
		po4[j]=po4[j-1]*4;
		if(!po2[j])
		po2[j]=po2[j-1]*2;
	while(t1<=n||t2<=n)
	{	
		
		t2=po4[j]-3*po2[j]+1;
		
		if(t1<t2)
		{step[k++]=t1;
//		printf("%d ",step[k-1]);
		i++;
		po4[i]=po4[i-1]*4;
		if(!po2[i])
		po2[i]=po2[i-1]*2;
		t1=9*po4[i]-9*po2[i]+1;
		}else{
			step[k++]=t2;
			j++;
	//		printf("%d ",step[k-1]);
			if(!po4[j])
			po4[j]=po4[j-1]*4;
			if(!po2[j])
			po2[j]=po2[j-1]*2;
		
			t2=po4[j]-3*po2[j]+1;
		}
		
	}
}


void readin(){
	while(~scanf("%d",&data[n+1]))
	n++;
}
int ef(int base,int len,int val,int tmr,int tml=0){
	int i=base;
/*	for(;i<=base+tmr*len;i+=len){
		if(data[i]>val)
		return i;
		
	}
*/	
	if(!(tml^tmr)){
		return base+len*tml;
	}
	int mid=(tml+tmr)>>1;
	if(data[base+mid*len]<val){
		return ef(base,len,val,tmr,mid+1);
	}else{
		return ef(base,len,val,mid,tml);
	}
}

void shell_sort(){
	k--;
	int i,j,d;
	int t,te;
	while(k>=0){
	d=n%step[k]+1;
	for(i=1;i<=d+1;i++)
		for(j=i;j<=n;j+=step[k]){
			if(data[j]<data[j-step[k]]){
				t=ef(i,step[k],data[j],(j-i)/step[k]);
				te=data[j];
				while(t<=j){
					ex(te,data[t]);
					t+=step[k];
				}
			}

		}
	k--;
	}
	
	
	
}

void print(){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",data[i]);
	}
	
}

}instance;int main(){}

