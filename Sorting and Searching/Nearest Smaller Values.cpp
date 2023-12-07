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

    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
    }

    stack<int> s;

    s.push(-1);

    for(int e=0;e<n;e++)
    {
        while(s.top()!=-1&&x[s.top()]>=x[e])
        {
            s.pop();
        }

        cout<<s.top()+1<<" ";

        s.push(e);
    }

    return 0;
}