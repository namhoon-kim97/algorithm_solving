#include <bits/stdc++.h>

using namespace std;
int n;

void printStars(int x, int y, int size, vector<vector<char>>& canvas) {
    if (size == 3) {
        canvas[y][x] = '*';
        canvas[y][x - 1] = '*';
        canvas[y][x + 1] = '*';
        canvas[y+1][x] = ' ';
        canvas[y+1][x - 1] = '*';
        canvas[y+1][x + 1] = '*';
        canvas[y+2][x] = '*';
        canvas[y+2][x - 1] = '*';
        canvas[y+2][x + 1] = '*';

        return;
    }
    else {
        int newSize = size / 3;
        printStars(x, y, newSize, canvas);
        printStars(x + newSize, y, newSize, canvas);
        printStars(x - newSize, y, newSize, canvas);

        printStars(x + newSize, y + newSize, newSize, canvas);
        printStars(x - newSize, y + newSize, newSize, canvas);

        printStars(x, y + 2 * newSize, newSize, canvas);
        printStars(x + newSize, y + 2 * newSize, newSize, canvas);
        printStars(x - newSize, y + 2 * newSize, newSize, canvas);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int width = n;
    vector<vector<char>> canvas(n, vector<char>(width, ' '));

    printStars(n / 2, 0, n, canvas);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << canvas[i][j];
        }
        cout << '\n';
    }

    return 0;
}