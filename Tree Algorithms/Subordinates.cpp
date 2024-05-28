#include <bits/stdc++.h>
#define int long long
using namespace std;

// dfs and normal tree dp question

const int N=2*1e5+1;

vector<int> tree[N];
vector<int> subordinates(N, 1);

void dfs(int v, int p)
{
    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dfs(e, v);

        subordinates[v]+=subordinates[e];
    }
}

int32_t main()
{
    int n;cin>>n;

    for(int e=2;e<=n;e++)
    {
        int i;cin>>i;

        tree[e].push_back(i);
        tree[i].push_back(e);
    }

    dfs(1, 0);

    for(int e=1;e<=n;e++)
    {
        cout<<subordinates[e]-1<<" ";
    }

    return 0;
}
