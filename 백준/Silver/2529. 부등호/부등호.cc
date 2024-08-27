#include <bits/stdc++.h>

using namespace std;
char arr[11];
bool vis[11];
vector<string> ans;
int k;

void solution(int cnt,string num){
    if (cnt == k + 1) {
        for (int i = 0; i < k; i++) {
            if (arr[i] == '<') {
                if (num[i] > num[i + 1])
                    return;
            }
            else {
                if (num[i] < num[i + 1])
                    return;
            }
        }
        ans.push_back(num);
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (!vis[i]) {
            vis[i] = true;
            solution(cnt + 1, num + to_string(i));
            vis[i] = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> arr[i];

    solution(0, "");
    cout << ans.back() << '\n';
    cout << ans.front() << '\n';
}