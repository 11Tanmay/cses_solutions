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

    vector<int> k(n);

    for(int e=0;e<n;e++)
    {
        cin>>k[e];
    }

    multiset<int> s;

    for(int e=0;e<n;e++)
    {
        if(s.upper_bound(k[e])==s.end())
        {
            s.insert(k[e]);
        }
        else
        {
            s.erase(s.upper_bound(k[e]));
            s.insert(k[e]);
        }
    }

    cout<<(int)s.size();

    return 0;
}
