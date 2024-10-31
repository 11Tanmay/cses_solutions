#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// in this question we use 2-SAT problem to find the solution
// the inputs can be framed as (x1 or x2) and (x3 or x4) ...
// (xi or xi+1) we have to find a solution for this, for this
// xi or xi+1 to be true we create an implication edges that
// if not xi then xi+1, if not xi+1 then xi here the nodes are
// xi, not xi, xi+1, not xi+1, and the edges form a directed graph
// we next find the sscs in the graph and then try to assign values
// to the sscs in topological order to avoid any conflicts, nodes
// in the same sscs are mutually dependent, if xi and not xi are in
// the same ssc this means both are true which is impossible so
// then no solution exists to the problem, here we represent xi with 
// xi and not xi with node xi+n.

const int N=200020;

vector<int> graph[N];
vector<int> reverse_graph[N];
vector<int> topo_order;
vector<int> component(N, 0);
vector<int> members[N];
vector<int> assignment(N, -1);
bool vis[N];

void dfs(int node)
{
    vis[node]=1;

    for(auto child: graph[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }

    topo_order.push_back(node);
}

void dfs_reverse(int node, int ssc)
{
    vis[node]=1;
    component[node]=ssc;
    members[ssc].push_back(node);

    for(auto child: reverse_graph[node])
    {
        if(!vis[child])
        {
            dfs_reverse(child, ssc);
        }
    }
}
 
int32_t main() 
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
 
    int m, n;
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        char c1, c2;
        int x1, x2;
        
        cin>>c1>>x1>>c2>>x2;

        x1--;
        x2--;

        int b1 = c1 == '+' ? 1 : 0;
        int b2 = c2 == '+' ? 1 : 0;

        graph[n * (1 - b1) + x1].push_back(n * b2 + x2);
        reverse_graph[n * b2 + x2].push_back(n * (1 - b1) + x1);
        graph[n * (1 - b2) + x2].push_back(n * b1 + x1);
        reverse_graph[n * b1 + x1].push_back(n * (1 - b2) + x2);
    }

    memset(vis, 0 , sizeof(vis));
    for(int i=0;i<2*n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    reverse(topo_order.begin(), topo_order.end());  // topological order is the reverse of array found after the dfs

    memset(vis, 0, sizeof(vis));
    int ssc=0;
    for(auto i: topo_order)
    {
        if(!vis[i])
        {
            dfs_reverse(i, ssc++);
        }
    }

    vector<char> ans(n);
    for(int i=0;i<n;i++)
    {
        if(component[i]==component[i+n])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    memset(vis, 0, sizeof(vis));

    for(auto i: topo_order)
    {
        if(vis[component[i]]==0)
        {
            vis[component[i]]=1;
            for(auto j: members[component[i]])
            {
                if(assignment[j]==-1&&assignment[(j+n)%(2*n)]==-1)
                {
                    assignment[j]=1;
                    assignment[(j+n)%(2*n)]=0;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<(assignment[i]==1?'+':'-')<<" ";
    }
 
    return 0;
}