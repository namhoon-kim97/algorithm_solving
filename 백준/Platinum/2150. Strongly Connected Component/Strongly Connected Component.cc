#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
vector<int> adjTranspose[10001];
int v, e;
bool vis[10001];
deque<int> dq;
vector<int> id;
int cnt;

void reversePostOrderDfs(int cur) {
    vis[cur] = true;
    for (auto a: adj[cur])
        if (!vis[a]){
            reversePostOrderDfs(a);
        }
    dq.push_front(cur);
}

void dfs(int cur) {
    vis[cur] = true;
    id[cur] = cnt;
    for (int a : adjTranspose[cur])
        if (!vis[a])
            dfs(a);
}

void transpose() {
    // adj transpose
    
    for (int i = 1; i <= v; i++) {
        for (auto a : adj[i]) {
            adjTranspose[a].push_back(i);
        }
    }

    for (int i = 1; i <= v; i++) {
        adj[i].clear();
        adj[i] = adjTranspose[i];
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= v; i++) {
            if (!vis[i])
                reversePostOrderDfs(i);
    }

    transpose();

    cnt = 0;
    id.resize(v + 1, -1);
    fill(vis, vis + v + 1, false);
    for (auto v : dq)
        if (id[v] < 0) {
            dfs(v);
            cnt++;
        }


    vector<vector<int>> components(cnt);
    for (int s = 1; s <= v; s++)
        components[id[s]].push_back(s);
    cout << cnt << '\n';
    sort(components.begin(), components.end());
    for (int i = 0; i < components.size(); i++)
    {
        for (auto v : components[i])
            cout << v << " ";
        cout << -1 << '\n';
    }
}
