#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+1;

vector<vector<int>> roads;
vector<int> parent(N);
vector<int> sz(N, 1);

int find_parent(int v)
{
    if(parent[v]==v)
    {
        return v;
    }

    return parent[v]=find_parent(parent[v]);
}

void unite(int x, int y)
{
    x=find_parent(x);
    y=find_parent(y);

    if(sz[x]<sz[y])
    {
        swap(x, y);
    }

    parent[y]=x;
    sz[x]+=sz[y];
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n, m;
    cin>>n>>m;

    for(int e=0;e<m;e++)
    {
        int a, b, wt;
        cin>>a>>b>>wt;

        roads.push_back({wt, a, b});
    }

    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }

    sort(roads.begin(), roads.end());

    int cost=0;

    for(auto i: roads)
    {
        if(find_parent(i[1])==find_parent(i[2]))
        {
            continue;
        }

        unite(i[1], i[2]);

        cost+=i[0];
    }

    if(sz[find_parent(1)]!=n)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        cout<<cost;
    }

    return 0;
}