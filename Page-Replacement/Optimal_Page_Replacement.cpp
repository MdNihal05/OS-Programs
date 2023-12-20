#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;
int32_t main()
{
    int n, frame; cin >> n >> frame;
    vector<int>process(n);
    for (auto &i : process) cin >> i;
    set<int>s;
    int hit = 0, miss = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(process[i]) != s.end()) {
            hit++;
        } else {
            miss++;
            if (s.size() < frame) {
                s.insert(process[i]);
            } else {
                map<int, int>m;
                for (auto &i : s) m[i] = INT_MAX;
                for (auto &ele : s) {
                    for (int j = i + 1; j < n; j++) {
                        if (process[j] == ele) {
                            m[process[j]] = min(m[process[j]], j);
                        }
                    }
                }
                pair<int, int>del = { -1, -1};
                for (auto &i : m) {
                    if (i.second > del.second) del = i;
                }
                cout << del.first << " is replaced with " << process[i] << endl;
                s.erase(del.first);
                s.insert(process[i]);
            }
        }
    }
    cout << hit << " " << miss;
}
