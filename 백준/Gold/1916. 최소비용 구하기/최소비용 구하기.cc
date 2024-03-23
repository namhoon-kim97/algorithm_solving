#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int, int>> adj[1001]; // {cost, en} [st]
int dist[1001];
int INF = 1e9 + 10;
int st, en;
void dijkstra(int st) {
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ dist[st],st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue;
        for (auto nxt : adj[cur.second]) {
            if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }
    
    cin >> st >> en;
    fill(dist, dist + n + 1, INF);
    dijkstra(st);
    cout << dist[en] << '\n';
    
    
}
