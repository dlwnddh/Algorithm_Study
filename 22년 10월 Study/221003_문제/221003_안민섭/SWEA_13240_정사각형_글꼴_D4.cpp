#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int h, w, n;
        cin >> h >> w >> n;
        string str[1001] = {};
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            int len = str[i].length();
            maxlen = max(maxlen, len);
        }
        int maxi = 0;
        for (int x = w; x >= maxlen; x--) {
            int y = 1;
            int cur_line = 0;
            for (int i = 0; i < n; i++) {
                // y가 h를 넘으면?
                // if(y>h) break;
                // 지금 얘 추가하면 x(width)를 넘길 때
                int len = str[i].length();
                if (cur_line + len > x) {
                    y++;
                    cur_line = 0;
                }
                cur_line += len+1;
            }
            int a = h / y;
            int b = w / x;
            int ans = min(a, b);
            maxi = max(maxi, ans);
        }
        cout << "#" << t << " " << maxi << "\n";
    }
    return 0;
}