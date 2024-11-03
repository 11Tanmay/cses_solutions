#include <bits/stdc++.h>
// #include "stdc++.h"
#define int long long
using namespace std;

// in this question sort the arrival and departure dates
// of the guests independently in increasing order
// now before the arrival of the ith guest in the sorted
// arrival array send all those guest home whose departure
// is before from the departure array the arrival of the ith guests
// now we also have to keep track of the empty rooms to assign
// to new guests if there are no empty rooms then we
// increase the number of available rooms.
 
int32_t main() 
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
 
    int n;cin>>n;
    vector<pair<int, int> > arrival;
    vector<pair<int, int> > departure;

    for(int i=0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;

        arrival.push_back(make_pair(a, i));
        departure.push_back(make_pair(b, i));
    }

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int room=0;
    int max_rooms=0;

    map<int, int> room_allocation_map;
    set<int> empty_rooms;

    for(int i=0,j=0;i<n;i++)
    {
        while(departure[j].first<arrival[i].first)
        {
            empty_rooms.insert(room_allocation_map[departure[j].second]);
            j++;
            room--;
        }
        if(empty_rooms.size()==0)
        {
            room++;
            room_allocation_map[arrival[i].second] = room;
            max_rooms=max(max_rooms, room);
        }
        else
        {
            room_allocation_map[arrival[i].second] = (*empty_rooms.begin());
            empty_rooms.erase(empty_rooms.begin());
            room++;
        }
    }

    cout<<max_rooms<<'\n';
    for(int i=0;i<n;i++)
    {
        cout<<room_allocation_map[i]<<" ";
    }
    return 0;
}