#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int MOD=1e9+7;
 
int bin_exp(int b, int e)
{
    if(e==0)
    {
        return 1;
    }
 
    return e%2==0?(bin_exp(b, e/2)*bin_exp(b, e/2))%MOD:(b*bin_exp(b, e-1))%MOD;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n;cin>>n;
 
    cout<<bin_exp(2, n);
 
    return 0;
}
