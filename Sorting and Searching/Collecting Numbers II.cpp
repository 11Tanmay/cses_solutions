#include<bits/stdc++.h>
#define int long long
using namespace std;

// to now answer the queries if i and j positions are
// to be swapped then we check if number just greater
// or just less then ith are present anywhere from 
// i+1 to j if they are present, then only count will
// change similary for jth we check if number just 
// greater or just less than it are present anywhere
// from i to j-1 or not, if not then only the count will
// change.
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n,m;
    cin>>n>>m;
 
    vector<int> x(n);
 
    vector<int> mp(n+1);
    vector<int> ind(n+1);
 
    for(int e=0;e<n;e++)
    {
        cin>>x[e];
        ind[x[e]]=e;
        mp[e+1]=1;
    }
 
    for(int e=n-1;e>=0;e--)
    {
        if(ind[x[e]+1]>ind[x[e]])
        {
            mp[x[e]]+=mp[x[e]+1];
        }
    }
 
    int num=1;
 
    int count=0;
 
    while(num<=n)
    {
        num+=mp[num];
        count++;
    }
 
    while(m--)
    {
        int a, b;
        cin>>a>>b;
 
        a=a-1;
        b=b-1;

        int a_=min(a, b);
        int b_=max(a, b);

        a=a_;
        b=b_;
 
        if(ind[x[b]+1]>=a&&ind[x[b]+1]<b)
        {
            count=count-1;
        }
        if(x[b]!=1&&ind[x[b]-1]>=a&&ind[x[b]-1]<b)
        {
            count=count+1;
        }
        if(ind[x[a]+1]>a&&ind[x[a]+1]<=b)
        {
            count=count+1;
        }
        if(x[a]!=1&&ind[x[a]-1]>a&&ind[x[a]-1]<=b)
        {
            count=count-1;
        }
 
        if(x[a]+1==x[b])
        {
            count=count-1;
        }
        if(x[a]==x[b]+1)
        {
            count=count+1;
        }
 
        ind[x[a]]=b;
        ind[x[b]]=a;

        swap(x[a], x[b]);
 
        cout<<count<<'\n';
    }
 
    return 0;
}