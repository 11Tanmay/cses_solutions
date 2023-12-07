#include<bits/stdc++.h>
#define int long long
using namespace std;

// we first sort the movie times according to their 
// finishing times, now for ith movie if we have a
// person that is free we assign this movie to that
// person else we skip this movie. we check if a 
// person is free by checking if a lower value is
// present in multiset than this time if it exists
// we update it with the ending time of this movie.

bool comp(pair<int, int> &x, pair<int, int> &y)
{
    return x.second==y.second?x.first<y.first:x.second<y.second;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n,k;
    cin>>n>>k;

    vector<pair<int, int>> intervals;

    for(int e=0;e<n;e++)
    {
        int a, b;
        cin>>a>>b;

        intervals.push_back({a, b});
    }

    sort(intervals.begin(), intervals.end(), comp);

    int count=0;

    multiset<int> s;

    for(int e=0;e<n;e++)
    {
        if(s.lower_bound(-intervals[e].first)!=s.end())
        {
            s.erase(s.lower_bound(-intervals[e].first));
            s.insert(-intervals[e].second);
            count++;
        }
        else if((int)s.size()<k)
        {
            s.insert(-intervals[e].second);
            count++;
        }
    }

    cout<<count;
    
    return 0;
}
