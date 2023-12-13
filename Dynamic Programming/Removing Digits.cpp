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

    int INF=1e9;

    vector<int> steps(n+1, INF);

    steps[0]=0;

    for(int e=1;e<=n;e++)
    {
        for(int f=0;f<=6;f++)
        {
            int digit=(e/(int)pow(10, f))%10;

            if(e-digit<0)
            {
                continue;
            }

            steps[e]=min(steps[e], steps[e-digit]+1);
        }
    }

    cout<<steps[n];
    
    return 0;
}
