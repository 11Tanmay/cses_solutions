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
 
    cout<<0<<'\n';
 
    for(int e=2;e<=n;e++)
    {
        cout<<(e*e)*(e*e-1)/2-(4*(e-1)*(e-2))<<'\n';
    }
 
    return 0;
}