#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// so in this question first whether a negative cycle exists or not
// was detected using bellman ford algorithm that relaxes all the 
// edges n-1 times to find the shortest path and if the edges can 
// can be relaxed one more time then there exists a negative cycle in 
// the graph now to print the cycle we store the parent of each node
// from which a particular node was relaxed. Here it is not necessary that
// the edge that was relaxed is a part of the negative cycle. so we back track
// to the a node that is start of the cycle. Once we reach there we 
// print the cycle that this node is a part of this is the negative cycle.
 
const int N=2501;
const int INF=1e15+1;
 
vector<pair<int, int> > graph[N];
vector<int> dis(N, INF);
vector<int> parent(N, 1);
 
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
 
    dis[1]=0;
 
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(auto e: graph[j])
            {
                if(dis[j] + e.second < dis[e.first])
                {
                    parent[e.first]=j;
                    dis[e.first] = dis[j] + e.second;
                }
            }
        }
    }
 
    for (int j = 1; j <= n; j++)
    {
        for (auto e : graph[j])
        {
            if (dis[j] + e.second < dis[e.first])
            {
                parent[e.first]=j;
                cout<<"YES"<<'\n';
 
                vector<int> cycle;
                int x = j;  

                set<int> s;

                // finding a node that is a part of the cycle.
                while(s.find(x)==s.end())
                {
                    s.insert(x);
                    x=parent[x];
                }
 
                int start = x;  
                cycle.push_back(start);
                
                for (int v = parent[start]; v != start; v = parent[v]) {
                    cycle.push_back(v);
                }
                cycle.push_back(start);
                
                reverse(cycle.begin(), cycle.end());
                for (auto v : cycle) {
                    cout << v << " ";
                }
 
 
                return 0;
            }
        }
    }
 
    cout<<"NO";
 
    return 0;
}