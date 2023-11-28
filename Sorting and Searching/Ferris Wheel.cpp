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

    int n,x;
    cin>>n>>x;

    vector<int> weights(n);

    for(int e=0;e<n;e++)
    {
        cin>>weights[e];
    }

    sort(weights.begin(), weights.end());

    int ans=0;
    int i=0, j=n-1;

    while(i<=j)
    {
        if(i==j)
        {
            ans++;
            j--;
        }
        else
        {
            if(weights[i]+weights[j]<=x)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
    }

    cout<<ans;

    return 0;
}