#include <bits/stdc++.h>
using namespace std;

const int N = 7;
string path;
bool vis[N][N];
int ans = 0;

int dx[4] = {-1, 1, 0, 0}; // U D L R
int dy[4] = {0, 0, -1, 1};
char dirChar[4] = {'U', 'D', 'L', 'R'};

bool isEmpty(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && !vis[x][y];
}

void dfs(int x, int y, int i) {
    if (x == 6 && y == 0) {
        if (i == 48) ans++;
        return;
    }

    // Pruning: trapped in dead-end corridor
    if (isEmpty(x - 1, y) && isEmpty(x + 1, y) && !isEmpty(x, y - 1) && !isEmpty(x, y + 1)) return;
    if (!isEmpty(x - 1, y) && !isEmpty(x + 1, y) && isEmpty(x, y - 1) && isEmpty(x, y + 1)) return;

    vis[x][y] = true;

    if (i < 48) {
        if (path[i] == '?') {
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (isEmpty(nx, ny)) {
                    dfs(nx, ny, i + 1);
                }
            }
        } else {
            for (int d = 0; d < 4; d++) {
                if (path[i] == dirChar[d]) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (isEmpty(nx, ny)) {
                        dfs(nx, ny, i + 1);
                    }
                }
            }
        }
    }

    vis[x][y] = false;
}

int main() {
    cin >> path;
    dfs(0, 0, 0);
    cout << ans << '\n';
    return 0;
}
