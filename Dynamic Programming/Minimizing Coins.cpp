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

    int INF=1e9+1;

    vector<int> min_coins(x+1, INF);

    min_coins[0]=0;

    for(int e=1;e<=x;e++)
    {
        for(int f=0;f<n;f++)
        {
            if(e-coins[f]<0)
            {
                continue;
            }
            min_coins[e]=min(min_coins[e], min_coins[e-coins[f]]+1);
        }
    }

    min_coins[x]=min_coins[x]>=INF?-1:min_coins[x];

    cout<<min_coins[x];
    
    return 0;
}
