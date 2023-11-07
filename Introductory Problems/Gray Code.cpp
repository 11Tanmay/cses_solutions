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

    vector<vector<int>> gray_code((1<<n), vector<int> (n));

    for(int f=0;f<n;f++)
    {
        for(int e=0;e<(1<<n);e++)
        {
            if(e/(1<<(f+1))%2==0)
            {
                if(e/(1<<(f))%2==0)
                {
                    gray_code[e][f]=0;
                }
                else
                {
                    gray_code[e][f]=1;
                }
            }
            else
            {
                if(e/(1<<(f))%2==0)
                {
                    gray_code[e][f]=1;
                }
                else
                {
                    gray_code[e][f]=0;
                }
            }
        }
    }

    for(int e=0;e<(1<<n);e++)
    {
        for(int f=n-1;f>=0;f--)
        {
            cout<<gray_code[e][f];
        }
        cout<<'\n';
    }

    return 0;
}
