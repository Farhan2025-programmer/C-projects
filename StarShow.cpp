# include <iostream>
using namespace std;

int main() {

    int n = 5;
    int star = 0;
    
    cout << "Enter your number: " << endl;
    cin >> n;
    
    int space = n - star;

    cout << "\n\n" << endl;

    for (int spaceCounter = 1; spaceCounter <= n; spaceCounter++) {
        cout << " ";

        space--;
        star++;
        
        for (int starCounter = 0; starCounter < star; starCounter++) {
            cout << "*";
        }

        cout << endl;
        
    }

    cout << "\n\n" << endl;

    star = n;
    space = star - n;


    for (int spaceCounter = n; spaceCounter >= 0; spaceCounter--) {
        cout << " ";
        
        space++;
        star--;
        
        for (int starCounter = star; starCounter >= 0; starCounter--) {
            cout << "*";
        }

        cout << endl;
        
    }

    int start = 1;
    int leftSpace = n - star;


    for (int i = 0; i <= n; i++) {
        for(int leftSpaceCounter = 0; leftSpaceCounter <= leftSpace; leftSpaceCounter++) {
            cout << " ";
        }

        for (int starCounter = 0; starCounter <= star; starCounter++) {
            cout << "* ";
        }

        leftSpace--;
        star++;

        cout << endl;
    }
    
    return 0;
}
