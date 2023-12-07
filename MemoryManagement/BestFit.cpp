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
        int mn = INT_MAX, ind = -1;
        for (int j = 0; j < n; j++) {
            if (block[j] >= process[i] and block[j] <= mn) {
                mn = block[j];
                ind = j ;
            }
        }
        ans[i + 1] = (ind>0)?ind+1:-1;
        if (ind != -1) block[ind] -= process[i];
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
}
