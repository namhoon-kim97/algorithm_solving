#include <bits/stdc++.h>
#include <unordered_map>
#include <regex>
using namespace std;

string addNumber(string a, string b) {
    int i = a.length() - 1, j = b.length() - 1;
    string ret = "";
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int temp = carry;
        if (i >= 0) temp += (a[i--] - '0');
        if (j >= 0) temp += (b[j--] - '0');
        ret += to_string(temp % 10);
        carry = temp / 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string sortDigitsAndRemoveLeadingZeros(const string& num) {
    string sortedNum = num;
    sort(sortedNum.begin(), sortedNum.end());

    int pos = 0;
    while (pos < sortedNum.size() && sortedNum[pos] == '0') {
        pos++;
    }
    if (pos == sortedNum.size())
        return "0";
    return sortedNum.substr(pos);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    regex patternA("^123(3+)+4444$");
    regex patternB("^556(6+)+7777$");
    while (t--) {
        int m;
        string term;
        cin >> m >> term;
        unordered_map<string, int> um;
        string outcome = "";
        
        int i;
        for (i = 1; i <= m; i++) {
            //cout << "idx: " << i << "  number : " << number <<  "   temp : " << temp << '\n';
            if (regex_match(term, patternA) || regex_match(term, patternB)) {
                outcome = "C " + to_string(i);
                break;
            }

            // 반복 검사: 이전에 등장한 항이면
            if (um.find(term) != um.end()) {
                outcome = "R " + to_string(i);
                break;
            }
            um[term] = i;
            if (i < m) {
                string rev = term;
                reverse(rev.begin(), rev.end());
                string sum = addNumber(term, rev);
                // 합의 자릿수를 정렬하고 선행 0 제거
                term = sortDigitsAndRemoveLeadingZeros(sum);
            }
        }
        if (outcome == "")
            outcome = term;

        cout << outcome << "\n";
    }
}
