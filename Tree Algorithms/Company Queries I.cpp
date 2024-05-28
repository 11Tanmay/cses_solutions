#include <bits/stdc++.h>
#define int long long
using namespace std;

// binary lifting is used to find the kth parent.

const int N=2*1e5+1;

vector<vector<int>> parent(N, vector<int> (log2(N)+1, -1));

int find_kth(int x, int k)
{
    for(int e=30;e>=0;e--)
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

int32_t main()
{
    int n, q;
    cin>>n>>q;

    for(int e=2;e<=n;e++)
    {
        cin>>parent[e][0];
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
    
    while(q--)
    {
        int x, k;
        cin>>x>>k;

        cout<<find_kth(x, k)<<'\n';
    }

    return 0;
}
