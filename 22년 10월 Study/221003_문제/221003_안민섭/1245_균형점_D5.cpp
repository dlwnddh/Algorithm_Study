#include <iostream>
#include <cmath>

using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        double loc[12] = {};
        double mass[12] = {};
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> loc[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> mass[i];
        }
        cout << "#"<<t;
        // 0~1 1~2 사이에서 이진탐색으로 적절한 값검색 (모든 값 계산 더하기 g,m1은 소거됨)
        for (int i = 0; i < n - 1; i++) {
            double a = loc[i];
            double b = loc[i+1];
            while (a <= b) {
                double mid = (a + b) / 2;
                // m2/(d*d) 계산해서 비교 후 a or b이동
                // 앞부분
                double sumf = 0;
                for (int y = 0; y <= i; y++) {
                    double d = abs(mid - loc[y]);
                    sumf += mass[y] / (d*d);
                }
                // 뒷부분
                double sumb = 0;
                for (int y = i + 1; y < n; y++) {
                    double d = abs(mid - loc[y]);
                    sumb += mass[y] / (d*d);
                }
                if (sumf < sumb) {
                    b = mid;
                }
                else {
                    a = mid;
                }
                if (round(b * 1e12) / 1e12 == round(a * 1e12) / 1e12)break;
            }
            printf(" %.10f", (a + b) / 2);
        }
        cout << "\n";

    }

    return 0;
}