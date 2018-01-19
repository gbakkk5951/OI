#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
using namespace std;
bool vis[200001];int dist[200001];
//����һ�¸�����ĺ��壺vis�����ô���spfa��ķ��ʱ�ǣ�����ʱ��ķ��ʱ�ǣ�dist��ÿ����ľ�����
int n,m,s,t,ans=0;
//s����㣬t���յ㣬ans�Ƿ��ô�
int nedge=-1,p[200001],c[200001],cc[200001],nex[200001],head[200001];
//�����Ǳ߱�����һ�¸�����ĺ��壺p[i]��ʾ��ĳһ������ı��Ϊi�ı߶�Ӧ�㣬c��ʾ���Ϊi�ıߵ�������cc��ʾ���Ϊi�ıߵķ��ã�nex��head��˵�˰ɡ�����
inline void addedge(int x,int y,int z,int zz){
    p[++nedge]=y;c[nedge]=z;cc[nedge]=zz;nex[nedge]=head[x];head[x]=nedge;
}
//���ߣ�����ģ��߱��ң�
inline bool spfa(int s,int t){
    memset(vis,0,sizeof vis);
    for(int i=0;i<=n;i++)dist[i]=1e9;dist[t]=0;vis[t]=1;
//����SPFA����ά�������ŵ�ʱ��Ҫ�����ܣ���������ά�������յ�����·��
    deque<int>q;q.push_back(t);
//ʹ����SPFA��SLF�Ż���SLF�������аٶȻ�Google��
    while(!q.empty()){
        int now=q.front();q.pop_front();
        for(int k=head[now];k>-1;k=nex[k])if(c[k^1]&&dist[p[k]]>dist[now]-cc[k]){
//����c[k^1]��Ϊʲô�أ���Ϊ����Ҫ��֤����������SPFA�ǵ����ܵģ�����˵����Ҫ��c[k]�Ķ�Ӧ����������ģ�������֤�ߵķ�������ȷ��
            dist[p[k]]=dist[now]-cc[k];
//��Ϊ�Ѿ��ǵ��ŵ��ˣ�����Ҳ���Ժ�������׵�֪�����ߵ�ʱ����ߵı�Ȩ�Ǹ��ģ����Լ�һ�¾Ͷ��ˣ�����������
            if(!vis[p[k]]){
                vis[p[k]]=1;
                if(!q.empty()&&dist[p[k]]<dist[q.front()])q.push_front(p[k]);else q.push_back(p[k]);
//SLF�Ż�
            }
        }
        vis[now]=0;
    }
    return dist[s]<1e9;
//�ж�����յ��Ƿ���ͨ
}
inline int dfs(int x,int low){
//������ǽ��Љ�����
    if(x==t){vis[t]=1;return low;}
    int used=0,a;vis[x]=1;
//����ǲ��Ǻ�dinic����
    for(int k=head[x];k>-1;k=nex[k])if(!vis[p[k]]&&c[k]&&dist[x]-cc[k]==dist[p[k]]){
//��������ͱ�ʾ�����߿��Խ��Љ���
        a=dfs(p[k],min(c[k],low-used));
        if(a)ans+=a*cc[k],c[k]-=a,c[k^1]+=a,used+=a;
//�ۼӴ𰸣������Ȳ�����������
        if(used==low)break;
    }
    return used;
}
inline int costflow(){
    int flow=0;
    while(spfa(s,t)){
//�ж�����յ��Ƿ���ͨ������ͨ˵���������������˳�
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof vis);
            flow+=dfs(s,1e9);
//һֱ����ֱ���߲���Ϊֹ������Ҳ����ʡʱ��Ŷ��
        }
    }
    return flow;//���ﷵ�ص�������������õĴ���ans��
}
int main()
{
    memset(nex,-1,sizeof nex);memset(head,-1,sizeof head);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int x,y,z,zz;scanf("%d%d%d%d",&x,&y,&z,&zz);
        addedge(x,y,z,zz);addedge(y,x,0,-zz);
    }
    printf("%d ",costflow());printf("%d",ans);
    return 0;
}
