#include<bits/stdc++.h>
#define int long long
using namespace std;

// we calculate the power of 5 in the prime factorization of n!
// for this we divide n by increasing powers of 5
// here increasing powers are necessary because some numbers upto
// n may contain more than one 5's in their prime factorization

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n;cin>>n;

    int ans=0;

    for(int pow_of_5=5;pow_of_5<=n;pow_of_5*=5)
    {
        ans+=n/pow_of_5;
    }

    cout<<ans;

    return 0;
}