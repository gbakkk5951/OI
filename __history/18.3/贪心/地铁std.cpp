#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int Max_diff(vector<int>& degsIn, vector<int>& degsOut)
{
        int size = degsIn.size();
        int max = 0, res = 0;
        for(int i = 0; i < size; ++i)
        {
  int temp = (int)abs((double)degsIn[i] - (double)degsOut[i]);
  if(max < temp)
  {
         max = temp;
         res = i;
  }
        }
        return res;
}
int Sec_diff(vector<int>& nodes, vector<int>& degsIn, vector<int>& degsOut, int flag)
{
        int max = -1000024, pos ;
        for(int i = 0; i < nodes.size(); ++i)
        {
  if(nodes[i] < 0)
         continue;
  int temp = degsIn[nodes[i]] - degsOut[nodes[i]];
  if( flag )
  {
         temp = -temp;
  }
  if( max < temp)
  {
         max = temp;
         pos = i;
  }
        }
        return nodes[pos];
}
void Del_nodes(vector<int>& nodes, int v)
{
        for(int i = 0; i < nodes.size(); ++i)
  if(nodes[i] == v)
  {
         nodes[i] = -1;
         return ;
  }
}

int main()
{
        int T;
        cin >> T;
        for(int iCase = 1; iCase <= T; ++iCase)
        {
  int n, m, k;
  cin >> n >> m >> k;
  k = m - k;

                vector<vector<int> > links(n), rlinks(n);
                vector<int> degsIn(n, 0), degsOut(n, 0);

  for(int i = 0; i < m; ++i)
  {
         int src, dest;
         cin >> src >> dest;
         --src, --dest;
         links[src].push_back(dest);
         rlinks[dest].push_back(src);
         degsIn[dest]++;
         degsOut[src]++;
  }

  for(int i = 0; i < k; ++i)
  {
         int max_d = Max_diff(degsIn, degsOut);
         if(degsOut[max_d] >= degsIn[max_d])
         {
    //out_degree > in_degree
    //In max_d's adj_vex, find a maximum (in_degree - out_degree)
    int sec_d = Sec_diff(links[max_d], degsIn, degsOut, 0);
    Del_nodes(links[max_d], sec_d);
    Del_nodes(rlinks[sec_d], max_d);
    degsOut[max_d]--;
    degsIn[sec_d]--;
         }
         else
         {
    //in_degree > out_degree
    int sec_d = Sec_diff(rlinks[max_d], degsIn, degsOut, 1);
    Del_nodes(rlinks[max_d], sec_d);
    Del_nodes(links[sec_d], max_d);
    degsIn[max_d]--;
    degsOut[sec_d]--;
         }
  }
  int max_d = Max_diff(degsIn, degsOut);
  cout << "Case " << iCase << ": " << (int)abs((double)degsIn[max_d] - (double)degsOut[max_d]) << endl;
        }
        return 0;
}
