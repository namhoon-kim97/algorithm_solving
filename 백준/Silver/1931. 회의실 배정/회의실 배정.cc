#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    while (n--) {
        int x, y;
        cin >> x >> y;
        arr.push_back({ x,y });
    }
    sort(arr.begin(), arr.end(),compare);
    
    int cnt = 1;
    int time = arr[0].second;
    for (int i = 1; i < arr.size(); i++) {
        if (time <= arr[i].first) {
            time = arr[i].second;
            cnt++;
        }
        else continue;
    }
    cout << cnt;
}
