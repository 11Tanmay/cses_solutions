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

    if(n==1)
    {
        cout<<1;
    }
    else
    {
        set<int> s;

        for(int e=1;e<=n;e++)
        {
            s.insert(e);
        }

        int i=2;

        while(s.size()!=0)
        {
            cout<<i<<" ";

            s.erase(i);

            i=s.upper_bound(i)==s.end()?*s.begin():*s.upper_bound(i);
            i=s.upper_bound(i)==s.end()?*s.begin():*s.upper_bound(i);
        }
    }
 
    return 0;
}