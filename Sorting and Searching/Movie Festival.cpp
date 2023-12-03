#include <bits/stdc++.h>
#define int long long
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second==b.second?a.first<b.first:a.second<b.second;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n;cin>>n;

    vector<pair<int, int>> intervals;

    for(int e=0;e<n;e++)
    {
        int a, b;
        cin>>a>>b;

        intervals.push_back({a, b});
    }

    sort(intervals.begin(), intervals.end(), comp);

    int i=0, j=0;

    int count=1;

    while(j<n)
    {
        while(i<n&&intervals[i].first<intervals[j].second)
        {
            i++;
        }
        j=i;
        if(i==n)
        {
            break;
        }
        count++;
    }

    cout<<count;

    return 0;
}