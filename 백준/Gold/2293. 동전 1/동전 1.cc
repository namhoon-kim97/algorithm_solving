#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // d[i]는 i원을 만들 수 있는 경우의 수

    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            d[j] = d[j] + d[j - arr[i]];
        }
    }
   
    cout << d[k];
}