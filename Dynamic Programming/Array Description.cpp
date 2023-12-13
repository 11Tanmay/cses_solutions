#include<bits/stdc++.h>
// #define int long long
using namespace std;

// in this question from state m, i we can go to state
// m, i-1 , m, i , m, i+1 and when we are at state m, i
// we have to check whether xi is fixed or not. If it is
// fixed we check whether the abs(xi-m)<=1 or not, and we
// go to the states xi, i-1. Now if xi==0 and i==n-1 we
// iterate over all states from 1, i-1 to m, i-1.

const int MOD=(int)1e9+7;
int dp[101][(int)1e5+1];

int solve(vector<int> &x, int max_m, int m, int i)
{
    if(i<0)
    {
        return 1;
    }

    if(dp[m][i]!=-1)
    {
        return dp[m][i];
    }

    if(x[i]!=0&&i!=(int)x.size()-1&&abs(m-x[i])>1)
    {
        return 0;
    }

    int sum=0;

    if(x[i]==0)
    {
        if(i==(int)x.size()-1)
        {
            for(int e=1;e<=max_m;e++)
            {
                sum=(sum+solve(x, max_m, e, i-1))%MOD;
            }
        }
        else
        {
            for(int e=max(1, m-1);e<=min(m+1, max_m);e++)
            {
                sum=(sum+solve(x, max_m, e, i-1))%MOD;
            }
        }
    }
    else
    {
        sum=solve(x, max_m, x[i], i-1)%MOD;
    }

    return dp[m][i]=sum%MOD;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n, m;
    cin>>n>>m;

    memset(dp, -1, sizeof dp);

    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
    }

    cout<<solve(x, m, 0, n-1);
    
    return 0;
}
