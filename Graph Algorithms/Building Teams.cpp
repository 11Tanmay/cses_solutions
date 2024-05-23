#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+1;

vector<int> graph[N];
vector<int> vis(N);

// check whether the graph is bipartite or not!
// for this color the vertex then go to its children
// if any one of its neighbours have the same color
// then it is not possible to form a bipartite graph
// else recur for the neighbour.

int make_teams(int v, int color)
{
    vis[v]=color;

    int b=1;

    for(auto e:graph[v])
    {
        if(vis[e]!=-1)
        {
            if(vis[e]==color)
            {
                return 0;
            }
            continue;
        }

        b=b&make_teams(e, 1-color);
    }

    return b;
}

int32_t main()
{
    int n, m;
    cin>>n>>m;

    for(int e=0;e<m;e++)
    {
        int a, b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int e=1;e<=n;e++)
    {
        vis[e]=-1;
    }

    int b=1;

    for(int e=1;e<=n;e++)
    {
        if(vis[e]==-1)
        {
            b=b&make_teams(e, 0);
        }
    }

    if(b)
    {
        for(int e=1;e<=n;e++)
        {
            cout<<vis[e]+1<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }

    return 0;
}
