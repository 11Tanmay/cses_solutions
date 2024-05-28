#include <bits/stdc++.h>
#define int long long
using namespace std;

// the vertices farthest from any given vertex in a tree
// are the endpoints of the diametre of the tree.

const int N=2*1e5+1;

vector<int> tree[N];

void dfs(vector<int> &dis, int v, int p)
{
    dis[v]=dis[p]+1;

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dfs(dis, e, v);
    }
}

int32_t main()
{
    int n;cin>>n;

    for(int e=0;e<n-1;e++)
    {
        int a, b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> dis_root(n, 0);
    vector<int> dis_e1(n, 0);
    vector<int> dis_e2(n, 0);

    dfs(dis_root, 1, 0);

    int e1, mx1=0;

    for(int e=1;e<=n;e++)
    {
        if(mx1<dis_root[e])
        {
            e1=e;
            mx1=dis_root[e];
        }
    }

    dfs(dis_e1, e1, 0);

    int e2, mx2=0;

    for(int e=1;e<=n;e++)
    {
        if(mx2<dis_e1[e])
        {
            e2=e;
            mx2=dis_e1[e];
        }
    }
    
    dfs(dis_e2, e2, 0);

    for(int e=1;e<=n;e++)
    {
        cout<<max(dis_e1[e], dis_e2[e])-1<<" ";
    }

    return 0;
}
