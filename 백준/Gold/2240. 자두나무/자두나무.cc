#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001][31][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    dp[0][w][1] = 0;

    for (int time = 0; time < t; time++) {
        for (int cnt = 0; cnt <= w; cnt++) {
            for (int pos = 1; pos <= 2; pos++) {
                if (dp[time][cnt][pos] >= 0) {
                    int nextPos = arr[time + 1];

                    if (pos == nextPos)
                        dp[time + 1][cnt][pos] = dp[time][cnt][pos] + 1;
                    else {
                        if (cnt != 0)
                            dp[time + 1][cnt - 1][nextPos] = max(dp[time + 1][cnt - 1][nextPos], dp[time][cnt][pos] + 1);
                        dp[time + 1][cnt][pos] = dp[time][cnt][pos];
                    }
                }
            }
        }
    }

    int ret = 0;
    for (int cnt = 0; cnt <= w; cnt++) {
        for (int pos = 1; pos <= 2; pos++)
            ret = max(ret, dp[t][cnt][pos]);
    }

    cout << ret;
}