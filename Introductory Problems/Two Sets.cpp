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
 
    int sum=n*(n+1);
 
    if(sum%4==0)
    {
        cout<<"YES"<<'\n';
 
        vector<int> set1;
        vector<int> set2;
 
        sum/=4;
 
        while(n!=0)
        {
            if(n<=sum)
            {
                set1.push_back(n);
                sum-=n;
            }
            else
            {
                set2.push_back(n);
            }
 
            n--;
        }
 
        reverse(set1.begin(), set1.end());
        reverse(set2.begin(), set2.end());
 
        cout<<set1.size()<<'\n';
 
        for(auto e:set1)
        {
            cout<<e<<" ";
        }
 
        cout<<'\n';
 
        cout<<set2.size()<<'\n';
 
        for(auto e:set2)
        {
            cout<<e<<" ";
        }
    }
    else
    {
        cout<<"NO";
    }
 
    return 0;
}