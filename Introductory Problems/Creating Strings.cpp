#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(string &s, map<string, bool> &mp, vector<bool> &is_taken, string &output, vector<string> &result)
{
    bool b=1;

    for(auto e:is_taken)
    {
        if(e==0)
        {
            b=0;
        }
    }

    if(b==1)
    {
        if(mp.find(output)==mp.end())
        {
            result.push_back(output);
            mp[output]=1;
        }
        return ;
    }

    for(int e=0;e<(int)is_taken.size();e++)
    {
        if(is_taken[e]==0)
        {
            is_taken[e]=1;
            output+=s[e];
            solve(s, mp, is_taken, output, result);
            output.pop_back();
            is_taken[e]=0;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    string s;cin>>s;
    map<string, bool> mp;
    vector<bool> is_taken((int)s.size(), 0);
    string output="";
    vector<string> result;
    solve(s, mp, is_taken, output, result);

    cout<<result.size()<<'\n';

    sort(result.begin(), result.end());

    for(auto e:result)
    {
        cout<<e<<'\n';
    }

    return 0;
}
