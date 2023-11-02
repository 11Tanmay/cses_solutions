#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
 
    int n;cin>>n;
 
    while(1)
    {
        cout<<n<<" ";
        if(n==1)
        {
            break;
        }
        if(n%2)
        {
            n*=3;
            n+=1;
        }
        else
        {
            n/=2;
        }
    }
 
    return 0;
}
