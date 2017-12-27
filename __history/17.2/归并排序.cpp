#include<cstdio>


int n;
int d[100001];
int main(){
void merge_sort(int *left,int length);
void merge(int *A,int la,int *B,int lb);
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
{scanf("%d",d+i);
}

int test[]={15,16,17,18};



merge_sort(d,n);

for(i=0;i<n;i++)
printf("%d ",d[i]);
}

void merge(int *A,int la,int *B,int lb)
{
//printf("merge(%d,%d)",la,lb);
	int T[lb+la];
	int a=0,b=0;
	int pos=0;
	while(a<la&&b<lb)
	{
//		printf("{a=%d,b=%d}",*(A+a),*(B+b));
		if(*(A+a)<=*(B+b))
		{T[pos++]=*(A+a++);
		}else T[pos++]=*(B+b++);
		
	}
	if(a<la)
	for(;pos<la+lb;pos++)
	{T[pos]=*(A+a++);
	}
	else for(;pos<la+lb;pos++)
	{T[pos]=*(B+b++);
	}
	for(pos=0;pos<la+lb;pos++)
	{*(A+pos)=T[pos];
//	printf("{%d}",T[pos]);
	}
}

void merge_sort(int *left,int length)
{
//	printf("_+%d_",*left);
//	int *mid=left+(int)(length/2);
	int temp;
	if(length==2)
	{
//	printf("[%d,%d]",*(left),*(left+1));
	if(*(left)>*(left+1))
	{temp=*(left+1);
	*(left+1)=*left;
	*left=temp;
	}
		
	}else
	{
	//	printf("{left=%d,mid=%d,length=%d}",left,mid,length);
	if((int)(length/2)!=0)
	{
//	printf("{%d,%d}",left,mid);
	merge_sort(left,(length/2));
	}if((length-(int)(length/2))!=1)
	{

	merge_sort(left+(int)(length/2),length-(int)(length/2));
	}
    }
	merge(left,length/2,left+(int)(length/2),length-(int)(length/2));
		
	
	
}
