#include <iostream>
#include <vector>
#include <cmath> // abs() 함수 사용을 위해 포함

using namespace std;

int n, cnt = 0;
vector<int> board;
vector<bool> vis_col;

bool is_promising(int row) {
    for (int i = 0; i < row; ++i) {
        if (abs(i - row) == abs(board[i] - board[row])) {
            return false;
        }
    }
    return true;
}

void solution(int cur) {
    if (cur == n) {
        ++cnt;
        return;
    }

    for (int i = 0; i < n; ++i) {
        board[cur] = i;
        if (is_promising(cur) && !vis_col[i]) {
            vis_col[i] = true;
            solution(cur + 1);
            board[cur] = 0;
            vis_col[i] = false;
        }
    }
}

int main() {
    cin >> n;
    board.resize(n);
    vis_col.assign(n, false);

    solution(0);

    cout << cnt << endl;

    return 0;
}
