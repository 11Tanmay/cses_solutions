#include <bits/stdc++.h>
#define int long long
using namespace std;

// this question is a generalized version of dijekstra only here we have to store
// for each node the k min distances from the source node, for this we check 
// whether dis[i][k-1] (the kth minimum dis to it can be relaxed or not if not we
// move on else update the dis[i][k-1] with new cost, next we sort the dis[i] array
// to arrange the k costs in ascending order so that dis[i][k-1] is again the worst
// of all the k costs.

const int INF=1e15+1;
const int N=1e5+1;
const int K=11;

vector<pair<int, int>> graph[N];
vector<vector<int>> dis(N, vector<int> (K, INF));
 
int32_t main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n, m, k;
    cin>>n>>m>>k;

    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        graph[a].push_back({b, c});
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    >   pq;

    dis[1][0]=0;
    pq.push({0, 1});

    while(pq.size()!=0)
    {
        auto v=pq.top();
        pq.pop();

        int vx=v.second;
        int d=v.first;

        if(dis[vx][k-1]<d)
        {
            continue;
        }

        for(auto i: graph[vx])
        {
            int x=i.first;
            int wt=i.second;
            if(dis[x][k-1]>d+wt)
            {
                dis[x][k-1]=d+wt;
                pq.push({dis[x][k-1], x});
                sort(dis[x].begin(), dis[x].end());
            }
        }
    }

    for(int i=0;i<k;i++)
    {
        cout<<dis[n][i]<<" ";
    }

    return 0;
}