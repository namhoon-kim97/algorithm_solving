#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> arr;
stack<int> st;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        
        while (!st.empty() && st.top() <= h) {
            st.pop();
        }
        ans += st.size();
        st.push(h);
    }
    cout << ans;
}
