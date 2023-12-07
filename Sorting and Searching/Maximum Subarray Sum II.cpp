#include<bits/stdc++.h>
#define int long long
using namespace std;

// so if we are at an index i the subarray of lengths
// between a and b ending at i can start from i-b+1
// to i-a+1 so if we now store the prefix sum array 
// to calculate the subarray sum we need to find
// max(prefix[i]-prefix[j]) where j is lying from
// i-b to i-a for this to be maximum prefix[j] needs
// to be minimum so we have to find for every index i
// minimum value of prefix j such that j is from i-b
// to i-a this can be done by making sparse table on
// prefix sums.
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n,a,b;
    cin>>n>>a>>b;

    vector<int> x(n+1);

    for(int e=1;e<=n;e++)
    {
        cin>>x[e];
    }

    vector<vector<int>> sparse_table(n+1, vector<int> ((int)log2(n)+1, 0));

    for(int e=1;e<=n;e++)
    {
        sparse_table[e][0]=sparse_table[e-1][0]+x[e];
    }

    for(int e=1;e<=log2(n);e++)
    {
        for(int f=0;f<=n-(1<<e)+1;f++)
        {
            sparse_table[f][e]=min(sparse_table[f][e-1], sparse_table[f+(1<<(e-1))][e-1]);
        }
    }

    int mx=-1e15;

    for(int e=a;e<=n;e++)
    {
        int l=max((int)0, e-b);
        int r=max((int)0, e-a);

        int length=(int)log2(r-l+1);

        int range_min=min(sparse_table[l][length], 
                          sparse_table[r-(1<<length)+1][length]);

        mx=max(mx, sparse_table[e][0]-range_min);
    }

    cout<<mx;

    return 0;
}
