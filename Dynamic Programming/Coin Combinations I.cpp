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
    
    int n, x;
    cin>>n>>x;

    vector<int> coins(n);

    for(int e=0;e<n;e++)
    {
        cin>>coins[e];
    }

    int MOD=1e9+7;

    vector<int> ways(x+1, 0);

    ways[0]=1;

    for(int e=1;e<=x;e++)
    {
        for(int f=0;f<n;f++)
        {
            if(e-coins[f]<0)
            {
                continue;
            }
            ways[e]=(ways[e]+ways[e-coins[f]])%MOD;
        }
    }

    cout<<ways[x];
    
    return 0;
}
