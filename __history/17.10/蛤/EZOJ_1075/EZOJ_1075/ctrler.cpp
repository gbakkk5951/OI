#include<bits/stdc++.h>
#include <unistd.h>
#define debug cerr
using namespace std;

int main()
{
    static char s[1024];
    
    for(int i=0;i<20;i++)
    {
        debug<<"i = "<<i<<endl;
        freopen("arg.txt","w",stdout);
            printf("%d\n",i);
        fclose(stdout);
        
        
        sprintf(s,"maker > frog%d.in",i);
        sleep(1);
        system(s);
        debug<<"Data Made"<<endl;
        sprintf(s,"std < frog%d.in > frog%d.out",i,i);
        system(s);
        debug<<"Run"<<endl;
    }
    
    return 0;
}
