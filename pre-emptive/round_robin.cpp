#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;
int32_t main()
{
    int n, time_quantunm = 1; cin >> n >> time_quantunm;
    vector<pair<int, int>>process(n);
    vector<int>burst(n);
    for (int i = 0; i < n; i++) {
        cin >> process[i].first;
        cin >> burst[i];
        process[i].second = i;
    }
    int time = 0;
    sort(all(process));
    for (auto &i : process) {
        cout << i.first << " " << i.second << endl;
    }

    vector<int> ans, vis(n), completion(n);
    deque<pair<int, int>>rq;
    int count = 0;
    rq.push_back(process[0]);
    vis[process[0].second] = 1;

    while (count < n) {
        auto ex = rq.front();
        int req = min(time_quantunm, burst[ex.second]);
        time += req;
        burst[ex.second] -= req;
        if (burst[ex.second] == 0) {
            count++;
            completion[ex.second] = time;
        }
        ans.push_back(ex.second + 1);
        sort(all(process));
        for (int i = 0; i < n; i++) {
            if (vis[process[i].second] == 0 and process[i].second != ex.second and process[i].first <= time and burst[process[i].second] > 0) {
                vis[process[i].second] = 1;
                rq.push_back(process[i]);
            }
        }
        if (burst[ex.second] > 0) {
            rq.push_back(ex);
        }
        rq.pop_front();
    }
    for (auto &i : ans) cout << i << " " ;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << completion[i] << " ";
    }
}
