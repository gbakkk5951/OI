#include<iostream>
#include<cstdio>
#include<cstring>
#define searchnext(x,y,k) y==5? search(x+1,1,k):search(x,y+1,k)
using namespace std;
bool mp[101][6],t[101][6],ans;
int s,xx[4]={0,0,-1,1},yy[4]={-1,1,0,0},n;
void del(int x,int y)
{
     t[x][y]=0;
     for(int i=0;i<4;i++)
     {
             int nowx=x+xx[i],nowy=y+yy[i];
             if(nowx>5||nowy>5||nowx<1||nowy<1||!t[nowx][nowy])continue;
             del(nowx,nowy);
             }
 }
bool judans()
{
     bool flag=0;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
           t[i][j]=mp[i][j];
     for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
        {
                if(t[i][j])
                {
                            if(!flag){del(i,j);flag=1;}
                            else return 0;
                }
        }
     return 1;
 }
void search(int x,int y,int k)
{
     if(k==s){if(judans())ans=1;return;}
     if(ans||x==n+1)return;
     for(int i=y;i<=5;i++){
             if(mp[x][i])continue;
             mp[x][i]=1;
             searchnext(x,i,k+1);
             mp[x][i]=0;
             }
     for(int i=x+1;i<=n;i++)
        for(int j=1;j<=5;j++){
             if(mp[i][j])continue;
             mp[i][j]=1;
             searchnext(i,j,k+1);
             mp[i][j]=0;
             }
 }
int main()
{
    scanf("%d",&n);
    char ch[10];
    for(int i=1;i<=n;i++)
    {
       scanf("%s",ch);
       for(int j=1;j<=5;j++)
       mp[i][j]=ch[j-1]-'0';
       }
    for(s=0;s<=25;s++)
        {search(1,1,0);if(ans){printf("%d\n",s);return 0;}}
}
