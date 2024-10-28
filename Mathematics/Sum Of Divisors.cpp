#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// in this question we know that each divisor i will occur
// n/i times in the summation now we have to find what range
// of numbers occur x times so we then find sum(range_sum * x)
// now the smallest number that is repeated i times is n/(i+1) + 1
// and the greatest that is repeated i times is n/i, now here i is
// a divisor of n so we have in total O(2rootn) values of i 
// thus the overall time complexity of the solution is O(root n).

const int MOD = 1e9 + 7;

int bin_exp(int b, int p)
{
    if(p==0)
    {
        return 1;
    }
    return p%2 == 1 ? (b * bin_exp(b, p-1))%MOD : (bin_exp(b, p/2) * bin_exp(b, p/2))%MOD;
}

int inv_2 = bin_exp(2, MOD-2);

int sum(int n)
{
    return ((((n%MOD) * ((n+1) % MOD))%MOD) * inv_2)%MOD;
}

int32_t main() 
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n;cin>>n;

    int result = 0;

    for(int i=1,j;i<=n;i=j)
    {
        int quotient = n/i;
        j = n/quotient + 1; // smallest number that is repeated quotient-1 times for next iteration for currenct iteration it is the upperbound.

        result = (result + ((((sum(j-1) - sum(i-1) + MOD)%MOD) * (quotient%MOD))%MOD))%MOD;
    }

    cout<<result;

    return 0;
}
