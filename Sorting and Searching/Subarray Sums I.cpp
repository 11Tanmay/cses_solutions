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
    
    int n, x;
    cin>>n>>x;

    vector<int> a(n);

    for(int e=0;e<n;e++)
    {
        cin>>a[e];
    }

    int i=0, j=-1;

    int sum=0;

    int count=0;

    while(1)
    {
        j++;
        if(j==n)
        {
            break;
        }
        sum+=a[j];
        
        while(sum>x)
        {
            sum-=a[i];
            i++;
        }

        if(sum==x)
        {
            count++;
        }
    }

    cout<<count;

    return 0;
}