#include<iostream>
#include<vector>
using namespace std;
#define MAX 200000

int main() {
    int n;
    cin >> n;
    vector<int> c(MAX + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x] ++;
    }
    long long ans = 0;
    for (int q = 1; q <= MAX; ++q) {
        for (int r = 1; q * r <= MAX; ++r) {
            ans += (long long)c[q] * c[r] * c[q * r];
        }
    }
    cout << ans << '\n';
    return 0;
}