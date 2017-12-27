#include<stdio.h>

using namespace std;
int cube[38][38]={0};
	int N=0;
	int &n=N;
int main()
{
  FILE *in,*out;
  in=freopen("magic.in","r",stdin);

	
	for(int z=0;z<n;z++)
{
	for(int a=0;a<n;a++)
	cube[a][z]=0;
	
}
	scanf("%d",&N);
	cube[n/2][0]=1;
	void docube();
	docube();
	fclose(in);
	out=freopen("magic.out","w",stdout);
	for(int z=0;z<n;z++)
{
	for(int a=0;a<n;a++)
	printf("%d ",cube[a][z]);
	printf("\n");
}
fclose(out);
}
void docube()
{
	int lastx=0,lasty=0;
	int &x=lastx,&y=lasty;
	lastx=n/2;
	lasty=0;

	for(int jici=2;jici<=N*N;jici++)
	{
		if(lasty==0&&lastx!=N-1)
		{
			cube[lastx+1][N-1]=jici;
			lastx++;lasty=N-1;
		
		}
	
		else if(x==n-1&&y!=0)
		{
			cube[0][y-1]=jici;
			x=0;y--;
			
		}
		else if(x==n-1&&y==0)
		{
			cube[x][y+1]=jici;
			y++;
			
		}
		else if(x!=n-1&&y!=0)
		{
			if(cube[x+1][y-1]==0)
			{
				cube[x+1][y-1]=jici;
				x++;y--;
			}
			else{
				cube[x][y+1]=jici;
				y++;
			}
		}
		
		
		
		
		
	}
	
	
	
}

	

