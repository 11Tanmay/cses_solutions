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

    string s;
    cin>>s;

    int n=s.size();

    map<char, int> mp;

    for(int e=0;e<n;e++)
    {
        mp[s[e]]++;
    }

    int count=0;

    for(auto e:mp)
    {
        if(e.second%2==1)
        {
            count++;
        }
    }

    if(count>1)
    {
        cout<<"NO SOLUTION";
    }
    else
    {
        int i=0, j=n-1;

        for(int e=0;e<26;e++)
        {
            if(mp[(char)(e+'A')]>1)
            {
                while(mp[(char)(e+'A')]>1)
                {
                    s[i]=(char)(e+'A');
                    s[j]=(char)(e+'A');

                    i++;
                    j--;

                    mp[(char)(e+'A')]-=2;
                }
            }
        }

        for(auto e:mp)
        {
            if(e.second==1)
            {
                s[i]=e.first;
            }
        }

        cout<<s;
    }

    return 0;
}

