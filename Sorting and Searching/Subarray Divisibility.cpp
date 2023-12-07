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

    vector<int> a(n);

    for(int e=0;e<n;e++)
    {
        cin>>a[e];
    }

    map<int, int> mp;

    int sum=0;

    int count=0;

    mp[0]=1;

    for(int e=0;e<n;e++)
    {
        sum+=a[e];
        sum=sum%n;
        sum=sum+n;
        sum=sum%n;
        count+=mp[sum];
        mp[sum]++;
    }

    cout<<count;

    return 0;
}