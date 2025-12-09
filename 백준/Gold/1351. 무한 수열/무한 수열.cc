#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

long long n, p, q;
unordered_map<long long, long long> um;


long long dfs(long long cur) {
    if (cur == 0) return um[cur] = 1;
    if (um[cur] != 0) 
        return um[cur];

    return um[cur] = dfs(cur / p) + dfs(cur / q);
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> p >> q;
    cout << dfs(n);
}