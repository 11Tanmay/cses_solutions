// #include <bits/stdc++.h>
#include "stdc++.h"
#define int long long
using namespace std;

// in this question we solve it like normal knights tour
// problem with an added heuristic for jumping to next
// state that involves going to state where least 
// branching(or next states) occur, this optimizes
// the problem significantly.

const int N=9;

vector<vector<int> > vis(N, vector<int> (N, 0));
int moves=0;
int dx[] = {1, 1, 2, 2,-1,-1,-2,-2};
int dy[] = {2,-2, 1,-1, 2,-2, 1,-1};

int get_heuristic(int x, int y)
{
    int count = 0;

    for(int i=0;i<8;i++)
    {
        int vx = x + dx[i];
        int vy = y + dy[i];

        if(vx>0&&vx<=8&&vy>0&&vy<=8&&vis[vx][vy]==0)
        {
            count++;
        }
    }

    return count;
}

bool solve(int x, int y)
{
    moves++;
    vis[x][y]=moves;
    if(moves==64)
    {
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                cout<<vis[j][i]<<" ";
            }

            cout<<'\n';
        }

        return 1;
    }

    vector<pair<int, pair<int, int> > > heuristic_order;

    for(int i=0;i<8;i++)
    {
        int vx=x+dx[i];
        int vy=y+dy[i];

        if(vx>0&&vx<=8&&vy>0&&vy<=8&&vis[vx][vy]==0)
        {
            heuristic_order.push_back(make_pair(get_heuristic(vx, vy), make_pair(vx, vy)));
        }
    }

    sort(heuristic_order.begin(), heuristic_order.end());

    for(auto i: heuristic_order)
    {
        int vx=i.second.first;
        int vy=i.second.second;
        if(solve(vx, vy))
        {
            return 1;
        }
    }

    moves--;
    vis[x][y]=0;
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin>>x>>y;

    bool b = solve(x, y);

    return 0;
}