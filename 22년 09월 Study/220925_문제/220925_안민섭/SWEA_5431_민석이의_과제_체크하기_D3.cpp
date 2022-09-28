#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    // tc
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int dat[110] = {};
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            int t;
            cin >> t;
            dat[t] = 1;
        }
        cout << "#" << t;
        for (int i = 1; i <= n; i++) {
            if (dat[i] == 0) cout << " " << i;
        }
        cout << endl;


    }

    return 0;
}