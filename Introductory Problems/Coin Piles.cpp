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

    int q;cin>>q;

    while(q--)
    {
        int a, b;

        cin>>a>>b;

        if((2*a - b)%3 == 0 && (2*a -b) >= 0 && (2*b - a)%3 == 0 && (2*b-a) >= 0)
        {
            cout<<"YES"<<'\n';
        }
        else
        {
            cout<<"NO"<<'\n';
        }
    }

    return 0;
}