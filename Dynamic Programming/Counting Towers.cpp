#include<bits/stdc++.h>
#define int long long
using namespace std;

// let at the ith state ai is the number of
// towers that have a paritiion at the ith level
// and bi be the number of towers that don't
// have partition at the ith level. Now for the
// i+1th state 3*ai towers will be with partition
// using blocks that can only be place on towers
// with partition, bi towers with no partition
// can be generated using blocks that can only
// be placed on top of towers with no partition,
// now ai+bi non partitioned towers can be generated
// from blocks with no partition and ai+bi partitioned
// towers can be generated from blocks with
// partition. So, in total 4*ai+bi towers with
// partition are generated and ai+2*bi towers
// without partition are generated.
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int N=1e6+1;
    int MOD=1e9+7;

    vector<int> with_part(N);
    vector<int> without_part(N);

    with_part[1]=1;
    without_part[1]=1;

    for(int e=2;e<N;e++)
    {
        with_part[e]=((4*with_part[e-1])%MOD+without_part[e-1])%MOD;
        without_part[e]=(with_part[e-1]+(2*without_part[e-1])%MOD)%MOD;
    }

    int q;cin>>q;

    while(q--)
    {
        int i;cin>>i;

        cout<<(with_part[i]+without_part[i])%MOD<<'\n';
    }
    
    return 0;
}
