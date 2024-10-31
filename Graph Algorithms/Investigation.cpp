#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// to solve this question we have to modify dijekstra algorithm a little bit
// now if dis[node] + edge < dis[child] this means that a shorter path exists
// to reach the node in this case we update all the other arrays routes, min_flights,
// max_flights with the use of node, otherwise if dis[node] + edge == dis[child]
// then we update the number of routes of the child with the number of 
// routes of the node and also we update if min_flights, max_flights of the child can be
// updated with the min_flights and the max_flights of the node, rest
// the code remains same as standard dijkestra.

const int N=1e5+1;
const int INF=1e15+1;
const int MOD=1e9+7;

vector<pair<int, int> > graph[N];
vector<int> dis(N, INF);
vector<int> vis(N, 0);
vector<int> routes(N, 0);
vector<int> min_flights(N, INF);
vector<int> max_flights(N, 0);
 
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
        int a, b, wt;
        cin>>a>>b>>wt;

        graph[a].push_back(make_pair(b, wt));
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dis[1]=0;
    routes[1]=1;
    min_flights[1]=0;
    max_flights[1]=0;
    pq.push(make_pair(0, 1));

    while(pq.size()!=0)
    {
        auto v = pq.top();
        pq.pop();

        int node = v.second;

        if(vis[node])
        {
            continue;
        }

        vis[node]=1;

        for(auto i: graph[node])
        {
            int child = i.first;
            int edge = i.second;

            if(dis[node] + edge < dis[child])
            {
                dis[child]=dis[node]+edge;
                routes[child]=routes[node];
                min_flights[child]=min_flights[node]+1;
                max_flights[child]=max_flights[node]+1;

                pq.push(make_pair(dis[child], child));
            }
            else if (dis[node] + edge == dis[child])
            {
                routes[child]=(routes[child]+routes[node])%MOD;
                min_flights[child]=min(min_flights[child], min_flights[node]+1);
                max_flights[child]=max(max_flights[child], max_flights[node]+1);
            }
        }
    }

    cout<<dis[n]<<" "<<routes[n]<<" "<<min_flights[n]<<" "<<max_flights[n];
 
    return 0;
}