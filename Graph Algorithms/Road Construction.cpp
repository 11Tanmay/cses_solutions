#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+1;

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

    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }

    int components=n;
    int max_size=1;

    for(int i=1;i<=m;i++)
    {
        int a, b;
        cin>>a>>b;

        if(find_parent(a)==find_parent(b))
        {
            cout<<components<<" "<<max_size<<'\n';
            continue;
        }
        else
        {
            unite(a, b);
            components--;
            max_size=max(max_size, sz[find_parent(a)]);

            cout<<components<<" "<<max_size<<'\n';
            
        }
    }

    return 0;
}