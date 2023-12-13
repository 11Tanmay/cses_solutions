#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=62626;
const int MOD=1e9+7;

vector<vector<int>> dp(N, vector<int> (501, -1));

int bin_exp(int b, int p)
{
    if(p==0)
    {
        return 1;
    }
    return p%2==0?(bin_exp(b, p/2)*bin_exp(b, p/2))%MOD:(b*bin_exp(b, p-1))%MOD;
}
 
int solve(int req_sum, int n)
{
    if(n==0&&req_sum==0)
    {
        return 1;
    }
    if(req_sum<0||n==0)
    {
        return 0;
    }

    if(dp[req_sum][n]!=-1)
    {
        return dp[req_sum][n];
    }
    return dp[req_sum][n]=(solve(req_sum-n, n-1)+solve(req_sum, n-1))%MOD;
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

    int req_sum=(n*(n+1))/2;

    if(req_sum%2!=0)
    {
        cout<<0;
    }
    else
    {
        req_sum=req_sum/2;
        cout<<(solve(req_sum, n)*bin_exp(2, MOD-2))%MOD;
    }
    
    return 0;
}
