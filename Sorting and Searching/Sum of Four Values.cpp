#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n, x;
    cin>>n>>x;

    if(n<4)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<pair<int, pair<int, int>>> pair_sum;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            pair_sum.push_back({a[i]+a[j], {i+1, j+1}});
        }
    }

    sort(pair_sum.begin(), pair_sum.end());

    int i=0, j=(int)pair_sum.size()-1;

    while(i<j)
    {
        if(pair_sum[i].first+pair_sum[j].first<x)
        {
            i++;
        }
        else if(pair_sum[i].first+pair_sum[j].first>x)
        {
            j--;
        }
        else
        {
            if(pair_sum[i].second.first==pair_sum[j].second.first||
                pair_sum[i].second.second==pair_sum[j].second.first||
                pair_sum[i].second.first==pair_sum[j].second.second||
                pair_sum[i].second.second==pair_sum[j].second.second)
            {
                if(pair_sum[i].first==pair_sum[i+1].first)
                {
                    i++;
                }
                else if(pair_sum[j].first==pair_sum[j-1].first)
                {
                    j--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout<<pair_sum[i].second.first<<" "<<pair_sum[i].second.second<<" "<<pair_sum[j].second.first<<" "<<pair_sum[j].second.second;
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";

    return 0;
}