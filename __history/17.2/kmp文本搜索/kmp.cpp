#include<cstdio>
#include<cstring>
#include<ctime>
char yxz[510];//��Ѱ�� 
char bxz[1000010];//��Ѱ�� 
int next[1000010];//ǰ2����.size�������ַ�ƥ��ʱ����ͷ�ж��٣�.size������һ�� 
int la,lb;
int cnt;
void getnext(){
	int k=0;
	int i,j,l;
	for(i=1;i<la;i++){
		while(k&&yxz[k]!=yxz[i])
		k=next[k];
		if(yxz[k]==yxz[i])
		k++;
		next[i+1]=k;
	}
}



int main(){
  //	freopen("super.in","r",stdin);
 	//freopen("super.ans","w",stdout);
	scanf("%s%s",yxz,bxz);
	la=strlen(yxz);
	lb=strlen(bxz);
	getnext();
		int i,po=0;
	int beg=-1;
	for(i=0;i<lb;i++)
	{
		while(bxz[i]!=yxz[po]&&po){
			po=next[po];	
		}
		if(bxz[i]==yxz[po])
		{
			po++;
		 }
		 if(po==la)
		 {

		cnt++;
		}
	}
	printf("%d",cnt);
//	printf("%f",(float)clock()/CLOCKS_PER_SEC);
 //	fclose(stdout);
} 


