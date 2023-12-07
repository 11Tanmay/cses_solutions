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
    
    int n,x;
    cin>>n>>x;

    map<int, int> sums;

    int sum=0;

    sums[0]=1;

    int count=0;

    vector<int> a(n);

    for(int e=0;e<n;e++)
    {
        cin>>a[e];
    }

    for(int e=0;e<n;e++)
    {
        sum+=a[e];
        count+=sums[sum-x];
        sums[sum]++;
    }

    cout<<count;

    return 0;
}