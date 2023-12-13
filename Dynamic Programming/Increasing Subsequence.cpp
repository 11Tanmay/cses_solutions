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

    vector<int> s;

    for(int e=0;e<n;e++)
    {
        int i;cin>>i;

        if(lower_bound(s.begin(), s.end(), i)==s.end())
        {
            s.push_back(i);
        }
        else
        {
            s[lower_bound(s.begin(), s.end(), i)-s.begin()]=i;
        }
    }

    cout<<(int)s.size();

    return 0;
}
