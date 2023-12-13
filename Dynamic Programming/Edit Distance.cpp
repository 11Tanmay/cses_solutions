#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5*1e3+1;

vector<vector<int>> dp(N, vector<int> (N, -1));

int solve(string &a, string &b, int i, int j)
{
    if(i<0&&j<0)
    {
        return 0;
    }
    else if(i<0)
    {
        return j+1;
    }
    else if(j<0)
    {
        return i+1;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(a[i]==b[j])
    {
        return dp[i][j]=solve(a, b, i-1, j-1);
    }

    return dp[i][j]=min({
                        solve(a, b, i-1, j),
                        solve(a, b, i, j-1),
                        solve(a, b, i-1, j-1)
                    }) + 1;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    string a, b;
    cin>>a>>b;

    int n=a.size();
    int m=b.size();

    cout<<solve(a, b, n-1, m-1);
    
    return 0;
}
