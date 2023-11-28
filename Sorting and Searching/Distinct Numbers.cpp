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

    vector<int> nums(n);

    for(int e=0;e<n;e++)
    {
        cin>>nums[e];
    }

    map<int, int> mp;

    for(int e=0;e<n;e++)
    {
        mp[nums[e]]++;
    }

    cout<<mp.size();

    return 0;
}