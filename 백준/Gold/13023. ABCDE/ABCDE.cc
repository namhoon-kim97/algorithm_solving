#include <bits/stdc++.h>

using namespace std;

vector<int> adj[2001];
bool vis[2001];
int n, m;
bool flag;

void dfs(int depth, int cur) {
    if (depth == 5) {
        flag = true;
        return;
    }
    for (int nxt: adj[cur])
        if (!vis[nxt]) {
            vis[nxt] = true;
            dfs(depth + 1, nxt);
            vis[nxt] = false;
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++) {
        fill(vis, vis + n, false);
        flag = false;
        vis[i] = true;
        dfs(1, i);
        if (flag) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}