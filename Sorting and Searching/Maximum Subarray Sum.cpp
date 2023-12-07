#include<bits/stdc++.h>
#define int long long
using namespace std;

// if all numbers are negative the output
// the maximum number present in the array

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

    int sum=0;
    int global_mx=0;
    int all_neg=1;

    for(int e=0;e<n;e++)
    {
        sum+=nums[e];
        if(sum<0)
        {
            sum=0;
        }
        if(nums[e]>=0)
        {
            all_neg=0;
        }
        global_mx=max(global_mx, sum);
    }

    if(all_neg)
    {
        global_mx=-1e9;
        for(int e=0;e<n;e++)
        {
            global_mx=max(global_mx, nums[e]);
        }
    }

    cout<<global_mx;

    return 0;
}