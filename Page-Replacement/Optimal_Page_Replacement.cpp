#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;



int32_t main()
{
    int n, frame; cin >> n >> frame;
    vector<int>process(n);
    for (int i = 0; i < n; i++) {
        cin >> process[i];
    }
    set<int>s;
    int hit = 0, miss = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(process[i]) != s.end()) {
            hit++;
        } else {
            miss++;
            if (s.size() < frame) {
                s.insert(process[i]);
                continue;
            }
            vector<int>index(20, INT_MAX);
            for (int j = i + 1; j < n; j++) {
                index[process[j]] = min(index[process[j]], j);
            }
            pair<int, int>F = {0, INT_MIN};
            for (auto &j : s) {
                if (F.second < index[j]) {
                    F.second = index[j];
                    F.first = j;
                }
            }
            s.erase(F.first);
            s.insert(process[i]);
        }
    }
    cout << hit << " " << miss;
}
