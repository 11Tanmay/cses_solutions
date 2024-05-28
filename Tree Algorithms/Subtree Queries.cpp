#include <bits/stdc++.h>
#define int long long
using namespace std;

// in this question you have to flatten the tree using dfs
// each node is remapped to a new array according to starting
// times in the dfs and every subtree is now a range start_time
// to end_time, now for an update query only the node needs to 
// be updated and for a subtree query sum of the range from
// start_time to end_time is to be outputted, this can be 
// implemented via a segment tree over the new array.

const int N=2*1e5+1;

vector<int> tree[N];
vector<int> start_time(N);
vector<int> end_time(N);

void dfs(int v, int p, int &time)
{
    time++;

    start_time[v]=time;

    for(auto e:tree[v])
    {
        if(e==p)
        {
            continue;
        }

        dfs(e, v, time);
    }

    end_time[v]=time;
}

int build_tree(vector<int> &segment_tree, vector<int> &x, int i, int l, int r)
{
    if(l>r)
    {
        return 0;
    }
    if(l==r)
    {
        return segment_tree[i]=x[l];
    }

    int mid=(l+r)/2;
    return segment_tree[i]=build_tree(segment_tree, x, 2*i+1, l, mid)+build_tree(segment_tree, x, 2*i+2, mid+1, r);
}

int query(vector<int> &segment_tree, vector<int> &x, int i, int l, int r, int ql, int qr)
{
    if(ql>r||qr<l)
    {
        return 0;
    }
    if(ql<=l&&r<=qr)
    {
        return segment_tree[i];
    }

    int mid=(l+r)/2;
    return query(segment_tree, x, 2*i+1, l, mid, ql, qr)+query(segment_tree, x, 2*i+2, mid+1, r, ql, qr);
}

void update(vector<int> &segment_tree, vector<int> &x, int i, int l, int r, int index, int value)
{
    if(index<l||index>r)
    {
        return ;
    }
    if(l==r)
    {
        segment_tree[i]+=value;
        return ;
    }

    int mid=(l+r)/2;

    update(segment_tree, x, 2*i+1, l, mid, index, value);
    update(segment_tree, x, 2*i+2, mid+1, r, index, value);

    segment_tree[i]+=value;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> v(n);
    for(int e=0;e<n;e++)
    {
        cin>>v[e];
    }

    for(int e=0;e<n-1;e++)
    {
        int a, b;
        cin>>a>>b;

        a--;
        b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int time=-1;

    dfs(0, -1, time);

    vector<int> x(n);

    for(int e=0;e<n;e++)
    {
        x[start_time[e]]=v[e];
    }

    vector<int> segment_tree(4*n);

    build_tree(segment_tree, x, 0, 0, n-1);

    while(q--)
    {
        int i;cin>>i;

        if(i==1)
        {
            int s, value;
            cin>>s>>value;
            s--;

            update(segment_tree, x, 0, 0, n-1, start_time[s], value-x[start_time[s]]);

            x[start_time[s]]=value;
        }
        else
        {
            int s;cin>>s;
            s--;

            cout<<query(segment_tree, x, 0, 0, n-1, start_time[s], end_time[s])<<'\n';
        }
    }

    return 0;
}
