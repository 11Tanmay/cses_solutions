#include <bits/stdc++.h>
using namespace std;

// in this problem we are titling the floor length wise from right
// to left and here dp[length][mask] represents the state of the 
// column length where if ith bit of mask is set then it represents
// that the tile is occupied otherwise it is unoccupied. Now we go 
// from state (length, mask) to state (length-1, next_mask) where
// next_mask represents one of the next possible mask after tiling
// the current mask. Now we precompute each of these next possible masks
// for each of the mask. Now if in a mask the ith position is occupied
// then for sure the ith position in the next mask will be unoccupied
// now if the ith position is unoccupied then the ith position will be
// occupied if we position a horizontal tile and unoccupied if we position
// the tile vertically, in this case one of the adjacent position of the
// ith tile must also be unoccupied.

const int MOD = 1e9+7;

vector<vector<int> > dp(1001, vector<int> ((1<<10), -1));
vector<set<int> > next_masks((1<<10));

int n, m;

int solve(int length, int mask)
{
    if (length==0)
    {
        if(mask==0)
        {
            return 1;
        }
        return 0;
    }

    if(dp[length][mask]!=-1)
    {
        return dp[length][mask];
    }

    dp[length][mask] = 0;

    for (auto i: next_masks[mask])
    {
        dp[length][mask] = (dp[length][mask] + solve(length-1, i))%MOD;
    }

    return dp[length][mask];
}

void generate_masks(int mask, int curr_mask, int pos)
{
    if(pos == n)
    {
        next_masks[mask].insert(curr_mask);
        return ;
    }
    if(((curr_mask>>pos) & 1) == 1)
    {
        // if the ith is occupied in the current mask then it will be unoccupied in the
        // next mask (we can't place a tile).
        generate_masks(mask, curr_mask ^ (1<<pos), pos+1);
        return;
    }

    // if the ith position is unoccupied in the current mask then placing a tile horizontally
    // occupies the ith place in next mask.
    generate_masks(mask, (1<<pos)^curr_mask, pos+1);

    if(pos<n-1 && (((curr_mask>>(pos+1)) & 1) == 0))
    {
        // if the ith and i+1th position are unoccupied then we can place a tile vertically 
        // and leaving both ith and i+1th positions unoccupied.
        generate_masks(mask, curr_mask, pos+2);
    }
}

int32_t main() 
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    cin>>n>>m;

    for (int mask=0;mask<(1<<n);mask++)
    {
        generate_masks(mask, mask, 0);
    }

    cout<<solve(m, 0);

    return 0;
}
