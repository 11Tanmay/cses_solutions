#include <bits/stdc++.h>
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
    
    int n,s;
    cin>>n>>s;

    vector<pair<int, int>> nums(n);

    for(int e=0;e<n;e++)
    {
        cin>>nums[e].first;
        nums[e].second=e+1;
    }

    sort(nums.begin(), nums.end());

    int i=0, j=n-1;

    while(i<j)
    {
        if(nums[i].first+nums[j].first<s)
        {
            i++;
        }
        else if(nums[i].first+nums[j].first>s)
        {
            j--;
        }
        else
        {
            cout<<nums[i].second<<" "<<nums[j].second<<'\n';
            return 0;
        }
    }

    cout<<"IMPOSSIBLE";
    return 0;
}
