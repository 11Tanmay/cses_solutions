#include <bits/stdc++.h>
#define int long long
using namespace std;

// distance between two nodes in a tree is equal to 
// dis[a]+dis[b]-2*dis[lca(a, b)]

const int N=2*1e5+1;

vector<vector<int>> parent(N, vector<int> (log2(N)+1, -1));
vector<int> tree[N];
vector<int> depth(N, 0);

int find_kth(int x, int k)
{
    for(int e=log2(N);e>=0;e--)
    {
        if(x==-1)
        {
            continue;
        }
        if((k>>e)&1)
        {
            x=parent[x][e];
        }
    }

    return x;
}

int lca(int a, int b)
{
    if(depth[a]<depth[b])
    {
        swap(a, b);
    }

    a=find_kth(a, depth[a]-depth[b]);

    if(a==b)
    {
        return a;
    }

    for(int e=log2(N);e>=0;e--)
    {
        int x=parent[a][e];
        int y=parent[b][e];
        if(x==y)
        {
            continue;
        }
        a=x;
        b=y;
    }

    return parent[a][0];
}

void dfs(int v, int p)
{
    depth[v]=depth[p]+1;

    if(v!=1)
    {
        parent[v][0]=p;
    }

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dfs(e, v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   

    int n, q;
    cin>>n>>q;

    for(int e=0;e<n-1;e++)
    {
        int a, b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1, 0);

    for(int e=1;e<=log2(n);e++)
    {
        for(int f=1;f<=n;f++)
        {
            if(parent[f][e-1]==-1)
            {
                continue;
            }
            parent[f][e]=parent[parent[f][e-1]][e-1];
        }
    }
    
    while(q--)
    {
        int a, b;
        cin>>a>>b;

        cout<<depth[a]+depth[b]-2*depth[lca(a, b)]<<'\n';
    }

    return 0;
}
