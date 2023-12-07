#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    int n, total_tracks, head; cin >> n >> head >> total_tracks;
    vector<int>process(n);
    for (int i = 0; i < n; i++) {
        cin >> process[i];
    }
    sort(all(process));
    auto mn = lower_bound(all(process), head); mn--;
    int mx = *upper_bound(all(process), head);

    cout << 2 * total_tracks - head + *mn << endl; // towards largest
    cout << head + 2 * total_tracks - mx;   // towards smallest
}
