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
 
    vector<int> permutation(n);
    if(n==2||n==3)
    {
        cout<<"NO SOLUTION";
    }
    else if(n==4)
    {
        cout<<3<<" "<<1<<" "<<4<<" "<<2<<" ";
    }
    else
    {
        int l=0, r=n-1;
 
        while(l<=r)
        {
            if(l==r)
            {
                permutation[l]=n;
                break;
            }
            permutation[l]=n;
            l++;
            n--;
            permutation[r]=n;
            r--;
            n--;
        }
 
        reverse(permutation.begin()+((int)permutation.size()+1)/2, permutation.end());
 
        for(auto e:permutation)
        {
            cout<<e<<" ";
        }
    }    
 
    return 0;
}