#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int y, x,val;
};
bool operator < (Node v, Node t) {
    return t.val < v.val;
}
int main() {
    freopen("input.txt", "r", stdin);
    // tc
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        priority_queue<Node> q;
        int dy[4] = { 0,0,1,-1 };
        int dx[4] = { 1,-1,0,0 };
        int arr[110][110] = {};
        int dp[110][110] = {};
        int cost[110][110] = {};
        int n;
        cin >> n;
        // string input
        for (int y = 0; y < n; y++) {
            string str;
            cin >> str;
            for (int x = 0; x < n; x++) {
                arr[y][x] = str[x]-'0';
            }
        }
        // cost set
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cost[y][x] = 21e8;
            }
        }
        // djikstra
        q.push({ 0,0,0 });
        cost[0][0] = 0;
        while (!q.empty()) {
            Node now = q.top();
            q.pop();
            if (now.val > cost[now.y][now.x]) continue;
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + now.y;
                int nx = dx[i] + now.x;
                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                // 저장된 cost가 더 작으면 저장할 필요 x
                if (cost[ny][nx] <= cost[now.y][now.x] + arr[ny][nx]) continue;
                cost[ny][nx] = cost[now.y][now.x] + arr[ny][nx];
                q.push({ ny,nx, cost[ny][nx]});
            }
        }
        cout << "#"<<t<<" "<< cost[n - 1][n - 1]<<"\n";

    }

    return 0;
}