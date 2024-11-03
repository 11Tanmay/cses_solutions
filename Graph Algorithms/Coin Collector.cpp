#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

const int N = 100010;

// condense the graph then find topological order
// of the nodes of the condensed graph, process
// the nodes of the condensed graph in reverse
// topological order from sink to source, and
// find the maximum number of coins that can be collected.
// if a node leads to multiple nodes then we take the one
// which maximizes the coins collected that is why we
// iterate from the sink to the source.

vector<int> coins(N);
vector<int> graph[N];
vector<int> reverse_graph[N];
vector<int> topo_order;
int vis[N];
vector<pair<int, int> > edges;
vector<int> condensed_graph[N];
vector<int> condensed_coins(N, 0);
vector<int> parent(N, 0);

void dfs(int node)
{
    vis[node] = 1;

    for (auto child : graph[node])
    {
        if (vis[child])
        {
            continue;
        }

        dfs(child);
    }

    topo_order.push_back(node);
}

void reverse_dfs(int node, int component)
{
    vis[node] = 1;

    condensed_coins[component] += coins[node];
    parent[node] = component;

    for (auto child : reverse_graph[node])
    {
        if (vis[child] == 1)
        {
            continue;
        }

        reverse_dfs(child, component);
    }
}

void dfs_condensed(int node)
{
    vis[node]=1;

    for(auto child: condensed_graph[node])
    {
        if(vis[child])
        {
            continue;
        }

        dfs_condensed(child);
    }

    topo_order.push_back(node);
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }

        dfs(i);
    }

    reverse(topo_order.begin(), topo_order.end());

    int scc = 1;

    memset(vis, 0, sizeof(vis));
    for (auto i : topo_order)
    {
        if (vis[i])
        {
            continue;
        }

        reverse_dfs(i, scc);
        scc++;
    }

    for (auto edge : edges)
    {
        if (parent[edge.first] != parent[edge.second])
        {
            condensed_graph[parent[edge.first]].push_back(parent[edge.second]);
        }
    }

    topo_order.clear();

    memset(vis, 0, sizeof(vis));

    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            continue;
        }

        dfs_condensed(i);
    }

    int ans = 0;

    // in the condensed graph we will process sink components first
    for(auto i: topo_order)
    {
        int mx = 0;
        for(auto j: condensed_graph[i])
        {
            mx = max(mx, condensed_coins[j]);
        }

        condensed_coins[i] += mx;

        ans = max(ans, condensed_coins[i]);
    }

    cout<<ans;

    return 0;
}