#include<bits/stdc++.h>
#define int long long
using namespace std;

// since both of them play alternatively and optimally
// which is same as player 1 trying to maximize
// score1 - score2 and player 2 trying to minimize
// score1 - score2 so to find the maximum value of
// score1 - score2 we move from state i, j to the
// state x[i] - (i+1, j) or to state x[j] - (i, j-1)

const int N=5001;

vector<vector<int>> dp(N, vector<int> (N, -1));

int solve(vector<int> &x, int i, int j)
{
    if(i==j)
    {
        return x[i];
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    return dp[i][j]=max(x[i]-solve(x, i+1, j), x[j]-solve(x, i, j-1));
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

    vector<int> x(n);

    int sum=0;

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
        sum+=x[e];
    }

    int diff=solve(x, 0, n-1);

    cout<<(sum+diff)/2;
    
    return 0;
}
