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

    int n, x;
    cin>>n>>x;

    vector<pair<int, int>> a(n);

    for(int e=0;e<n;e++)
    {
        cin>>a[e].first;

        a[e].second=e+1;
    }

    sort(a.begin(), a.end());

    for(int i=0;i<n-2;i++)
    {
        int j=i+1, k=n-1;

        while(j<k)
        {
            if(a[j].first+a[k].first>x-a[i].first)
            {
                k--;
            }
            else if(a[j].first+a[k].first<x-a[i].first)
            {
                j++;
            }   
            else
            {
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second;

                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";

    return 0;
}