#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; ++i) {
        int d, t;
        cin >> d >> t;

        pq.push({ d, t }); // 마감기한이 빠른거부터
    }

    int dayCnt = 0;
    int x = 0, y = 0;  // x: 평일 근무 가능 횟수, y: 시간 외 근무 가능 횟수
    int cnt = 0;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int t = cur.second;
        
        while (dayCnt < cur.first) {
            if (dayCnt % 7 < 5) x++;
            y++;
            dayCnt++;
        }
        if (x >= t) {
            x -= t;
        }
        else if (x + y >= t) {
            int tmp = t - x;
            x = 0;
            y -= tmp;
            cnt += tmp;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    cout << cnt;
}
