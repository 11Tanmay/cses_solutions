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
    
    string s;cin>>s;
 
    int n=s.size();
 
    int mx_count=0;
 
    for(int e=0;e<n;e++)
    {
        int count=1;
 
        while(e!=n-1&&s[e]==s[e+1])
        {
            count++;
            e++;
        }
 
        mx_count=max(mx_count, count);
    }
 
    cout<<mx_count;
 
    return 0;
}