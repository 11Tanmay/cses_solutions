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
    
    int n;cin>>n;

    vector<int> ways(n+1);

    ways[0]=1;

    int MOD=1e9+7;

    for(int e=1;e<=n;e++)
    {
        for(int f=max((int)0, e-6);f<=e-1;f++)
        {
            ways[e]=(ways[e]+ways[f])%MOD;
        }
    }

    cout<<ways[n];
    
    return 0;
}
