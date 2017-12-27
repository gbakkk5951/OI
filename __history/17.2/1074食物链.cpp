#include<cstdio>
int lie;
int n,q;
int fa[50010];
int rel[50010];
int find(int x)
{
	if(fa[x]==x)
	return x;
	int t=find(fa[x]);
	rel[x]=(rel[x]+rel[fa[x]])%3;
	fa[x]=t;
	return fa[x];
}


int main(){
	int i,j,k,l,d,x,y;
	
	
	int f1,f2;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	
	for(i=0;i<q;i++){
		scanf("%d%d%d",&j,&k,&l);
		if(l>n||k>n)
		{lie++;
		continue;
		}
		
		f1=find(k);
		f2=find(l);
	
		
		if(j==1){
			if(f1==f2){
				if(rel[k]!=rel[l]){
					lie++;
					continue;
				}
			}
			else{
				fa[f1]=f2;
				rel[f1]=(3-rel[k]+rel[l])%3;
			}			
		}else{
			if(f1==f2){
				
				switch(rel[k])
				{
					case 0:{
						if(rel[l]!=2){
							lie++;
						}
						break;
					}
					case 1:{
						if(rel[l]!=0)
						{
						
							lie++;}
						break;
					}
					case 2:{
						if(rel[l]!=1){
							lie++;
						}
						break;
					}
					
					
				}
			
				
			}else{
				fa[f1]=f2;
				rel[f1]=(4-rel[k]+rel[l])%3;
			}
			
			
		}
		
	}
	printf("%d",lie);
	
}
