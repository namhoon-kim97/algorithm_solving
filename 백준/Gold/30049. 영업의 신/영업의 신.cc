#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int values[10001]; // 매장에서 1등 매출액
int stores[10001]; // 매장에서 1등 직원번호
int arr[301][10001]; // [직원][가게] = 매출액
vector<int> adj[301]; // 각 직원 담당 매장들
vector<int> store_employees[10001];
int cnt_top[301]; // 자신이 맡은 매장 중 1등 매장 수
int result = 0; // 현재 영업왕 수

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    
    for (int i = 1; i <= n; i++) {
        unordered_set<int> visited;
        for (int j = 0; j < k; j++) {
            int store, t;
            cin >> store >> t;
            arr[i][store] += t;
            if (visited.insert(store).second) {
                adj[i].push_back(store);
                store_employees[store].push_back(i);
            }
            if (values[store] < arr[i][store]) {
                values[store] = arr[i][store];
                stores[store] = i;
            }
        }
    }

    // 초기 영업왕 계산
    for (int i = 1; i <= n; i++) {
        for (auto store : adj[i]) {
            if (stores[store] == i) cnt_top[i]++;
        }
        if (cnt_top[i] == adj[i].size()) result++;
    }

    int q;
    cin >> q;
    while (q--) {
        int person, store, v;
        cin >> person >> store >> v;
        arr[person][store] += v;
        
        if (values[store] < arr[person][store]) {
            int old_top = stores[store];
            int new_top = person;

            values[store] = arr[person][store];
            stores[store] = new_top;

            if (old_top != new_top) {
                // 기존 1등 직원 cnt_top 감소
                if (--cnt_top[old_top] == adj[old_top].size() - 1) result--;
                // 새로운 1등 직원 cnt_top 증가
                if (++cnt_top[new_top] == adj[new_top].size()) result++;
            }
        }
        cout << result << '\n';
    }
}
