#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector<int> &x, int mid, int k)
{
    int sum=0;

    int count=0;

    for(int e=0;e<(int)x.size();e++)
    {
        if(x[e]>mid)
        {
            return 0;
        }
        sum=sum+x[e];
        if(sum>mid)
        {
            sum=x[e];
            count++;
        }
    }

    return count+1<=k;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n,k;
    cin>>n>>k;

    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
    }

    int lo=0, hi=1e15;

    int ans=0;

    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;

        if(check(x, mid, k))
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }

    cout<<ans;

    return 0;
}