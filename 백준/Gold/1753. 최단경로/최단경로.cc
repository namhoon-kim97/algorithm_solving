#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005];
int v, e, st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> st;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }

    fill(d, d + v + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({ d[st],st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.second] != cur.first) continue;
        for (auto a : adj[cur.second]) {
            if (d[cur.second] + a.first <= d[a.second]) {
                d[a.second] = d[cur.second] + a.first;
                pq.push({ d[a.second], a.second });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }


}