#include<bits/stdc++.h>
using namespace std;

// this problem is solved by bfs.

// string concatenation is O(N^2) where N is the 
// sum of lengths of string1 and string 2 that are
// being concatenated.
 
const int N=1e3+1;
 
int n, m;
 
vector<int> dx={0, 1, 0, -1};
vector<int> dy={1, 0, -1, 0};
 
char labyrinth[N][N];
 
vector<char> path;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    cin>>n>>m;
 
    int i=0;
    int j=0;
 
    for(int e=0;e<n;e++)
    {
        for(int f=0;f<m;f++)
        {
            cin>>labyrinth[e][f];
            if(labyrinth[e][f]=='A')
            {
                i=e;
                j=f;
            }
        }
    }
    
    queue<pair<int, int>> q;
 
    q.push({i, j});
 
    while(!q.empty())
    {
        pair<int, int> v=q.front();
        q.pop();
 
        for(int e=0;e<4;e++)
        {
            int x=v.first+dx[e];
            int y=v.second+dy[e];
 
            if(x<0||x>=n||y<0||y>=m)
            {
                continue;
            }
 
            if(!(labyrinth[x][y]=='.'||labyrinth[x][y]=='B'))
            {
                continue;
            }
 
            q.push({x, y});
 
            int is_b=labyrinth[x][y]=='B';
 
            labyrinth[x][y]=e==0?'R':e==1?'D':e==2?'L':'U';
 
            if(is_b)
            {
                while(labyrinth[x][y]!='A')
                {
                    path.push_back(labyrinth[x][y]);
 
                    int i=labyrinth[x][y]=='R'?0:labyrinth[x][y]=='D'?1:labyrinth[x][y]=='L'?2:3;
 
                    x-=dx[i];
                    y-=dy[i];             
                }
 
                reverse(path.begin(), path.end());
 
                cout<<"YES"<<'\n'<<(int)path.size()<<'\n';

                for(auto e: path)
                {
                    cout<<e;
                }
 
                return 0;
            }
        }
    }
 
    cout<<"NO";
 
    return 0;
}