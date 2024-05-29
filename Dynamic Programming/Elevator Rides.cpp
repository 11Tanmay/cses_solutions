#include <bits/stdc++.h>
#define int long long
using namespace std;

// in this question the naive approach would be to use the state transition
// dp[X]=min(dp[X], 1+dp[X-x]) where x is a subset of X, the time complexity of
// this approach would be O(3^n), but let us form the subsets instead, in
// this way for a person i if a new ride is needed then dp[X]=min(dp[X], {k+1, wi})
// or if not then dp[X]=min(dp[X], {k, wi+W}) where dp[X^(1<<i)]={k, W}, the time
// complexity of this approach is then O(n*2^n).

int32_t main()
{
    int n, x;
    cin>>n>>x;

    vector<int> individual_weight(n);

    for(int e=0;e<n;e++)
    {
        cin>>individual_weight[e];
    }

    vector<pair<int, int>> dp((1<<n), {21, 0});      //rides, weight

    dp[0]={1, 0};

    for(int mask=1;mask<(1<<n);mask++)
    {
        for(int person=0;person<n;person++)
        {
            if((mask>>person)&1)
            {
                auto [rides, weight]=dp[mask^(1<<person)];

                if(weight+individual_weight[person]>x)
                {
                    rides++;
                    weight=min(weight, individual_weight[person]);
                }
                else
                {
                    weight+=individual_weight[person];
                }

                dp[mask]=min(dp[mask], {rides, weight});
            }
        }
    }

    cout<<dp[(1<<n)-1].first;

    return 0;
}
