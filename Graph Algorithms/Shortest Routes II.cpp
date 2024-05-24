#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=501;
const int INF=1e15+1;

vector<vector<int>> dis(N, vector<int> (N, INF));

int32_t main()
{
    int n, m, q;
    cin>>n>>m>>q;

    for(int e=0;e<m;e++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        dis[a][b]=min(dis[a][b], c);
        dis[b][a]=min(dis[b][a], c);
    }

    for(int k=1;k<=n;k++)
    {
        for(int e=1;e<=n;e++)
        {
            for(int f=1;f<=n;f++)
            {
                if(e==f)
                {
                    dis[e][f]=0;
                    continue;
                }
                else
                {
                    dis[e][f]=min(dis[e][f], dis[e][k]+dis[k][f]);
                }
            }
        }
    }

    while(q--)
    {
        int a, b;
        cin>>a>>b;

        if(dis[a][b]==INF)
        {
            cout<<-1<<'\n';
        }
        else
        {
            cout<<dis[a][b]<<'\n';
        }
    }

    return 0;
}
