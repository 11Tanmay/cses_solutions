#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// in this question we move around the graph visiting each vertex
// and keep track of the vertex visited using bitmasking
// for the base case if we reach the nth vertex and all the
// vertices are visited then we return 1 else we return 0.
// we memoise the states, to make the calculations faster.

const int N = 21;
const int MOD = 1e9+7;

vector<int> graph[N];
int dp[(1<<N)][N];

int hamiltonian(int n, int vis, int node)
{
    vis = (vis ^ (1<<node));
    if(node==n-1)
    {
        return vis==0;
    }

    if(dp[vis][node]!=-1)
    {
        return dp[vis][node];
    }

    dp[vis][node] = 0;

    for(auto child: graph[node])
    {
        if(vis & (1<<child))
        {
            dp[vis][node] = (dp[vis][node] + hamiltonian(n, vis, child)) % MOD;
        }
    }

    return dp[vis][node];
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;

        a--;
        b--;

        graph[a].push_back(b);
    }

    memset(dp, -1, sizeof(dp));
    cout<<hamiltonian(n, (1<<n) - 1, 0);

    return 0;
}