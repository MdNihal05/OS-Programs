#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    int n, frame; cin >> n >> frame;
    vector<int>process(n);
    for (int i = 0; i < n; i++) cin >> process[i];
    set<int>s;
    vector<int>vis(frame);
    int hit = 0, miss = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(process[i]) != s.end()) {
            hit++;
            vis[frame - 1] = process[i];
            for (auto &j : vis) cout << j << " ";
            cout << "hit";
        } else {
            miss++;
            if (s.size() < frame) {
                vis[miss - 1] = process[i];
                s.insert(process[i]);
            } else {
                s.erase(vis[frame - 1]);
                vis[frame - 1] = process[i];
                s.insert(vis[frame - 1]);
            }
            for (auto &j : vis) cout << j << " ";

            cout << "miss";
        }
        cout << endl;
    }
    cout << hit << " " << miss;

}
