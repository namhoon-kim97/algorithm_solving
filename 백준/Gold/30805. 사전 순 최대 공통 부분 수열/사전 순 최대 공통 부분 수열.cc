#include <bits/stdc++.h>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
    vector<int> arrA(n);
	for (int i = 0; i < n; ++i)
		cin >> arrA[i];
	int m;
	cin >> m;
    vector<int> arrB(m);
	for (int i = 0; i < m; ++i)
		cin >> arrB[i];

    vector<int> common_elements;

    for (int num : arrA) {
        if (find(arrB.begin(), arrB.end(), num) != arrB.end()) {
            common_elements.push_back(num);
        }
    }

    sort(common_elements.begin(), common_elements.end());
    common_elements.erase(unique(common_elements.begin(), common_elements.end()), common_elements.end());

    if (common_elements.empty()) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> result;
    while (!common_elements.empty()) {
        int max_val = *max_element(common_elements.begin(), common_elements.end());
        result.push_back(max_val);

        // 최대값 이후로 부분 수열 업데이트
        auto it1 = find(arrA.begin(), arrA.end(), max_val);
        auto it2 = find(arrB.begin(), arrB.end(), max_val);
        arrA.erase(arrA.begin(), it1 + 1);
        arrB.erase(arrB.begin(), it2 + 1);

        // 공통 숫자 다시 구하기
        common_elements.clear();
        for (int num : arrA) {
            if (find(arrB.begin(), arrB.end(), num) != arrB.end()) {
                common_elements.push_back(num);
            }
        }
        sort(common_elements.begin(), common_elements.end());
        common_elements.erase(unique(common_elements.begin(), common_elements.end()), common_elements.end());
    }

    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
}