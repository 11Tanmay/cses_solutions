#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// this question is based on the max flow problem, we
// find augmented paths via bfs on the graph from source
// to the sink, if found we find the bottle-neck capacity,
// this is the curr_flow in the path, next we update the 
// capacity of the edges in the path by subtracting the 
// curr_flow and add capacity to the reverse edges of this
// path equal to the curr_flow, this is don because then
// we will not be able to reverse flow and the algorithm
// would miss certain potential flow configurations.

const int N=501;
const int INF=1e15+1;

vector<vector<int> > capacity(N, vector<int> (N, 0));
vector<int> graph[N];
int parent[N];

bool reacheable(int n)
{
    queue<int> q;
    q.push(1);
    parent[1]=0;

    while(q.size()!=0)
    {
        auto v = q.front();
        q.pop();
        
        for(auto child: graph[v])
        {
            if(parent[child]!=-1||capacity[v][child]<=0)
            {
                continue;
            }

            parent[child]=v;
            q.push(child);
        }
    }

    return parent[n]!=-1;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        graph[a].push_back(b);
        graph[b].push_back(a);
        capacity[a][b]+=c;
    }

    int max_flow = 0;
    memset(parent, -1, sizeof(parent));

    while(reacheable(n))
    {
        int node = n;

        int current_flow = INF;

        while(node!=1)
        {
            current_flow = min(current_flow, capacity[parent[node]][node]);
            node=parent[node];
        }

        max_flow = max_flow + current_flow;

        node = n;

        while(parent[node]!=0)
        {
            capacity[parent[node]][node]-=current_flow;
            capacity[node][parent[node]]+=current_flow;
            node=parent[node];
        }

        memset(parent, -1, sizeof(parent));
    }

    cout<<max_flow;

    return 0;
}