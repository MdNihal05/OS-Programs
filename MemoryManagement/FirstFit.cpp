#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    int n , m; cin >> n >> m;
    vector<int>block(n), process(m);
    for (auto &i : block) cin >> i;
    for (auto &i : process) cin >> i;
    vector<int>ans(m + 1, -1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (block[j] >= process[i]) {
                ans[i + 1] = j + 1;
                block[j] -= process[i];
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
}
