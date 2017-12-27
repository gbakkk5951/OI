#include<cstdio>
#include<cstring>
struct begin{
	int T,l;
	int ans;
	char s[500010],t[500010];
	int ex1[500010],ex2[500010];
	int psum[500010];
	char val[26];
begin(){
	freopen("data.in","r",stdin);
	freopen("my.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		ans=-2147483648;
		scan();
		ini();
		ekmp(s,t,ex1);//Ç°×º 
		ekmp(t,s,ex2);//ºó×º 
		getpsum();
		calc();
		printf("%d\n",ans);
	}
}
int nt[500010];
void ekmp(char *a,char *b,int *ex){
	int i,j,k;
	int mx=0;
	int po=0;
	nt[0]=l;
	j=0;
	int tp;
	for(i=1;i<l;i++){
		tp=i+nt[i-po];
		if(tp<mx){
			nt[i]=nt[i-po];
		}else{
			j=(mx-i);
			if(j<0)
			j++;
			for(;i+j<l;j++){
				if(a[j]!=a[i+j])
					break;
			}
			nt[i]=j;
			po=i;
			if(nt[i])
			mx=i+nt[i]-1;
			else
			mx=i;
		}
	}
for(i=0;i<l;i++){
	if(a[i]!=b[i])
	break;
}
po=0;
if(i)
mx=i-1;
else mx=0;
ex[0]=i;
for(i=1;i<l;i++){
	tp=i+nt[i-po];
	if(tp<mx){
		nt[i]=nt[i-po];
	}else{
		j=(mx-i);
		if(j<0)
		j++;
		for(;i+j<l;j++){
			if(a[j]!=b[i+j])
				break;
		}
		ex[i]=j;
		po=i;
		if(ex[i])
		mx=i+ex[i]-1;
		else
		mx=i;
	}
}
}
void calc(){
	int i=0;
	int temp;
	for(i=1;i<l;i++){
	//	printf("ex1[%d]=%d ex2[%d]=%d ",i,ex1[i],i,ex2[i]);
		temp=0;
		if(ex1[l-i]+l-i==l){
			temp+=psum[i-1];
	//		printf("1i=%d temp=%d ",i,temp);
		}               
		if(ex2[i]+i==l){
			temp+=psum[l-1]-psum[i-1];
	//		printf("2i=%d temp=%d ;",i,temp);
		}
		if(temp>ans){
			ans=temp;
		}
	}
	
	
}

void scan(){
	int i;
	for(i=0;i<26;i++){
	scanf("%d",val+i);
	}
	scanf("%s",s);
}
void ini(){
	int i;
	l=strlen(s);
	for(i=0;i<l;i++){
		t[i]=s[l-i-1];
	}t[l]='\0';
}
void getpsum(){
	psum[0]=val[s[0]-'a'];
	int i;
	for(i=1;i<l;i++){
		psum[i]=psum[i-1]+val[s[i]-'a'];
	}
}
	
	
	
	
	
	
	
	
	
}instance;int main(){}
