#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int N=100001;
 
vector<int> graph[N];
vector<int> vis(N, 0);
vector<int> cycle;
 
bool dfs(vector<int> &cycle, int v)
{
    vis[v]=2;

    cycle.push_back(v);

    for(auto i: graph[v])
    {
        if(vis[i]==1)
        {
            continue;
        }
        else if(vis[i]==2)
        {
            cycle.push_back(i);

            return 1;
        }
        else if(vis[i]==0)
        {
            bool b=dfs(cycle, i);

            if(b)
            {
                return 1;
            }
        }
    }

    cycle.pop_back();

    vis[v]=1;

    return 0;
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
 
    int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;

        graph[a].push_back(b);
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            bool b=dfs(cycle, i);
            if(b)
            {
                reverse(cycle.begin(), cycle.end());

                while(cycle[(int)cycle.size()-1]!=cycle[0])
                {
                    cycle.pop_back();
                }

                cout<<(int)cycle.size()<<'\n';

                reverse(cycle.begin(), cycle.end());

                for(auto i: cycle)
                {
                    cout<<i<<" ";
                }

                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";
 
    return 0;
}