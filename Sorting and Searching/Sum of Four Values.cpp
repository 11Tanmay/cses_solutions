#include<bits/stdc++.h>
#define int long long
using namespace std;

// we make pairs of index values and their sums
// in a vector of pair of int, pair of int, int
// the we sort this vector and apply two pointer
// now if our sum is equal to x and none of the
// indices used to form the sum are equal we output
// those but if some are same we increment i if 
// sum of i+1 is equal to that of i and decrement j
// if sum of j is equal to j-1 else we break the loop
// and claim that a answer is not possible.
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int n,x;
    cin>>n>>x;

    vector<int> nums(n);

    for(int e=0;e<n;e++)
    {
        cin>>nums[e];
    }

    vector<pair<int, pair<int, int>>> p;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            p.push_back({nums[i]+nums[j], {i+1, j+1}});
        }
    }

    sort(p.begin(), p.end());

    int i=0, j=(int)p.size()-1;

    while(i<j)
    {
        if(p[i].first+p[j].first==x)
        {
            if(p[i].second.first==p[j].second.first||
                p[i].second.first==p[j].second.second||
                p[i].second.second==p[j].second.first||
                p[i].second.second==p[j].second.second)
                {
                    if(p[i].first==p[i+1].first)
                    {
                        i++;
                    }
                    else if(p[j].first==p[j-1].first)
                    {
                        j--;
                    }
                    else
                    {
                        break;
                    }
                }
            cout<<p[i].second.first<<" "<<p[i].second.second<<" "<<p[j].second.first<<" "<<p[j].second.second;
            return 0;
        }
        else if(p[i].first+p[j].first<x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    cout<<"IMPOSSIBLE";
    
    return 0;
}
