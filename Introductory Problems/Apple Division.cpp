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
    vector<int> weights(n);

    for(int e=0;e<n;e++)
    {
        cin>>weights[e];
    }

    int mn=1e15;

    for(int e=0;e<(1<<n);e++)
    {
        int sum1=0;
        int sum2=0;
        for(auto f=0;f<n;f++)
        {
            if(((e>>f)&1)==1)
            {
                sum1+=weights[f];
            }
            else
            {
                sum2+=weights[f];
            }
        }

        mn=min(mn, abs(sum1-sum2));
    }

    cout<<mn;

    return 0;
}
