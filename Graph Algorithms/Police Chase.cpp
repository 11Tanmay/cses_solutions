#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// this question is the min cut problem, here
// first find the max flow in the graph, now
// start bfs from the source and mark all the
// node that can be visited. Next if there exists
// an edge between a node that can be visited and
// a node that cannot be visited then this is
// the edge to be removed and a part of the min
// cut edges.

const int N=501;
const int INF=1e15+1;

vector<vector<int> > capacity(N, vector<int> (N));
vector<vector<int> > edges(N, vector<int> (N));
int parent[N];

bool reacheable(int n)
{
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(1);
    parent[1]=0;

    while(q.size()!=0)
    {
        auto node = q.front();
        q.pop();

        for(int i=1;i<=n;i++)
        {
            if(parent[i]!=-1||capacity[node][i]<=0)
            {
                continue;
            }

            parent[i]=node;
            q.push(i);
        }
    }

    return parent[n]!=-1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;

        capacity[a][b]++;
        capacity[b][a]++;

        edges[a][b]=1;
        edges[b][a]=1;
    }

    while(reacheable(n))
    {
        int curr_flow=INF;

        int node = n;

        while(node!=1)
        {
            curr_flow = min(curr_flow, capacity[parent[node]][node]);
            node=parent[node];
        }

        node = n;

        while(node!=1)
        {
            capacity[parent[node]][node]-=curr_flow;
            capacity[node][parent[node]]+=curr_flow;
            node=parent[node];
        }
    }

    vector<pair<int, int> > closing_streets;

    reacheable(n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(parent[i]!=-1&&parent[j]==-1&&edges[i][j])
            {
                closing_streets.push_back(make_pair(i, j));
            }
        }
    }

    cout<<(int)closing_streets.size()<<'\n';
    for(auto street: closing_streets)
    {
        cout<<street.first<<" "<<street.second<<'\n';
    }

    return 0;
}