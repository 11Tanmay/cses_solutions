#include <bits/stdc++.h>
#define int long long
using namespace std;

// this question is similar to "Queries to increment array elements in a 
// given range by a given value for a given number of times" where we have to
// then print the final array, in this question we make three arrays for each
// node sum, up, ans, sum will be incremented when a node is end-point of
// path and up array of the lca of the endpoints will be decremented,
// now a dfs is run to calculate the final answer where sum for a node
// is incremented by addition of ans and up of its children, finally the
// ans for a node will simply be the addition of up and sum of the node.

const int N=2*1e5+1;

vector<vector<int>> parent(N, vector<int> (log2(N)+1, -1));
vector<int> tree[N];
vector<int> depth(N, 0);
vector<int> sum(N, 0);
vector<int> up(N, 0);
vector<int> ans(N, 0);

int find_kth(int x, int k)
{
    for(int e=log2(N);e>=0;e--)
    {
        if(x==-1)
        {
            continue;
        }
        if((k>>e)&1)
        {
            x=parent[x][e];
        }
    }

    return x;
}

int lca(int a, int b)
{
    if(depth[a]<depth[b])
    {
        swap(a, b);
    }

    a=find_kth(a, depth[a]-depth[b]);

    if(a==b)
    {
        return a;
    }

    for(int e=log2(N);e>=0;e--)
    {
        int x=parent[a][e];
        int y=parent[b][e];
        if(x==y)
        {
            continue;
        }
        a=x;
        b=y;
    }

    return parent[a][0];
}

void dfs(int v, int p)
{
    depth[v]=depth[p]+1;

    if(v!=1)
    {
        parent[v][0]=p;
    }

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dfs(e, v);

        sum[v]+=(ans[e]+up[e]);
    }

    ans[v]=up[v]+sum[v];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int e=0;e<n-1;e++)
    {
        int a, b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    for(int e=1;e<=log2(n);e++)
    {
        for(int f=1;f<=n;f++)
        {
            if(parent[f][e-1]==-1)
            {
                continue;
            }
            parent[f][e]=parent[parent[f][e-1]][e-1];
        }
    }

    while(m--)
    {
        int a, b;
        cin>>a>>b;

        sum[a]++;
        sum[b]++;
        up[lca(a, b)]--;
    }

    dfs(1, 0);

    for(int e=1;e<=n;e++)
    {
        cout<<ans[e]<<" ";
    }

    return 0;
}
