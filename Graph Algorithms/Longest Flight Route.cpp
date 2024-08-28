#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+1;

vector<int> graph[N];
vector<int> order;
vector<int> vis(N, 0);
vector<int> dis(N, -1);
vector<int> nxt(N, -1);

void topo_sort(int v)
{
    vis[v]=2;

    for(auto i: graph[v])
    {
        if(vis[i]==1)
        {
            continue;
        }

        if(vis[i]==2)
        {
            return ;
        }

        topo_sort(i);
    }

    order.push_back(v);

    vis[v]=1;
}
 
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
        int a, b;
        cin>>a>>b;

        graph[a].push_back(b);
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            topo_sort(i);
        }
    }

    dis[n]=1;

    for(int i=0;i<n;i++)
    {
        for(int j: graph[order[i]])
        {
            if(dis[j]!=-1&&dis[order[i]]<=dis[j]+1)
            {
                dis[order[i]]=dis[j]+1;
                nxt[order[i]]=j;
            }
        }
    }

    if(dis[1]==-1)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        cout<<dis[1]<<'\n';
        for(int i=1;i!=-1;i=nxt[i])
        {
            cout<<i<<" ";
        }
    }

    return 0;
}