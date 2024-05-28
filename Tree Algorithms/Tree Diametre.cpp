#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+1;
int diametre=0;

vector<int> tree[N];

int dfs(int v, int p)
{
    int mx1=0;
    int mx2=0;

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        int depth=dfs(e, v);

        if(depth>=mx1)
        {
            mx2=mx1;
            mx1=depth;
        }
        else if(depth>=mx2)
        {
            mx2=depth;
        }
    }

    diametre=max(diametre, mx1+mx2);

    return mx1+1;
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

    int depth=dfs(1, 0);

    cout<<diametre;

    return 0;
}
