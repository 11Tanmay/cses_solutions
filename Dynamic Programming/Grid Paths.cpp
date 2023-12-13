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

    vector<string> grid(n);

    for(int e=0;e<n;e++)
    {
        cin>>grid[e];
    }

    vector<vector<int>> paths(n+1, vector<int> (n+1, 0));

    int MOD=1e9+7;

    paths[1][1]=grid[0][0]=='*'?0:1;

    for(int e=1;e<=n;e++)
    {
        for(int f=1;f<=n;f++)
        {
            if(grid[e-1][f-1]=='*')
            {
                continue;
            }
            
            paths[e][f]=(paths[e][f]+paths[e-1][f])%MOD;
            paths[e][f]=(paths[e][f]+paths[e][f-1])%MOD;
        }
    }

    cout<<paths[n][n];
    
    return 0;
}
