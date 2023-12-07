#include<bits/stdc++.h>
#define int long long
using namespace std;

// median will give the minimum sum
// of differences in this question

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n;cin>>n;
    vector<int> p(n);

    for(int e=0;e<n;e++)
    {
        cin>>p[e];
    }

    sort(p.begin(), p.end());

    int ans=0;
    int median=p[n/2];
    for(int e=0;e<n;e++)
    {
        ans+=abs(p[e]-median);
    }

    cout<<ans;

    return 0;
}