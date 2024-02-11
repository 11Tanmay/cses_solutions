#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+1;

vector<int> graph[N];
vector<bool> vis(N);

void dfs(int v)
{
    vis[v]=1;

    for(auto e: graph[v])
    {
        if(vis[e]==1)
        {
            continue;
        }

        dfs(e);
    }
}

int32_t main()
{
    int n, m;
    cin>>n>>m;

    for(int e=0;e<m;e++)
    {
        int a, b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> cities;

    for(int e=1;e<=n;e++)
    {
        if(vis[e]==0)
        {
            cities.push_back(e);
            dfs(e);
        }
    }

    cout<<(int)cities.size()-1<<'\n';

    if((int)cities.size()>1)
    {
        for(int e=0;e<(int)cities.size()-1;e++)
        {
            cout<<cities[e]<<" "<<cities[e+1]<<'\n';
        }
    }
    return 0;
}