#include<bits/stdc++.h>
#define int long long
using namespace std;

int digit_count(int i)
{
    int digits_in_i=0;

    int _i=i;

    while(_i!=0)
    {
        digits_in_i++;
        _i/=10;
    }

    int digits=0;

    vector<int> digits_till_1ex(digits_in_i);

    digits_till_1ex[0]=0;

    for(int e=1;e<digits_in_i;e++)
    {
        digits_till_1ex[e]=digits_till_1ex[e-1]+e*((int)pow(10, e)-(int)pow(10, e-1));
    }

    digits+=digits+digits_till_1ex[digits_in_i-1];

    digits=digits+digits_in_i*(i-(int)pow(10, digits_in_i-1)+1);

    return digits;
}

int solve(int k)
{
    int lo=1, hi=1e18;

    int number=0;

    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;

        int digits=digit_count(mid);

        if(digits<=k)
        {
            number=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    
    if(digit_count(number)==k)
    {
        return number%10;
    }
    number+=1;
    return (number/(int)pow(10, (digit_count(number)-k)))%10;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int q;cin>>q;

    while(q--)
    {
        int k;cin>>k;

        cout<<solve(k)<<'\n';
    }

    return 0;
}