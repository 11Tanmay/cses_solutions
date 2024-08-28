#include <bits/stdc++.h>
#define int long long
using namespace std;

// the number of ways to reach a particular node i will be the sum of ways 
// to reach its parent nodes, topologically sort the graph then calculate 
// ways in this order the ways for each node.

const int N=1e5+1;
const int MOD=1e9+7;

vector<int> graph[N];
vector<int> r_graph[N];
vector<int> vis(N, 0);
vector<int> order;
vector<int> ways(N, 0);

void topo_sort(int v)
{
    vis[v]=1;

    for(int i: graph[v])
    {
        if(vis[i]==1)
        {
            continue;
        }

        topo_sort(i);
    }

    order.push_back(v);
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;

        graph[a].push_back(b);
        r_graph[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            topo_sort(i);
        }
    }

    reverse(order.begin(), order.end());

    ways[1]=1;

    for(int i=0;i<n;i++)
    {
        for(int j: r_graph[order[i]])
        {
            ways[order[i]]=(ways[order[i]]+ways[j])%MOD;
        }
    }

    cout<<ways[n];

    return 0;
}