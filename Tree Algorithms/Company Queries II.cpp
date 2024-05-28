#include <bits/stdc++.h>
#define int long long
using namespace std;

// raise both the vertices to same depth, if they are now
// same then it is the lca otherwise do a binary search 
// over the answer, check if the kth parent is same of not
// if it is then don't lift otherwise lift both the nodes,
// this way both the nodes will remain in the same subtree
// finally when the search ends immediate parent of both the
// nodes will be the answer.

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
    int n, q;
    cin>>n>>q;

    for(int e=2;e<=n;e++)
    {
        cin>>parent[e][0];

        tree[e].push_back(parent[e][0]);
        tree[parent[e][0]].push_back(e);
    }

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

    dfs(1, 0);
    
    while(q--)
    {
        int a, b;
        cin>>a>>b;

        cout<<lca(a, b)<<'\n';
    }

    return 0;
}
