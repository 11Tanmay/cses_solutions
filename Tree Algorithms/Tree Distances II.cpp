#include <bits/stdc++.h>
#define int long long
using namespace std;

// tree rerooting, dis[v]=dis[p]-dis[v]-subtree[v]+total_nodes-subtree[v]+dis[v]

const int N=2*1e5+1;

vector<int> tree[N];
vector<int> subtree_dis(N, 0);
vector<int> subtree(N, 0);
vector<int> dis(N, 0);

void calculate_sub(int v, int p)
{
    subtree[v]+=1;

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        calculate_sub(e, v);

        subtree[v]+=subtree[e];
        subtree_dis[v]+=(subtree_dis[e]+subtree[e]);
    }
}

void calculate_dis(int v, int p)
{
    if(v==1)
    {
        dis[v]=subtree_dis[v];
    }
    else
    {
        dis[v]=dis[p]+subtree[1]-2*subtree[v];
    }

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        calculate_dis(e, v);
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

    calculate_sub(1, 0);

    calculate_dis(1, 0);

    for(int e=1;e<=n;e++)
    {
        cout<<dis[e]<<" ";
    }

    return 0;
}
