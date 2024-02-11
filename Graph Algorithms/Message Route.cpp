#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+1;
const int INF=1e15+1;

vector<int> graph[N];
vector<int> dis(N, INF);
vector<bool> vis(N);
vector<int> parent(N);

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

    set<pair<int, int>> q;

    vector<int> path;

    dis[1]=0;
    q.insert({dis[1], 1});

    while(q.size()!=0)
    {
        auto v=*q.begin();
        q.erase(q.begin());

        int vx=v.second;

        if(vis[vx]==1)
        {
            continue;
        }

        if(vx==n)
        {
            while(vx!=0)
            {
                path.push_back(vx);
                vx=parent[vx];
            }

            reverse(path.begin(), path.end());
            break;
        }

        vis[vx]=1;

        for(auto e:graph[vx])
        {
            if(vis[e]==1)
            {
                continue;
            }

            if(dis[vx]+1<dis[e])
            {
                dis[e]=dis[vx]+1;
                parent[e]=vx;
                q.insert({dis[e], e});
            }
        }
    }

    if(dis[n]==INF)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        cout<<dis[n]+1<<'\n';

        for(auto e:path)
        {
            cout<<e<<" ";
        }
    }
    return 0;
}