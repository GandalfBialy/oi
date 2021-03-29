#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        string numberStr;
        cin >> numberStr;

        for (int j = 0; j < numberStr.length(); j++) {
            int digit = numberStr[j] - '0';
            sum += digit * digit;
        }

        if (numberStr == "1" or numberStr == "4") {
            cout << numberStr;
        }
        else {
            cout << numberStr << " " << sum;

            while (sum != 1 and sum != 4) {
                numberStr = to_string(sum);
                sum = 0;
                for (int j = 0; j < numberStr.length(); j++) {
                    int digit = numberStr[j] - '0';
                    sum += digit * digit;
                }

                cout << " " << sum;
            }
        }

        cout << endl;
    }
}