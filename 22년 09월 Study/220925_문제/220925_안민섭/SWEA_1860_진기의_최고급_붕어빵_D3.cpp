#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k; // n명, m초=k개
        int arr[110] = {};
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            
            // i = 지금까지 온사람 수
            // time 기준 몇개만들엇는지 계산법?
            // (time/m의 몫) * k
            if ((arr[i] / m) * k < (i+1)) {
                flag = 1;
            }
        }
        cout << "#" << t << " ";
        if (flag) cout << "Impossible\n";
        else cout << "Possible\n";
    }
    
    return 0;
}