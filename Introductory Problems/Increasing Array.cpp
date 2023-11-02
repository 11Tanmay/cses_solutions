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
 
    int count=0;
 
    for(int e=1;e<n;e++)
    {
        if(nums[e]>=nums[e-1])
        {
            continue;
        }
        count+=abs(nums[e]-nums[e-1]);
        nums[e]+=abs(nums[e]-nums[e-1]);
    }
 
    cout<<count;
 
    return 0;
}
