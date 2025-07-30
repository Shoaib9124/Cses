#include <bits/stdc++.h>
using namespace std;

int drow[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dcol[8] = {1, -1, -1, 1, 2, -2, 2, -2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto curr=q.front();
        int r=curr.first;
        int c=curr.second;
        q.pop();

        for (int k = 0; k < 8; ++k) {
            int nr = r + drow[k];
            int nc = c + dcol[k];

            if (nr >= 0 && nc >= 0 && nr < n && nc < n && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    // Print the result
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << dist[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
