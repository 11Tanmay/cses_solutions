#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector<vector<int>> &board, int e, int f)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(i==e&&j==f)
            {
                continue;
            }
            if(board[i][j]==2)
            {
                if(i==e||j==f)
                {
                    return 0;
                }
                if(abs(e-i)==abs(f-j))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void solve(vector<vector<int>> &board, int &ways, int i)
{
    if(i==8)
    {
        ways++;

        return ;
    }

    for(int e=0;e<8;e++)
    {
        if(board[i][e]==0&&check(board, i, e))
        {
            board[i][e]=2;
            solve(board, ways, i+1);
            board[i][e]=0;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    vector<vector<int>> board(8, vector<int> (8, 0));

    for(int e=0;e<8;e++)
    {
        for(int f=0;f<8;f++)
        {
            char c;cin>>c;

            if(c=='.')
            {
                board[e][f]=0;
            }
            else if(c=='*')
            {
                board[e][f]=1;
            }
        }
    }

    int ways=0;

    solve(board, ways, 0);

    cout<<ways;

    return 0;
}
