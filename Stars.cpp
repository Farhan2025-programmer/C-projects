#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int space = 1; space <= n - i; space++) {
            cout << " ";
        }

        for(int star = 1; star <= (2 * i - 1); star++) {
            cout << "*";
        }

        cout << endl;
    }

    cout << "\n\n" << endl;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "\n\n" << endl;

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
