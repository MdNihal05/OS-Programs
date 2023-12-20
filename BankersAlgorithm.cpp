#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main()
{
    int n, A, B, C; cin >> n >> A >> B >> C;
    vector<int>a(n), b(n), c(n);
    vector<int>ma(n), mb(n), mc(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ma[i] >> mb[i] >> mc[i];
        ma[i] -= a[i], mb[i] -= b[i], mc[i] -= c[i];
    }
    A -= accumulate(all(a), 0);
    B -= accumulate(all(b), 0);
    C -= accumulate(all(c), 0);
    vector<int>ans;
    for (int i = 0; i < n; i++) {
        cout << ma[i] << " " << mb[i] << " " << mc[i] << endl;
    }
    cout << endl;
    cout << A << " " << B << " " << C << endl;
    cout << endl;
    int start = 0, end = 0, count = n;
    while (count--) {
        do {
            if (ma[start] == 0 and mb[start] == 0 and mc[start] == 0) {
            }
            else if (A >= ma[start] and B >= mb[start] and C >= mc[start]) {
                ma[start] = 0, mb[start] = 0, mc[start] = 0;
                A += a[start], B += b[start], C += c[start];
                ans.push_back(start + 1);
            }
            start++;
            start %= n;
        } while (start != end);
        end = start;
    }
    for (auto &i : ans) cout << i << " ";

}
