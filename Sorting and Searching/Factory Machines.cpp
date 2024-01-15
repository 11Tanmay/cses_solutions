#include<bits/stdc++.h>
#define int long long
using namespace std;

int check(vector<int> &k, int mid, int mx)
{
    int products=0;

    for(int e=0;e<(int)k.size();e++)
    {
        products+=(int)(mid/k[e]);
        if(products>=mx)
        {
            return 1;
        }
    }

    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    int n,t;
    cin>>n>>t;

    vector<int> k(n);

    for(int e=0;e<n;e++)
    {
        cin>>k[e];
    }

    sort(k.begin(), k.end());

    reverse(k.begin(), k.end());

    int lo=1, hi=1e18;

    int mid;

    int ans=0;

    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;

        if(check(k, mid, t))
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }

    cout<<ans;

    return 0;
}
