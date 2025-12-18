# include <iostream>
# include <vector>
using namespace std;
class Cantact {
    public:

        string name;
        string lastName;
        string phoneNumber;

        Cantact(string nameInput, string lastNameInput, string phoneNumberInput) {
            name = nameInput;
            lastName = lastNameInput;
            phoneNumber = phoneNumberInput;
        }

    void itemsPrinter() {
        cout << "Name: " << name << "Last name: " << lastName << "Phone number: " << phoneNumber << endl;
    }
};

vector<Cantact> users;

int contactEditor();
void allContactsPrinter(vector<Cantact> dataList);
vector<Cantact> searcherByName (string searchByName);
vector<Cantact> searcherByPhoneNumber(string searchByPhoneNumber);
void creatorContact(string name, string lastName, string phoneNumber);


int main() {

    int operationId;

    while (true) {
        cout << "0. Shoow  items \n"
        << "1. Add contact \n"
        << "2. Edit contact \n"
        << "3. Search contact by name \n"
        << "4. Search contact by phone number" << endl;

        cout << "Enter your operation number: ";
        cin >> operationId;

        if ( operationId == 0 ) {
            allContactsPrinter(users);
        } else if ( operationId == 1 ) {

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
        } else if ( operationId == 2 ) {
            contactEditor();
        } else if ( operationId == 3 ) {

            string nameInputForSearch;
            cin >> nameInputForSearch;

            searcherByName(nameInputForSearch);
        } else if ( operationId == 4 ) {
            string phoneNumberInputForSearch;
            cin >> phoneNumberInputForSearch;

            searcherByPhoneNumber(phoneNumberInputForSearch);
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

int contactEditor() {
    return 0;
}

vector<Cantact> searcherByName (string searchByName) {

    vector<Cantact> results;
    int resultLenght = 0;

    for (Cantact item : users) {
        if (item.name.length() >= searchByName.length()) {
            for (int i = 0; i < searchByName.length(); i++) {
                if (item.name[i] == searchByName[i]) {
                    cout << "\n\n" << item.name[i] << " == " << searchByName[i] << endl;
                    resultLenght++;
                }
            }
            if (resultLenght == searchByName.length()) {
                cout << resultLenght << " - " << searchByName << endl;
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

vector<Cantact> searcherByLastName (string searchByLastName) {

    vector<Cantact> results;
    int resultLenght = 0;

    for (Cantact item : users) {
        if (item.lastName.length() >= searchByLastName.length()) {
            for (int i = 0; i < searchByLastName.length(); i++) {
                if (item.lastName[i] == searchByLastName[i]) {
                    cout << "\n\n" << item.lastName[i] << " == " << searchByLastName[i] << endl;
                    resultLenght++;
                }
            }
            if (resultLenght == searchByLastName.length()) {
                cout << resultLenght << " - " << searchByLastName << endl;
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
    for (Cantact item : dataList) {
        cout << item.name << " "
        << item.lastName << " - " 
        << item.phoneNumber << endl;
    }
    
}

// g++ PhoneBook.cpp -o PhoneBook
// ./PhoneBook
