#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string input;
    cin >> input;

    while (input != "") {
        string temp;
        if (input[0] == 'p') {
            temp = input.substr(0,2);
            if (temp == "pi")
                input = input.substr(2, input.length());
            else {
                cout << "NO";
                return 0;
            }
        } else if (input[0] == 'k') {
            temp = input.substr(0,2);
            if (temp == "ka")
                input = input.substr(2, input.length());
            else {
                cout << "NO";
                return 0;
            }
        } else if (input[0] == 'c') {
            temp = input.substr(0,3);
            if (temp == "chu")
                input = input.substr(3, input.length());
            else {
                cout << "NO";
                return 0;
            }
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}