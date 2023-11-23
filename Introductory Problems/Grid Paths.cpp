#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
vector<vector<bool>> vis(7, vector<bool> (7, 0));
int paths;

bool valid(int x, int y)
{
    return x>=0&&x<7&&y>=0&&y<7;
}

// in the solve function if we can't go U,D but can go both L,R
// we return as it is unnecessay to expand those branches as
// expanding from those won't make us reach the final goal state,
// same in the state where we can't go L,R but can go both U,D
// expanding from these states won't make us reach the final goal state.

void solve(int n, int i, int j)
{
    if(n==48||(i==6&&j==0))
    {
        paths+=(n==48&&i==6&&j==0)?1:0;
        return ;
    }

    if((!valid(i+1, j)||vis[i+1][j])&&(!valid(i-1, j)||vis[i-1][j]))
    {
        if(valid(i, j+1)&&!vis[i][j+1]&&valid(i, j-1)&&!vis[i][j-1])
        {
            return ;
        }
    }
    if((!valid(i, j+1)||vis[i][j+1])&&(!valid(i, j-1)||vis[i][j-1]))
    {
        if(valid(i+1, j)&&!vis[i+1][j]&&valid(i-1, j)&&!vis[i-1][j])
        {
            return ;
        }
    }

    vis[i][j]=1;
    if((s[n]=='?'||s[n]=='U')&&valid(i-1, j)&&!vis[i-1][j])
    {
        solve(n+1, i-1, j);
    }
    if((s[n]=='?'||s[n]=='D')&&valid(i+1, j)&&!vis[i+1][j])
    {
        solve(n+1, i+1, j);
    }
    if((s[n]=='?'||s[n]=='L')&&valid(i, j-1)&&!vis[i][j-1])
    {
        solve(n+1, i, j-1);
    }
    if((s[n]=='?'||s[n]=='R')&&valid(i, j+1)&&!vis[i][j+1])
    {
        solve(n+1, i, j+1);
    }
    vis[i][j]=0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;

    solve(0, 0, 0);

    cout<<paths;

    return 0;
}
