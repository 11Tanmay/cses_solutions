#include<bits/stdc++.h>
#define int long long
using namespace std;

// in this question we move greedily
// we sort the array for people and
// apartments. Then if the ith person
// can be assigned an apartment we
// assign him one and move on to check
// the next person and next apartment
// else if apartment number is too low 
// we check next apartment and if it is
// to high for a given person we move
// on to check the next person.

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n);
    
    for(int e=0;e<n;e++)
    {
        cin>>a[e];
    }

    vector<int> b(m);

    for(int e=0;e<m;e++)
    {
        cin>>b[e];
    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    int e=0, f=0;

    int ans=0;

    while(e<n&&f<m)
    {
        if(abs(a[e]-b[f])<=k)
        {
            ans++;
            e++;
            f++;
        }
        else
        {
            if(a[e]-b[f]>k)
            {
                f++;
            }
            else
            {
                e++;
            }
        }
    }

    cout<<ans;

    return 0;
}