#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+1;

vector<int> tree[N];
vector<int> subtree(N, 0);

void dfs(int n, int &centroid, int v, int p)
{
    bool b=1;

    for(auto e: tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dfs(n, centroid, e, v);

        if(subtree[e]>n/2)
        {
            b=0;
        }

        subtree[v]+=subtree[e];
    }

    subtree[v]+=1;

    if(n-subtree[v]>n/2)
    {
        b=0;
    }

    if(b==1)
    {
        centroid=v;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;

    for(int e=0;e<n-1;e++)
    {
        int a, b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int centroid=0;

    dfs(n, centroid, 1, 0);

    cout<<centroid;

    return 0;
}
