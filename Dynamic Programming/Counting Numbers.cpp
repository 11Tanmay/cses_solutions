#include <bits/stdc++.h>
#define int long long
using namespace std;

// question is of digit dp now we generate numbers less that x not having 
// two same consecutive digits for this we define a state with
// (idx, limit, leading_zeroes, previous_digit), where limit tells if 
// we follow the constrainsts of the original number or not and 
// leading_zeroes tells if the number being formed is of the type
// 00012.. here we should not take into account the leading zeroes
// as being repetitive.

int dp[20][2][2][10];

int solve(vector<int> &digits, int idx, int limit, int leading_zeroes, int previous_digit)
{
    if(idx<0)
    {
        return 1;
    }

    if(dp[idx][limit][leading_zeroes][previous_digit]!=-1)
    {
        return dp[idx][limit][leading_zeroes][previous_digit];
    }

    dp[idx][limit][leading_zeroes][previous_digit] = 0;

    int upper_bound = limit == 1 ? digits[idx] : 9;

    for(int i=0;i<=upper_bound;i++)                     
    {
        if(leading_zeroes == 0 && previous_digit == i)
        {
            continue;
        }

        dp[idx][limit][leading_zeroes][previous_digit] += solve(digits, idx-1, (limit == 1) && (i == upper_bound), (leading_zeroes == 1) && (i == 0), i);
    }

    return dp[idx][limit][leading_zeroes][previous_digit];
}

int count_numbers(int x)
{
    if(x<0)
    {
        return 0;
    }

    vector<int> digits;

    while(x>0)
    {
        digits.push_back(x%10);
        x=x/10;
    }

    memset(dp, -1, sizeof (dp));

    return solve(digits, (int)digits.size()-1, 1, 1, 10);
}

int32_t main() 
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    int a, b;
    cin>>a>>b;

    cout<<count_numbers(b)-count_numbers(a-1);

    return 0;
}
