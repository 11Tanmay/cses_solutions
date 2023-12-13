#include<bits/stdc++.h>
#define int long long
using namespace std;

// answer for aXb is same as bXa

const int N=501;

vector<vector<int>> dp(N, vector<int> (N, -1));

int solve(int l, int b)
{
    if(l==b)
    {
        return 0;
    }

    if(l<b)
    {
        swap(l, b);
    }

    if(dp[l][b]!=-1)
    {
        return dp[l][b];
    }

    int mn=1e15;

    for(int e=1;e<l;e++)
    {
        mn=min(mn, solve(e, b)+solve(l-e, b) + 1);
    }

    for(int f=1;f<b;f++)
    {
        mn=min(mn, solve(l, f)+solve(l, b-f) + 1);
    }

    return dp[l][b]=mn;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int l, b;
    cin>>l>>b;

    cout<<solve(l, b);
    
    return 0;
}
