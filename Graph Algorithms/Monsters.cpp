#include <bits/stdc++.h>
#define int long long
using namespace std;

// to solve the problem first find out the minimum
// time a certain monster will take to reach a square
// by running a multisource bfs, then run a bfs from
// the starting position and then see if the time
// it took from the starting square to this square is
// less than it will take for a monster to reach here
// if it is then only we can move to this square, after
// reaching the destination print the path.

const int N=1001;

vector<string> graph(N);
vector<vector<int>> vis(N, vector<int> (N));
queue<pair<pair<int, int>, int>> monsters;
vector<vector<int>> min_monster_dis(N, vector<int> (N, N));

queue<pair<pair<int, int>, int>> person;
int startx, starty;
vector<vector<int>> path(N, vector<int> (N));

vector<int> dx={0, 1, 0, -1};
vector<int> dy={1, 0, -1, 0};

void flood_fill_monsters(int n, int m)
{
    if((int)monsters.size()==0)
    {
        return ;
    }

    vis[monsters.front().first.first][monsters.front().first.second]=1;

    while(monsters.size()!=0)
    {
        auto v=monsters.front();
        monsters.pop();

        min_monster_dis[v.first.first][v.first.second]=v.second;

        for(int e=0;e<4;e++)
        {
            int x=v.first.first+dx[e];
            int y=v.first.second+dy[e];

            if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&(graph[x][y]=='.'||graph[x][y]=='A'))
            {
                monsters.push({{x, y}, v.second+1});
                vis[x][y]=1;
            }
        }
    }
}

void flood_fill_person(int n, int m)
{
    for(int e=0;e<n;e++)
    {
        for(int f=0;f<m;f++)
        {
            vis[e][f]=0;
        }
    }

    vis[person.front().first.first][person.front().first.second]=1;

    while(person.size()!=0)
    {
        auto v=person.front();
        person.pop();

        if(v.first.first==0||v.first.second==0||v.first.first==n-1||v.first.second==m-1)
        {
            // print path
            cout<<"YES"<<'\n';

            vector<char> path_taken;

            while(v.first.first!=startx||v.first.second!=starty)
            {
                if(path[v.first.first][v.first.second]==0)
                {
                    path_taken.push_back('R');
                    v.first.second-=1;
                }
                else if(path[v.first.first][v.first.second]==1)
                {
                    path_taken.push_back('D');
                    v.first.first-=1;
                }
                else if(path[v.first.first][v.first.second]==2)
                {
                    path_taken.push_back('L');
                    v.first.second+=1;
                }
                else if(path[v.first.first][v.first.second]==3)
                {
                    path_taken.push_back('U');
                    v.first.first+=1;
                }
            }

            reverse(path_taken.begin(), path_taken.end());

            cout<<path_taken.size()<<'\n';

            for(auto e:path_taken)
            {
                cout<<e;
            }

            return ;
        }

        for(int e=0;e<4;e++)
        {
            int x=v.first.first+dx[e];
            int y=v.first.second+dy[e];

            if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&graph[x][y]=='.'&&v.second+1<min_monster_dis[x][y])
            {
                person.push({{x, y}, v.second+1});
                path[x][y]=e;
                vis[x][y]=1;
            } 
        }
    }

    cout<<"NO";
}

int32_t main()
{
    int n, m;
    cin>>n>>m;

    for(int e=0;e<n;e++)
    {
        cin>>graph[e];

        for(int f=0;f<m;f++)
        {
            if(graph[e][f]=='M')
            {
                monsters.push({{e, f}, 0});
            }
            if(graph[e][f]=='A')
            {
                startx=e;
                starty=f;
                person.push({{e, f}, 0});
            }
        }
    }

    // move the monsters
    flood_fill_monsters(n, m);

    // // move the person
    flood_fill_person(n, m);

    return 0;
}
