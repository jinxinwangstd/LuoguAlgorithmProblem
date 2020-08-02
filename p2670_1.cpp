#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

vector<vector<int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    arr.assign(N, vector<int>(M, 0));
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == '*')
                arr[i][j] = -1;
        }
    }
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (arr[x][y] == 0) {
                for (int i = 0; i < 8; i++) {
                    int adj_x = x + dx[i], adj_y = y + dy[i];
                    if (adj_x < 0 || adj_x >= N || adj_y < 0 || adj_y >= M)
                        continue;
                    if (arr[adj_x][adj_y] < 0)
                        arr[x][y]++;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << (arr[i][j] >= 0 ? to_string(arr[i][j]) : "*");
        }
        cout << "\n";
    }
    return 0;
}