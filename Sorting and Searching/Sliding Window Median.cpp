#include<bits/stdc++.h>
#define int long long
using namespace std;

// take one maxheap for median and elements to left of the
// median in the window one minheap for elements to right
// of the median in the window, if the element to be included
// in the window is greater then the top element of maxh(median)
// then push it to the minh else if it is less than equal to
// to the top element of maxh(median) push it to the maxh.
// now balance the heaps maxh.size()-minh.size() either 0 or 
// 1 depending on whether k is even or odd. now when removing
// elements from the window check on which heap it is present
// according to it being greater or smaller(or equal) to 
// the current window median. balance the heaps again for
// the next step.

void balance(multiset<int> &maxh, multiset<int> &minh)
{
    while((int)maxh.size()-(int)minh.size()>1)
    {
        minh.insert(*(--maxh.end()));
        maxh.erase(--maxh.end());
    }

    while((int)minh.size()>(int)maxh.size())
    {
        maxh.insert(*(minh.begin()));
        minh.erase(minh.begin());
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
    
    int n,k;
    cin>>n>>k;

    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
    }

    int i=0, j=-1;

    vector<int> medians;
    multiset<int> maxh;
    multiset<int> minh;

    while(1)
    {
        j++;

        if(j==n)
        {
            break;
        }

        if(maxh.size()==0||*(--maxh.end())>=x[j])
        {
            maxh.insert(x[j]);
        }
        else
        {
            minh.insert(x[j]);
        }

        balance(maxh, minh);

        if(j-i+1==k)
        {
            int median=*(--maxh.end());

            medians.push_back(median);

            if(x[i]<=median)
            {
                maxh.erase(maxh.find(x[i]));
            }
            else
            {
                minh.erase(minh.find(x[i]));
            }

            i++;
            
            balance(maxh, minh);
        }
    }

    for(auto e: medians)
    {
        cout<<e<<" ";
    }

    return 0;
}
