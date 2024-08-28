#include <bits/stdc++.h>
#define int long long
using namespace std;

// to find strongly connected components in a graph dfs the reverse graph in the 
// topological order of the original graph, now all the nodes covered in the same
// dfs call belong to the same strongly connected component.

const int N=1e5+1;

vector<int> graph[N];
vector<int> r_graph[N];
vector<int> order;
vector<int> vis(N, 0);
vector<int> r_vis(N, 0);

void find_order(int v)
{
    vis[v]=1;

    for(auto i: graph[v])
    {
        if(vis[i]==1)
        {
            continue;
        }

        find_order(i);
    }

    order.push_back(v);
}

void dfs(int v)
{
    r_vis[v]=1;

    for(int i: r_graph[v])
    {
        if(r_vis[i]==1)
        {
            continue;
        }

        dfs(i);
    }
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
        if(vis[i]==1)
        {
            continue;
        }
        find_order(i);
    }

    reverse(order.begin(), order.end());

    vector<int> cities;

    for(int i=0;i<n;i++)
    {
        if(r_vis[order[i]]==1)
        {
            continue;
        }

        dfs(order[i]);
        cities.push_back(order[i]);
    }

    reverse(cities.begin(), cities.end());

    if(cities.size()==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO"<<'\n';

        cout<<cities[0]<<" "<<cities[1];
    }

    return 0;
}