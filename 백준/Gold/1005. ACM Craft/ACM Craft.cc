#include <bits/stdc++.h>

using namespace std;
int arr[1001];
int deg[1001];
int res[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    int n, k;
    cin >> T;


    while (T--) {
        cin >> n >> k;
        vector<int> adj[1001];

       
        fill(deg, deg + n + 1, 0);
        fill(arr, arr + n + 1, 0);
        fill(res, res + n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            res[i] = arr[i];
        }

        for (int l = 0; l < k; l++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            deg[y]++;
        }
        int w;
        cin >> w;

        queue<pair<int,int>> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0) q.push({ i ,arr[i]});

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            
            for (int nxt : adj[cur.first]) {
                deg[nxt]--;
                res[nxt] = max(res[nxt], cur.second + arr[nxt]);
                if (deg[nxt] == 0)
                    q.push({ nxt , res[nxt] });
            }
        }
        cout << res[w]<< '\n';
    }

}
