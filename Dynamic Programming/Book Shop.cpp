#include<bits/stdc++.h>
// #define int long long
using namespace std;

// in this question to avoid MLE 
// use int instead of long long

int dp[1001][(int)1e5+1];
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n, x;
    cin>>n>>x;

    vector<int> h(n+1);

    for(int e=1;e<=n;e++)
    {
        cin>>h[e];
    }

    vector<int> s(n+1);

    for(int f=1;f<=n;f++)
    {
        cin>>s[f];
    }

    for(int e=0;e<=n;e++)
    {
        for(int f=0;f<=x;f++)
        {
            if(e==0)
            {
                dp[e][x]=0;
                continue;
            }

            int x=f-h[e]<0?INT_MIN:dp[e-1][f-h[e]];
            int y=dp[e-1][f];

            dp[e][f]=max(x+s[e], y);
        }
    }

    cout<<dp[n][x];
    
    return 0;
}
