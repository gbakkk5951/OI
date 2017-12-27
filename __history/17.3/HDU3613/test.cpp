#include<cstring>
#include<cstdio>
struct begin{
int val[26];
int ans;
int psum[500010];
char na[500020],nb[500020];
int ea[500010],eb[500010];
int ab[500010],ba[500010];
int ol;
int al;
int max(int a,int b){
	return a>b?a:b;
}
begin(){
	freopen("data.in","r",stdin);
	freopen("my.out","w",stdout);
	int tn,i,j;
	scanf("%d",&tn);
	for(i=0;i<tn;i++){
		for(j=0;j<26;j++){
			scanf("%d",&val[j]);
		}
		scanf("%s",na);
		ol=strlen(na);
		al=ol;
		calc();

		printf("%d\n",ans);
		ans=0;
	}
}
void calc(){
	int i,j,l,k;
	
	getsum();
	ini();
	ea[0]=al;
	j=0;
	int po=0,mx=0;
	int temp;
	for(i=1;i<al;i++){
		temp=i-po+ea[i-po]-1;
		if(temp<mx-po){
			ea[i]=ea[i-po];
		}else{
			j=mx-i;
			if(j<0)
			j++;
			for(;i+j<al;j++){
				if(na[j]!=na[i+j]){
					break;
				}
			}

			ea[i]=j;
			po=i;
			if(j)
			mx=i+j-1;
			else
			mx=i;
		}
		
	}
	po=0,mx=0;
	eb[0]=al;
	for(i=1;i<al;i++){
		temp=i-po+eb[i-po]-1;
		if(temp<mx-po){
			eb[i]=eb[i-po];
		}else{
			j=mx-i;
			if(j<0)
			j++;
			for(;i+j<al;j++){
				if(nb[j]!=nb[i+j]){
					break;
				}
			}
			
		eb[i]=j;
			po=i;
			if(j)
			mx=i+j-1;
			else
			mx=i;
		}
		
	}
	for(i=0;i<al;i++){if(na[i]!=nb[i])break;
	}
	//printf("mx=%d ",i);
	ba[0]=i;
	mx=i;
	po=0;
	
	for(i=1;i<al;i++){
		temp=i-po+eb[i-po]-1;
		if(temp<mx-po){
			
			
		//	printf("[%d]=%d ",i,temp);
			ba[i]=eb[i-po];
		}else{
			j=mx-i;
			if(j<0)
			j++;
			for(;i+j<al;j++){
				if( nb[j]!=na[i+j]){
					break;
				}
			}
			
		
			ba[i]=j;
		
			po=i;
			if(j)
			mx=i+j-1;
			else
			mx=i;
		}
		
	}	
	

	ab[0]=ba[0];
	mx=ab[0];
	po=0;
	
		for(i=1;i<al;i++){
		temp=i-po+ea[i-po]-1;
		if(temp<mx-po){
/*			if(ba[i]==2)
			{
				printf(" j=%di=%d ",j,i);
			}
*/			ab[i]=ea[i-po];
		}else{
			j=mx-i;
			if(j<0)
			j++;
			for(;i+j<al;j++){
				if( na[j]!=nb[i+j]){
					break;
				}
			}
	
			ab[i]=j;
	
			po=i;
			if(j)
			mx=i+j-1;
			else
			mx=i;
		}
		
	}
/*	
	for(i=0;i<al;i++){
		printf("ba[%d]=%d ",i,ba[i]);
	}
	for(i=0;i<al;i++){
		printf("ab[%d]=%d ",i,ab[i]);
	}
*/
//ab[i]
//error
for(i=0;i<ol;i++){
	j=0;
//	printf("ba%d \n",ba[i]);
	if(i+ab[i]==ol)
	j=psum[ab[i]-1];
	if(ba[ab[i]]!=ol)
	if(ba[ab[i]]==ol-ab[i]/*&&ol-ab[i]>1*/)
	j+=psum[ol-1]-psum[ab[i]-1];
	if(j>ans)
	ans=j;
}

for(i=0;i<ol;i++){
	j=0;
//	printf("ab%d \n",ab[i]);
	if(i+ba[i]==ol)
	j=psum[ol-1]-psum[ol-ba[i]];
	if(ab[ba[i]]!=ol)
	if(ab[ba[i]]==ol-ba[i]/*&&ol-ab[i]>1*/)
	j+=psum[ol-ba[i]];
	if(j>ans)
	ans=j;
}
	
}
void ini(){
	int i=0;
	int l=ol;
	for(i=0;i<l;i++){
		nb[i]=na[l-i-1];
	}
//	nb[l]=0;printf ("[%s]",nb);
}


void getsum()
{
psum[0]=val[na[0]-'a'];
int i,j,k,l;
for(i=1;i<ol;i++){
	psum[i]=psum[i-1]+val[na[i]-'a'];
}


}
	
}instance;int main(){}
