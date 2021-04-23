#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;
	n--;
	vector<bool> isPlus(n);
	//vector<bool> openingBracket(n);
	//vector<bool> closingBracket(n);

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;

		if (c == '+') isPlus[i] = true;
	}

	bool noOpeningBracket = true;
	bool noClosingBracket = false;
	int i = 0;
	while (i < n) {
		if (!isPlus[i]) {
			if (noClosingBracket) {
				cout << ')';
				noClosingBracket = false;
				noOpeningBracket = true;
			}

			while (i < n and !isPlus[i]) {
				cout << '-';
				i++;
			}
		}
		
		if (isPlus[i]) {
			if (noOpeningBracket) {
				cout << '(';
				noOpeningBracket = false;
				noClosingBracket = true;
			}

			while (i < n and isPlus[i]) {
				cout << '-';
				i++;
			}
		}
	}

	if (noClosingBracket) cout << ')';
}