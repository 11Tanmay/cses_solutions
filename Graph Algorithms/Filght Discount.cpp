#include <bits/stdc++.h>
#define int long long
using namespace std;

// state dijekstra, lets say the person is at state u,1 
// so he can go to another state v,1 or v,0(by using a ticket)
// or if he is at a state u,0 then he can go to state v,0
// only now running dijekstra over this will return the 
// minimum cost of travel by using the ticket optimally.

const int N=1e5+1;
const int INF=1e15+1;

vector<pair<int, int>> graph[N];
vector<vector<int>> vis(N, vector<int> (2, 0));
vector<vector<int>> dis(N, vector<int> (2, INF));

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

    dis[1][1]=0;

    set<pair<int, pair<int, int>>> q;

    q.insert({0, {1, 1}});

    while(q.size()!=0)
    {
        auto v=*q.begin();
        q.erase(q.begin());

        int vx=v.second.first;
        int state=v.second.second;

        if(vis[vx][state]==1)
        {
            continue;
        }

        vis[vx][state]=1;

        for(auto e:graph[vx])
        {
            int x=e.first;
            int wt=e.second;

            if(state==0)
            {
                if(vis[x][state]==0&&dis[vx][state]+wt<dis[x][state])
                {
                    dis[x][state]=dis[vx][state]+wt;
                    q.insert({dis[x][state], {x, state}});
                }
            }
            else if(state==1)
            {
                if(vis[x][state]==0&&dis[vx][state]+wt<dis[x][state])
                {
                    dis[x][state]=dis[vx][state]+wt;
                    q.insert({dis[x][state], {x, state}});
                }
                if(vis[x][1-state]==0&&dis[vx][state]+wt/2<dis[x][1-state])
                {
                    dis[x][1-state]=dis[vx][state]+wt/2;
                    q.insert({dis[x][1-state], {x, 1-state}});
                }
            }
        }
    }

    cout<<min(dis[n][0], dis[n][1]);

    return 0;
}
