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
    
    int x, n;
    cin>>x>>n;

    set<int> positions;

    multiset<int> lengths;

    positions.insert(0);
    positions.insert(x);

    lengths.insert(x);

    for(int e=0;e<n;e++)
    {
        int i;cin>>i;

        auto itr=positions.lower_bound(i);

        int r=*(itr--);
        int l=*itr;

        lengths.erase(lengths.lower_bound(r-l));

        positions.insert(i);

        lengths.insert(i-l);
        lengths.insert(r-i);

        auto itra=lengths.rbegin();

        cout<<*itra<<'\n';
    }  


    return 0;
}
