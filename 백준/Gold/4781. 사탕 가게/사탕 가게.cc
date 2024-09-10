#include <bits/stdc++.h>

using namespace std;

int d[10001][5001];
int costs[5001];
int values[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		int n;
		double temp;
		cin >> n >> temp;
		int m = (int)(temp * 100.0 + 0.5);
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; i++) {
			double temp;
			cin >> values[i] >> temp;
			costs[i] = (int)(temp * 100.0 + 0.5);
		}

		for (int w = 1; w <= m; w++) { // w가 돈 m
			for (int v = 1; v <= n; v++) { // v가 개수
				if (costs[v - 1] > w)
					d[w][v] = d[w][v - 1];
				else 
					d[w][v] = max(d[w][v - 1], d[w - costs[v - 1]][v] + values[v - 1]);
				
			}
		}

		cout << d[m][n] << '\n';

		for (int i = 0; i <= m; i++)
			fill(d[i], d[i] + n + 1, 0);
	}

}