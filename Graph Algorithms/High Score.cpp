#include <bits/stdc++.h>
#define int long long
using namespace std;

// bellman ford algorithm is used to find shortest paths 
// when our graph contains negative weights also, here but
// there is a catch when we need to minimize the cost to a
// particular destination, we also need to check whether
// a negative weight cycle lies in the path from source
// to the destination or not, it can be found out by checking
// whether it can be visited from starting node and whether it
// can be visited from the destination node in the reverse graph,
// this is needed to be found because then there is no minimum
// cost from starting to destination or it is -INFINITY.

const int N=2501;
const int INF=1e15+1;

vector<pair<pair<int, int>, int>> edges;
vector<int> graph[N];
vector<int> reverse_graph[N];
vector<int> vis(N, 0);
vector<int> reverse_vis(N, 0);
vector<int> dis(N, INF);

void dfs(int v)
{
    vis[v]=1;

    for(auto e: graph[v])
    {
        if(vis[e]==1)
        {
            continue;
        }

        dfs(e);
    }
}

void reverse_dfs(int v)
{
    reverse_vis[v]=1;

    for(auto e:reverse_graph[v])
    {
        if(reverse_vis[e]==1)
        {
            continue;
        }

        reverse_dfs(e);
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

    int flag=0;

    for(int e=0;e<m;e++)
    {
        int a, b, wt;
        cin>>a>>b>>wt;

        graph[a].push_back(b);

        reverse_graph[b].push_back(a);
        
        edges.push_back({{a, b}, -wt});

        if(wt<0)
        {
            flag=1;
        }
    }

    dfs(1);

    reverse_dfs(n);

    dis[1]=0;

    for(int e=0;e<n-1;e++)
    {
        for(auto edge:edges)
        {
            int source=edge.first.first;
            int dest=edge.first.second;
            int wt=edge.second;

            if(dis[source]!=INF)
            {
                dis[dest]=min(dis[dest], dis[source]+wt);
            }
        }
    }

    for(auto edge:edges)
    {
        int source=edge.first.first;
        int dest=edge.first.second;
        int wt=edge.second;

        if(dis[source]!=INF&&dis[dest]>dis[source]+wt&&vis[source]==1&&reverse_vis[source]==1)
        {
            cout<<-1;
            return 0;
        }
    }

    cout<<-dis[n];

    return 0;
}
