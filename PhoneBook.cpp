# include <iostream>
# include <vector>
using namespace std;

int lastContactIndex = 1;

class Cantact {
    public:

        int index;
        string name;
        string lastName;
        string phoneNumber;

        Cantact(string nameInput, string lastNameInput, string phoneNumberInput) {
            index = lastContactIndex;
            name = nameInput;
            lastName = lastNameInput;
            phoneNumber = phoneNumberInput;

            lastContactIndex++;
        }

    void itemsPrinter() {
        cout << index << ". Name: " << name << "Last name: " << lastName << "Phone number: " << phoneNumber << endl;
    }
};

vector<Cantact> users;

void allContactsPrinter(vector<Cantact> dataList);
vector<Cantact> searcherByName (string searchByName);
vector<Cantact> searcherByPhoneNumber(string searchByPhoneNumber);
vector<Cantact> searcherByLastName (string searchByLastName);
void contactEditor(int changedItemIndex);
void creatorContact(string name, string lastName, string phoneNumber);


int main() {

    int operationId;

    while (true) {
        cout << "0. Shoow  items \n"
        << "1. Add contact \n"
        << "2. Edit contact \n"
        << "3. Search contact by name \n"
        << "4. Search contact by phone number \n" 
        << "5. Search contact by last name \n"
        << "6. Exit" << endl;

        cout << "Enter your operation number: ";
        cin >> operationId;

        if ( operationId == 0 ) {
            allContactsPrinter(users);
        } else if ( operationId == 1 ) {

            cout << "\n\n __ ADD _________________________ \n" << endl;

            string nameInput;
            string lastNameInput;
            string phoneNumberInput;
            
            cout << "Enter new contant name: ";
            cin >> nameInput;
            cout << "Enter new contact last name: ";
            cin >> lastNameInput;
            cout << "Enter new contact phone number: " << endl;
            cin >> phoneNumberInput;

            creatorContact(nameInput, lastNameInput, phoneNumberInput);

            cout << "\n\n __ END _________________________ \n" << endl;

        } else if ( operationId == 2 ) {
            int itemIndex;
            cout << "Enter user index: " << endl;
            cin >> itemIndex;

            contactEditor(itemIndex);
        } else if ( operationId == 3 ) {

            string nameInputForSearch;
            cout << "Enter name: " << endl;
            cin >> nameInputForSearch;

            searcherByName(nameInputForSearch);
        } else if ( operationId == 4 ) {
            string phoneNumberInputForSearch;
            cout << "Enter phone number: " << endl;
            cin >> phoneNumberInputForSearch;

            searcherByPhoneNumber(phoneNumberInputForSearch);
        } else if ( operationId == 5 ) {
            string lastNameInputForSearch;
            cout << "Enter last name: " << endl;
            cin >> lastNameInputForSearch;

            searcherByLastName(lastNameInputForSearch);
        }
        else if ( operationId == 6 ) {
            break;
        } else {
            cout << "\n\nEntered number is not valid" << endl;
        }
    }

    return 0;
}

void creatorContact(string name, string lastName, string phoneNumber) {
    Cantact newCantact(name, lastName, phoneNumber);
    users.push_back(newCantact);
}

vector<Cantact> searcherByName (string searchByName) {

    vector<Cantact> results;
    int resultLenght = 0;

    for (Cantact item : users) {
        if (item.name.length() >= searchByName.length()) {
            for (int i = 0; i < searchByName.length(); i++) {
                if (item.name[i] == searchByName[i]) {
                    resultLenght++;
                }
            }
            if (resultLenght == searchByName.length()) {
                Cantact newResult(item.name, item.lastName, item.phoneNumber);
                results.push_back(newResult);
            }
            resultLenght = 0;
        }
    }

    allContactsPrinter(results);
    return results;
}

vector<Cantact> searcherByLastName (string searchByLastName) {

    vector<Cantact> results;
    int resultLenght = 0;

    for (Cantact item : users) {
        if (item.lastName.length() >= searchByLastName.length()) {
            for (int i = 0; i < searchByLastName.length(); i++) {
                if (item.lastName[i] == searchByLastName[i]) {
                    resultLenght++;
                }
            }
            if (resultLenght == searchByLastName.length()) {
                Cantact newResult(item.name, item.lastName, item.phoneNumber);
                results.push_back(newResult);
            }
            resultLenght = 0;
        }
    }

    cout << "\n" << "___________________________________" << endl;
    allContactsPrinter(results);
    cout << "\n" << "___________________________________" << endl;
    return results;
}

vector<Cantact> searcherByPhoneNumber(string searchByPhoneNumber) {

    vector<Cantact> results;
    int resultLenght = 0;

    for (Cantact item : users) {
        if (item.phoneNumber.length() >= searchByPhoneNumber.length()) {
            for (int i = 0; i < searchByPhoneNumber.length(); i++) {
                if (item.phoneNumber[i] == searchByPhoneNumber[i]) {
                    resultLenght++;
                }
            }

            if (resultLenght == searchByPhoneNumber.length()) {
                Cantact newResult(item.name, item.lastName, item.phoneNumber);
                results.push_back(newResult);
            }
            resultLenght = 0;
        }
    }

    allContactsPrinter(results);
    return results;
}

void allContactsPrinter(vector<Cantact> dataList) {

    cout << "\n\n __ Users _______________________ \n" << endl;
    for (Cantact item : dataList) {
        cout << item.index << ". "
        << item.name << " "
        << item.lastName << " - " 
        << item.phoneNumber << endl;
    }
    cout << "\n ________________________________ \n" << endl;
    
}

void contactEditor(int changedItemIndex) {

    cout << "\n\n __ Edit ________________________ \n" << endl;

    string newName;
    cout << "Enter new name: " << endl;
    cin >> newName;

    string newLastName;
    cout << "Enter new last name: " << endl;
    cin >> newLastName;

    string newPhoneNumber;
    cout << "Enter new phone numer: " << endl;
    cin >> newPhoneNumber;

    changedItemIndex--;
    users[changedItemIndex].name = newName;
    users[changedItemIndex].lastName = newLastName;
    users[changedItemIndex].phoneNumber = newPhoneNumber;

    cout << "\n __ end _________________________ \n\n" << endl;

}

// g++ PhoneBook.cpp -o PhoneBook
// ./PhoneBook
