#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int sz = 0;


void push(int x) {
    arr[++sz] = x;
    int idx = sz;
    while (idx != 1) {
        int par = idx / 2;
        if (arr[par] >= arr[idx]) break;
        swap(arr[par], arr[idx]);
        idx = par;
    }
}

void top() {
    cout << arr[1] << '\n';
}

void pop() {
    arr[1] = arr[sz--];
    int idx = 1;

    while (2 * idx <= sz) {
        int lc = 2 * idx;
        int rc = 2 * idx + 1;
        int min_child = lc;
        if (rc <= sz && arr[rc] > arr[lc])
            min_child = rc;
        if (arr[idx] >= arr[min_child]) break;
        swap(arr[idx], arr[min_child]);
        idx = min_child;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int temp;
        cin >> temp;
        if (temp == 0 && sz == 0) {
            cout << 0 << '\n';
        }
        else if (temp == 0) {
            top();
            pop();
        }
        else {
            push(temp);
        }
    }

}
