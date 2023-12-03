#include <bits/stdc++.h>
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

    int n, m;
    cin>>n>>m;

    multiset<int> s;

    for(int e=0;e<n;e++)
    {
        int i;cin>>i;

        s.insert(-i);
    }

    for(int e=0;e<m;e++)
    {
        int i;cin>>i;

        if(s.lower_bound(-i)!=s.end())
        {
            cout<<-*s.lower_bound(-i)<<" ";
            s.erase(s.lower_bound(-i));
        }
        else
        {
            cout<<-1<<" ";
        }
    }
    return 0;
}