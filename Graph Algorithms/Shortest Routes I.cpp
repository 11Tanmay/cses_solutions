#include <bits/stdc++.h>
#define int long long
using namespace std;

// dijekstra algorithm-relax the vertices then
// in the next step choose the vertex with lowest
// distance and use it to relax other vertices,
// mark all the vertices that have been used to
// relax as visited and do not use them again.

const int N=1e5+1;
const int INF=1e15+1;

vector<pair<int, int>> graph[N];
vector<int> vis(N);
vector<int> dis(N, INF);

int32_t main()
{
    int n, m;
    cin>>n>>m;

    for(int e=0;e<m;e++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        graph[a].push_back({b, c});
    }

    dis[1]=0;

    set<pair<int, int>> q;

    q.insert({0, 1});

    while(q.size()!=0)
    {
        auto v=*q.begin();
        q.erase(q.begin());

        int x=v.second;

        if(vis[x]==1)
        {
            continue;
        }

        vis[x]=1;

        for(auto e:graph[x])
        {
            int vx=e.first;
            int wt=e.second;

            if(vis[vx]==0&&dis[x]+wt<dis[vx])
            {
                dis[vx]=dis[x]+wt;
                q.insert({dis[vx], vx});
            }
        }
    }

    for(int e=1;e<=n;e++)
    {
        cout<<dis[e]<<" ";
    }

    return 0;
}
