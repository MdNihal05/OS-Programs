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
    map<int, int>index;
    int hit = 0, miss = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(process[i]) != s.end()) {
            hit++;
            index[process[i]] = i;
        } else {
            miss++;
            if (s.size() < frame) {
                index[process[i]] = i;
                s.insert(process[i]);
            } else {
                pair<int, int> F = {0, INT_MAX};
                for (auto &i : index) {
                    if (F.second > i.second) {
                        F.second = i.second;
                        F.first = i.first;
                    }
                }
                index.erase(index.find(F.first));
                s.erase(F.first);
                index[process[i]] = i;
                s.insert(process[i]);
            }
        }
    }
    cout << hit << " " << miss;
}
