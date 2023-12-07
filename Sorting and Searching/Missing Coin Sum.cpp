#include<bits/stdc++.h>
#define int long long
using namespace std;

// first we sort the array then if we are at 
// index i then res representsthe first number 
// that cannot be made using elements from 0 to i-1
// this means that all numbers from 0 to res-1 can
// be made using elements from 0 to i-1 now for 
// res to be made we check whether element i if 
// less than equal to res if it is than we can make
// numbers from 0 to res+arr[i]-1 which includes res
// if not then we can only make elements from 0 to res-1 
// and then from arr[i] to arr[i]+res-1, these intervals
// do not contain res so res is our answer.

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n;cin>>n;

    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
    }

    sort(x.begin(), x.end());

    int res=1;

    for(int e=0;e<n;e++)
    {
        if(res<x[e])
        {
            break;
        }
        res+=x[e];
    }

    cout<<res;

    return 0;
}