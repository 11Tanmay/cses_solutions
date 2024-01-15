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

    vector<int> t(n);

    for(int e=0;e<n;e++)
    {
        cin>>t[e];
    }

    sort(t.begin(), t.end());

    int sum=0;

    for(int e=0;e<n-1;e++)
    {
        sum+=t[e];
    }

    if(sum<t[n-1])
    {
        cout<<2*t[n-1];
    }
    else
    {
        cout<<sum+t[n-1];
    }

    return 0;
}
