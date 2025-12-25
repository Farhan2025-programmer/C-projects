# include <iostream>
# include <vector>
using namespace std;

int main () {

    vector<int> alreadyIndexs;
    vector<bool> freeIndexs;
    vector<int> notBenIndex;

    string textInput;
    cin >> textInput;

    for (int textCounter = 0; textCounter <= textInput.length(); textCounter++) {
        alreadyIndexs.push_back(textCounter);
    }

    for (int item : alreadyIndexs) {
        cout << item << endl;
    }

    return 0;
}
