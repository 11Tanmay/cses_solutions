#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+1;

vector<int> graph[N];
vector<int> vis(N);

bool detect_cycle(vector<int> &cycle, int v,int p)
{
    vis[v]=1;
    cycle.push_back(v);

    for(auto e: graph[v])
    {
        if(e==p)
        {
            continue;
        }
        if(vis[e]==1)
        {
            cycle.push_back(e);
            return 1;
        }

        bool b=detect_cycle(cycle, e, v);

        if(b==1)
        {
            return 1;
        }
    }

    cycle.pop_back();
    return 0;
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

    vector<int> cycle;

    for(int e=1;e<=n;e++)
    {
        if(vis[e]==0&&detect_cycle(cycle, e, 0))
        {
            break;
        }
        cycle.clear();
    }

    if((int)cycle.size()==0)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {

        stack<int> s;

        reverse(cycle.begin(), cycle.end());

        s.push(cycle[0]);

        for(int e=1;e<cycle.size();e++)
        {
            s.push(cycle[e]);
            if(cycle[e]==cycle[0])
            {
                break;
            }
        }

        cout<<s.size()<<'\n';

        while(s.size()!=0)
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }

    return 0;
}
