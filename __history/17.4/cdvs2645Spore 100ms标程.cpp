#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n , m , x , y , a , b;
int dist[1000 + 2] , inq[1000 + 2];
bool use[1000 + 2];
vector < int > linker[1000 + 2] , di[1000 + 2];
queue < int > q;
int spfa()
{
    
    for( int i = 1 ; i <= n ; i++ ) dist[i] = 1000000000;
    memset( use , 0 , sizeof( use ) );
    memset( inq , 0 , sizeof( inq ) );
    q.push( 1 );
    dist[1] = 0;
    int now , v , cur;
    while( !q.empty() )
    {
        now = q.front() , q.pop();
        use[ now ] = 0;
        for( int i = 0 ; i < linker[ now ].size() ; i++ )
        {
             cur = linker[ now ][i] , v = di[ now ][i];
             if( dist[ cur ] > dist[ now ] + v )
             {
                 dist[ cur ] = dist[ now ] + v;
                 if( !use[ cur ] ) use[ cur ] = 1 , q.push( cur );
                 inq[ cur ]++;
                 if( inq[ cur ] > n ) return 1000000000;
             }
        }
   }
   while(!q.empty() )q.pop(); 
   return dist[n];
}

int main()
{
    while( scanf( "%d %d" , &n , &m ) != EOF )
    {
        if( !n ) if( !m ) break;
        for( register int i = 1 ; i <= m ; i++ )
        {
             scanf( "%d %d %d %d" , &x , &y , &a , &b );
             linker[x].push_back( y );
             di[x].push_back( a );
             linker[y].push_back( x );
             di[y].push_back( b );
        }
        int ans = spfa();
        if( ans == 1000000000 ) cout << "No such path" << endl;
        else cout << ans << endl;
        for( int i = 1 ; i <= n ; i++ ) linker[i].clear() , di[i].clear();
    }
    return 0;
}

