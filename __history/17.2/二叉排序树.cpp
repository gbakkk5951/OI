#include<stdio.h>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
struct str_tree
{
	str_tree *lchild,*rchild;
	int key;
	
};
class tree
{

	public:
		bool search(int num);
	    void insert(int num)
	    {
	    	
	    pinsert(&aroot,num);
		}
	    void print()
	    {
	
	    pprint(&aroot);
		}
	    
	    tree()
	    {
	  
	    	 
		}
		~tree()
		{
			pdelete (aroot);

		}

	private:
	
		struct str_tree *aroot=NULL;
		struct str_tree temp;

	


void pinsert(str_tree **root,int num)
{
	if(*root==NULL)
	{
	
		*root=(str_tree *)malloc(sizeof(str_tree));
		(*root)->key=num;
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;

	}
	else{
		if(num>=(*root)->key)
		pinsert(&(*root)->rchild,num);
		else
		pinsert(&(*root)->lchild,num);
	}
	
}

void pdelete (str_tree *obj)
{
	if(obj->lchild!=NULL)
	{
		pdelete(obj->lchild);
		
	}
	if(obj->rchild!=NULL)
	pdelete(obj->rchild);
	free(obj);
}
void pprint(str_tree **root)
{
	if((*root)->lchild!=NULL)
	pprint(&(*root)->lchild);
	printf("%d ",(*root)->key);
	if((*root)->rchild!=NULL)
	pprint(&(*root)->rchild);
	
}
	
};


int main()
{tree a;
int temp;
FILE *z,*b;
z=freopen("Ëæ»úÊý.out","r",stdin);
b=freopen("¶þ²æÊ÷ÅÅÐò.txt","w",stdout);
	while(~scanf("%d",&temp))
a.insert(temp);
	a.print();

fclose(z);
fclose(b);
freopen("CON","w",stdout);
	printf("%f",(float)clock()/CLOCKS_PER_SEC);
	
}
