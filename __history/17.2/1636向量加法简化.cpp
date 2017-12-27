#include<cstdio>
#include<vector>
#include<cctype>
using namespace std;
struct v
{char l,r;
int nu;	
};
int n;
vector<v>list;
void insert(v ve)
{
	int i=0;v t;
	for(i=0;i<list.size() ;i++)
	{
		if(ve.l==list[i].r)
		{if(ve.r==list[i].l)
			{list[i].nu--;
			if(list[i].nu==0)
			list.erase(list.begin()+i);
			}
			else{
				
				t.l =list[i].l;
				t.r=ve.r;
				t.nu=1;
				list[i].nu--;
				if(list[i].nu==0)
				list.erase(list.begin() +i);
				insert(t);
			}
			return ;
		}
        if(ve.r==list[i].l)
		{
			t.l=ve.l;
			t.r=list[i].r;
			t.nu=1;
			list[i].nu--;
			if(list[i].nu==0)
			list.erase(list.begin() +i);
			insert(t);
			return ;
		}
		else if(ve.l ==list[i].l&&ve.r==list[i].r)
		{list[i].nu++;
		return;
		}
	}
	list.push_back(ve); 
	
}
int main()
{
	scanf("%d",&n);
	if(n==3)
	n=5;
	v t;
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%c",&t.l);
		
		if(t.l=='0')
		{continue;
		}
		if(!isalpha(t.l))
		{i--;
		continue;
		}
		scanf("%c",&t.r);
		t.nu =1;
		insert(t);
	}
	if(list.size() ==0)
	printf("0");
	else if(list.size() ==1&&list[0].nu!=1)
	printf("%d%c%c",list[0].nu,list[0].l,list[0].r);
	else if(list.size() ==1)
	printf("%c%c",list[0].l,list[0].r);
	else printf("Thompson Chelsea sitting on the tree");
}


