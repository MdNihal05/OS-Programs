#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

bool find(deque<int>q, int x) {
    while (q.size()) {
        if (q.back() == x) {
            return 1;
        }
        q.pop_back();
    }
    return 0;
}

int32_t main()
{
    int n, frame; cin >> n >> frame;
    vector<int>process(n);
    for (int i = 0; i < n; i++) {
        cin >> process[i];
    }

    deque<int>q;
    int miss = 0, hit = 0;
    for (int i = 0; i < n; i++) {
        if (find(q, process[i])) {
            hit++;
        } else {
            q.push_back(process[i]);
            if (q.size() > frame) q.pop_front();
            miss++;
        }
    }
    cout << hit << " " << miss;
}
