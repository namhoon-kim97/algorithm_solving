#include <bits/stdc++.h>
using namespace std;

int indegree[1001];
vector<int> adj[1001];
int arr[1001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
            cin >> arr[j];
        for (int j = 0; j < a; j++) {
            if (j != a - 1) adj[arr[j]].push_back(arr[j + 1]);
            if (j != 0) indegree[arr[j]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    if (q.empty()) {
        cout << 0; return 0;
    }
    vector<int> res;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        res.push_back(cur);
        for (auto nxt : adj[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0)
                q.push(nxt);
        }
    }
    if (res.size() != n) cout << 0;
    else
        for (auto a : res)
            cout << a << '\n';
}