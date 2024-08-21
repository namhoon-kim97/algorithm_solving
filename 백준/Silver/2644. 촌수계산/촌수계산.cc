#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int n, m;
vector<int> adj[101];
bool vis[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    int a, b;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child;
        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }

    queue<pair<int, int>> q;
    q.push({ a,0 });
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.first == b) {
            cout << cur.second;
            return 0;
        }

        for (auto x : adj[cur.first]) {
            if (!vis[x]) {
                q.push({ x ,cur.second + 1 });
                vis[x] = true;
            }
        }
    }
    cout << -1;
}
