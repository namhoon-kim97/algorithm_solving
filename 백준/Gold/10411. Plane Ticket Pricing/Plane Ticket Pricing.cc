#include <bits/stdc++.h>
using namespace std;

int n, w;
int dp[301][53]; // dp[seats][week]
int price_choice[301]; // 첫 주에 좌석 n개일 때 선택할 가격
vector<int> prices[53]; // prices[week][i]
vector<int> sells[53];  // sells[week][i]

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> w;
    for (int i = w; i >= 0; --i) {
        int k;
        cin >> k;
        prices[i].resize(k);
        sells[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> prices[i][j];
        }
        for (int j = 0; j < k; ++j) {
            cin >> sells[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));

    // week 0부터 W까지
    for (int week = 0; week <= w; ++week) {
        for (int seats = 0; seats <= n; ++seats) {
            for (int i = 0; i < prices[week].size(); ++i) {
                int price = prices[week][i];
                int sell = sells[week][i];
                int real_sell = min(seats, sell);
                int revenue = price * real_sell;
                int prev = 0;
                if (week > 0) {
                    prev = dp[seats - real_sell][week - 1];
                }
                int total = revenue + prev;

                if (total > dp[seats][week]) {
                    dp[seats][week] = total;
                    if (week == w) {
                        price_choice[seats] = price; // 첫 주
                    }
                }
                else if (total == dp[seats][week] && week == w) {
                    price_choice[seats] = min(price_choice[seats], price);
                }
            }
        }
    }

    cout << dp[n][w] << '\n';          // 최대 수익
    cout << price_choice[n] << '\n';   // 첫 주 가격

    return 0;
}
