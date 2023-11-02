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
 
    vector<int> nums(n, 0);
 
    for(int e=0;e<n-1;e++)
    {
        cin>>nums[e];
    }
 
    for(int e=0;e<n;e++)
    {
        if(nums[e]!=0&&nums[e]!=e+1)
        {
            swap(nums[e], nums[nums[e]-1]);
            e--;
        }
    }
 
    for(int e=0;e<n;e++)
    {
        if(nums[e]==0)
        {
            cout<<e+1;
            break;
        }
    }
 
    return 0;
}