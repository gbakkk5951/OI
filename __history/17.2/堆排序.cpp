#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> heap;
	FILE *a,*b;
int main()
{
	void heap_sort();
	void heap_build();
	void heap_deal(int);
	heap.push_back(-1);
	a=freopen("CON","r",stdin);
	b=freopen("CON","w",stdout);

	int temp;
	while(fscanf(a,"%d",&temp)!=EOF)
	{heap.push_back(temp);
	}

	heap_build();
	heap_sort(); 
	fclose(a);
	fclose(b);
}


void heap_deal(int root)
{
	int kid=root*2;
	int temp;
	if(kid+1<heap.size()&&heap[kid]>heap[kid+1])
	{
		kid++;
	}
	if(heap[kid]<heap[root])
	{
		temp=heap[root];
		heap[root]=heap[kid];
		heap[kid]=temp;
		if(kid*2<heap.size())
		heap_deal(kid);
	}else return;
	
}


void heap_build()
{
	void heap_deal(int);
	for(int i=heap.size()/2;i>0;i--)
	{
		heap_deal(i);
	}
	
	
} 


void heap_sort()
{
	void heap_deal(int);
int temp;
int size=heap.size();
	for(int i=1;i<size;i++)
{
	fprintf(b,"%d ",heap[1]);
	heap[1]=heap[heap.size()-1];
	heap.pop_back();
	heap_deal(1);
	}	
}
