#include <bits/stdc++.h>
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

    vector<int> arrival(n);
    vector<int> departure(n);

    for(int e=0;e<n;e++)
    {
        cin>>arrival[e];
        cin>>departure[e];
    }

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i=0, j=0;

    int guests=0;

    int mx_guests=0;

    while(j<n)
    {
        while(i<n&&arrival[i]<=departure[j])
        {
            i++;
            guests++;
        }
        mx_guests=max(guests, mx_guests);
        guests--;
        j++;
    }

    cout<<mx_guests;
    return 0;
}