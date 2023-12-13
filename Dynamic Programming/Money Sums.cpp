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

    sort(nums.begin(), nums.end());

    vector<int> sums;

    map<int, bool> is_present;

    for(int e=0;e<n;e++)
    {
        vector<int> new_sums;
        for(auto sum:sums)
        {
            if(is_present[sum+nums[e]]!=1)
            {
                is_present[sum+nums[e]]=1;
                new_sums.push_back(sum+nums[e]);
            }
        }

        if(is_present[nums[e]]!=1)
        {
            is_present[nums[e]]=1;
            new_sums.push_back(nums[e]);
        }

        for(auto e:new_sums)
        {
            sums.push_back(e);
        }
    }

    cout<<sums.size()<<'\n';

    sort(sums.begin(), sums.end());

    for(auto sum:sums)
    {
        cout<<sum<<" ";
    }
    
    return 0;
}
