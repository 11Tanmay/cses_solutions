#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

void bfs(vector<vector<bool>> &building, int i, int j)
{
    queue<pair<int, int>> q;

    q.push({i, j});
    building[i][j]=0;

    while(q.size()!=0)
    {
        auto v=q.front();
        q.pop();

        for(int e=0;e<4;e++)
        {
            int x=v.first+dx[e];
            int y=v.second+dy[e];

            if(x>=0&&x<(int)building.size()&&y>=0&&y<(int)building[0].size()&&building[x][y]==1)
            {
                q.push({x, y});
                building[x][y]=0;
            }
        }
    }

    return ;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    vector<vector<bool>> building(n, vector<bool> (m, 0));

    for(int e=0;e<n;e++)
    {
        for(int f=0;f<m;f++)
        {
            char c;cin>>c;

            if(c=='.')
            {
                building[e][f]=1;
            }
        }
    }

    int rooms=0;

    for(int e=0;e<n;e++)
    {
        for(int f=0;f<m;f++)
        {
            if(building[e][f]==1)
            {
                rooms++;
                bfs(building, e, f);
            }
        }
    }

    cout<<rooms;

    return 0;
}
