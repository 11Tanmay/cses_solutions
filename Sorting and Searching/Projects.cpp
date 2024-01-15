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

    map<int, int> compress;

    vector<int> a(n), b(n), p(n);

    for(int e=0;e<n;e++)
    {
        cin>>a[e]>>b[e]>>p[e];

        b[e]++;

        compress[a[e]];
        compress[b[e]];
    }

    int total_coords=0;

    for(auto &e: compress)
    {
        e.second=total_coords;
        total_coords++;
    }

    vector<vector<pair<int, int>>> projects(total_coords);

    for(int e=0;e<n;e++)
    {
        projects[compress[b[e]]].push_back({compress[a[e]], p[e]});
    }

    vector<int> dp(total_coords, 0);

    for(int e=0;e<total_coords;e++)
    {
        if(e>0)
        {
            dp[e]=dp[e-1];
        }

        for(auto p: projects[e])
        {
            dp[e]=max(dp[e], dp[p.first] + p.second);
        }
    }

    cout<<dp[total_coords-1];

    return 0;
}
