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

    vector<pair<int, int>> tasks;

    for(int e=0;e<n;e++)
    {
        int a, d;
        cin>>a>>d;

        tasks.push_back({a, d});
    }

    sort(tasks.begin(), tasks.end());

    int ans=0;

    int finishing_time=0;

    for(int e=0;e<n;e++)
    {
        finishing_time+=tasks[e].first;
        ans=ans+tasks[e].second-finishing_time;
    }

    cout<<ans;
    
    return 0;
}
