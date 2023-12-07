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

    vector<int> x(n);

    map<int ,int> mp;
    map<int, int> ind;

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
        ind[x[e]]=e;
        mp[e+1]=1;
    }

    for(int e=n-1;e>=0;e--)
    {
        if(ind[x[e]+1]>ind[x[e]])
        {
            mp[x[e]]+=mp[x[e]+1];
        }
    }

    int num=1;

    int count=0;

    while(num<=n)
    {
        num+=mp[num];
        count++;
    }

    cout<<count;

    return 0;
}