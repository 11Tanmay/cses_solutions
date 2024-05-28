#include <bits/stdc++.h>
#define int long long
using namespace std;

// another standard tree dp question, in this question each node
// has two states 0 or 1 where 0 means that the edge above this 
// node is not taken and 1 means that it has been taken, to calculate
// u,0 we have to take one edge between one of its immediate children
// and for u,1 we don't take any edge between any of its immediate
// children.

const int N=2*1e5+1;

vector<int> tree[N];
vector<vector<int>> dp(N, vector<int> (2, 0));

void dfs(int p, int v)
{
    int sum=0;

    for(auto e: tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dfs(v, e);

        sum+=dp[e][0];
    }

    if(v!=1)
    {
        dp[v][1]=1;
    }

    dp[v][1]+=sum;

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dp[v][0]=max(dp[v][0], sum-dp[e][0]+dp[e][1]);
    }

}

int32_t main()
{
    int n;cin>>n;

    for(int e=0;e<n-1;e++)
    {
        int a, b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(0, 1);

    cout<<max(dp[1][0], dp[1][1]);

    return 0;
}
