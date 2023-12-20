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
    deque<int>vis;
    int hit = 0, miss = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(process[i]) != s.end()) {
            hit++;
            if (find(all(vis), process[i]) != vis.end()) {
                vis.erase(find(all(vis), process[i]));
            }
            vis.push_back(process[i]);
            for (auto &j : vis) cout << j << " ";
            cout << "hit";
        } else {
            miss++;
            if (s.size() < frame) {
                vis.push_back(process[i]);
                s.insert(process[i]);
            } else {
                s.erase(vis.front());
                vis.pop_front();
                vis.push_back(process[i]);
                s.insert(vis.back());
            }
            for (auto &j : vis) cout << j << " ";

            cout << "miss";
        }
        cout << endl;
    }
    cout << hit << " " << miss;

}
