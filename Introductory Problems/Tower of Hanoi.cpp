#include<bits/stdc++.h>
#define int long long
using namespace std;

// to solve tower of hanoi
// first move n-1 disks from x to y using z
// now move the disk on x to z
// now move the n-1 disks on y to z using x
// if only one disk then directly move it to z from x

void tower_of_hanoi(vector<pair<int, int>> &moves, int n, int x, int y, int z)
{
    if(n==1)
    {
        moves.push_back({x, z});
        return ;
    }
    tower_of_hanoi(moves, n-1, x, z, y);
    moves.push_back({x, z});
    tower_of_hanoi(moves, n-1, y, x, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n;cin>>n;

    vector<pair<int, int>> moves;

    tower_of_hanoi(moves, n, 1, 2, 3);

    cout<<(int)moves.size()<<'\n';

    for(int e=0;e<(int)moves.size();e++)
    {
        cout<<moves[e].first<<" "<<moves[e].second<<'\n';
    }   

    return 0;
}
