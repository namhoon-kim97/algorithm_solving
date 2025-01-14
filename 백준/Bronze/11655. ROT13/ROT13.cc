#include <bits/stdc++.h>
using namespace std;

void ROT13(string& input) {
	for (int i = 0; i < input.size(); i++) {
		if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
			if (isupper(input[i])) {
				input[i] = input[i] + 13;
				if ((input[i] >= 'A' && input[i] <= 'Z')) continue;
			}
			else {
				input[i] = input[i] + 13;
				if (input[i] >= 'a' && input[i] <= 'z') continue;
			}
				
			input[i] = input[i] - ('Z' - 'A' + 1);
		}
	}
	//a b c d e f g h i j k l m n o p q r s t u v w x y z 1 2 3
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	getline(cin, input);
	ROT13(input);
	cout << input;
}