#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int q;cin>>q;
 
    while(q--)
    {
        int x, y;
        cin>>x>>y;
 
        if(max(x, y)%2==1)
        {
            if(x<=y)
            {
                cout<<y*y-x+1<<'\n';
            }
            else
            {
                cout<<(x-1)*(x-1)+y<<'\n';
            }
        }
        else
        {
            if(x<=y)
            {
                cout<<(y-1)*(y-1)+x<<'\n';
            }
            else
            {
                cout<<x*x-y+1<<'\n';
            }
        }
    }
 
    return 0;
}