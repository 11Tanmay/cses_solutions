#include "bits/stdc++.h"
#define int long long
using namespace std;

// for this question sort the intervals in (start_time, -end_time order)
// negative of end_time is important because while processing the intervals
// if two intervals have the same start time then the interval which is longer
// should come first. Next implement a fenwick tree to get range sums. After
// sorting the intervals to find in how many intervals this interval occurs
// just find the the number of intervals having end time greater than this 
// interval. Now to find the number of intervals that this interval contains
// process the intervals in reverse order and find how many intervals have a 
// end time smaller than this interval.

const int N=4*1e5+10;

map<int, int> mp;
vector<pair<int, int> > inputs;
vector<pair<pair<int, int>, int> > sorted_inputs;
vector<int> fenwick_tree(N, 0);
vector<int> contains(N, 0);
vector<int> is_contained(N, 0);

void update(int index, int value)
{
    while(index<N)
    {
        fenwick_tree[index]+=value;
        index = index + (index & (-index));
    }
}

int range_sum(int index)
{
    int sum=0;

    while(index>0)
    {
        sum+=fenwick_tree[index];
        index = index - (index & (-index));
    }

    return sum;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;

        inputs.push_back(make_pair(a, b));
        mp[a]=0;
        mp[b]=0;
    }

    int count=1;

    for(auto i: mp)
    {
        mp[i.first]=count;
        count++;
    }

    count=0;

    for(auto input: inputs)
    {
        sorted_inputs.push_back(make_pair(make_pair(mp[input.first], -mp[input.second]), count));
        count++;
    }

    sort(sorted_inputs.begin(), sorted_inputs.end());
    
    for(auto input: sorted_inputs)
    {
        is_contained[input.second] = range_sum(N-1) - range_sum(-input.first.second-1);
        update(-input.first.second, 1);
    }

    fill(fenwick_tree.begin(), fenwick_tree.end(), 0);

    reverse(sorted_inputs.begin(), sorted_inputs.end());

    for(auto input: sorted_inputs)
    {
        contains[input.second] = range_sum(-input.first.second);
        update(-input.first.second, 1);
    }

    for(int i=0;i<n;i++)
    {
        cout<<(contains[i]!=0?1:0)<<" ";
    }

    cout<<'\n';

    for(int i=0;i<n;i++)
    {
        cout<<(is_contained[i]!=0?1:0)<<" ";
    }
    
    return 0;
}