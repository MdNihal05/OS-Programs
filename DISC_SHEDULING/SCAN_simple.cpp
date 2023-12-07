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
    int mn = *min_element(all(process));
    int mx = *max_element(all(process));

    cout << 2 * total_tracks - head - mn << endl; // towards largest

    cout << head + mx;            // towards smallest
}
