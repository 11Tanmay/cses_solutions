#include <bits/stdc++.h>
#define int long long
using namespace std;

int build_tree(vector<int> &segment_tree, vector<int> &x, int i, int l, int r)
{
    if(l>r)
    {
        return 1e9+1;
    }
    if(l==r)
    {
        return segment_tree[i]=x[l];
    }

    int mid=(l+r)/2;
    return segment_tree[i]=min(build_tree(segment_tree, x, 2*i+1, l, mid),build_tree(segment_tree, x, 2*i+2, mid+1, r));
}

int query(vector<int> &segment_tree, vector<int> &x, int i, int l, int r, int ql, int qr)
{
    if(ql>r||qr<l)
    {
        return 1e9+1;
    }
    if(ql<=l&&r<=qr)
    {
        return segment_tree[i];
    }

    int mid=(l+r)/2;
    return min(query(segment_tree, x, 2*i+1, l, mid, ql, qr), query(segment_tree, x, 2*i+2, mid+1, r, ql, qr));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n, q;
    cin>>n>>q;
    
    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        cin>>x[e];
    }

    vector<int> segment_tree(4*n+1, 0);

    build_tree(segment_tree, x, 0, 0, n-1);

    while(q--)
    {
        int a, b;
        cin>>a>>b;

        a--;
        b--;

        cout<<query(segment_tree, x, 0, 0, n-1, a, b)<<'\n';
    }

    return 0;
}
