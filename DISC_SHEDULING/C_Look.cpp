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
    int mn = *min_element(all(process));
    int mx = *max_element(all(process));
    auto lb = lower_bound(all(process), head); lb--;
    auto ub = *upper_bound(all(process), head);

    cout << 2 * mx - head - mn + *lb - mn << endl; // towards largest
    cout << head + 2 * mx - 2 * mn - ub; // towards smallest
}
