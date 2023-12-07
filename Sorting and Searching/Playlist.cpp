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

    map<int, int> u;

    int i=0, j=-1;

    int ans=0;

    while(j!=n-1)
    {
        j++;
        u[k[j]]++;

        while(u[k[j]]!=1)
        {
            u[k[i]]--;
            i++;
        }

        ans=max(ans, j-i+1);
    }

    cout<<ans;

    return 0;
}