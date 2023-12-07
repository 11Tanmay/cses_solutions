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
    
    int n, k;
    cin>>n>>k;

    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
    }

    map<int, int> mp;

    int count=0;

    int distinct=0;

    int i=0, j=-1;

    while(1)
    {
        j++;
        if(j==n)
        {
            break;
        }
        mp[x[j]]++;
        if(mp[x[j]]==1)
        {
            distinct++;
        }
        if(distinct<=k)
        {
            count+=(j-i+1);
        }
        else
        {
            while(distinct>k)
            {
                mp[x[i]]--;
                if(mp[x[i]]==0)
                {
                    distinct--;
                }
                i++;
            }

            count+=(j-i+1);
        }
    }

    cout<<count;

    return 0;
}