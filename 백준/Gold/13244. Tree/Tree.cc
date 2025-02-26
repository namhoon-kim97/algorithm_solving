#include <bits/stdc++.h>
using namespace std;
int vis[1001];

void dfs(int here, vector<vector<int>> &adj) {
    vis[here] = true;
    for (int there : adj[here]) {
        if (!vis[there]) {
            dfs(there, adj);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        fill(vis, vis + 1001, false);
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        int m;
        cin >> m;
       
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i, adj);
                cnt++;
            }
        }
        if (m == n - 1 && cnt == 1) {
            cout << "tree\n";
        }
        else cout << "graph\n";
    }
}