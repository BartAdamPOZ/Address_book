#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Friend {
    string friendName, friendSurname, friendAddress, friendMail;
    int phoneNumber, friendId;
};

void displayDataAboutFriend(vector<Friend> &friends, int i) {
    cout << "Imie i nazwisko: " << friends[i].friendName << " ";
    cout << friends[i].friendSurname << endl;
    cout << "Telefon: " << friends[i].phoneNumber << endl;
    cout << "E-mail: " << friends[i].friendMail << endl;
    cout << "Adres: " << friends[i].friendAddress << endl;
    cout << endl;
}

void searchByName (vector <Friend> friends) {

    Friend myFriend;
    string nameToSearch;

    cout << "Wprowadz imie szukanego znajomego: ";
    cin >> nameToSearch;

    for (int i = 0; i < friends.size(); i++) {
        if (nameToSearch == friends[i].friendName)
            displayDataAboutFriend(friends, i);
    }
    cout << "Aby kontynuowac nacisnij dowolny klawisz ... ";
    getch();
}

void searchBySurname (vector <Friend> friends) {

    Friend myFriend;
    string surnameToSearch;

    cout << "Wprowadz nazwisko szukanego znajomego: ";
    cin >> surnameToSearch;

    for (int i = 0; i < friends.size(); i++) {
        if (surnameToSearch == friends[i].friendSurname)
            displayDataAboutFriend(friends, i);
    }
    cout << "Aby kontynuowac nacisnij dowolny klawisz ... ";
    getch();
}

void deleteAllDataInFile() {

    fstream file;
    file.open("Ksiazka_adresowa.txt",ios::trunc| ios::in | ios::out);
    file.close();

}

void saveDataToFile (vector <Friend> &friends) {

    fstream file;
    Friend myFriend;

    file.open("Ksiazka_adresowa.txt",ios::out | ios:: app);


    for (int i = 0; i < friends.size(); i++) {

        file << friends[i].friendId << "|";
        file << friends[i].friendName << "|";
        file << friends[i].friendSurname << "|";
        file << friends[i].phoneNumber << "|";
        file << friends[i].friendMail << "|";
        file << friends[i].friendAddress<< "|" << endl;
    }

    file.close();
    friends.shrink_to_fit();
}

void deleteFriendFromList (vector <Friend> &friends) {

    Friend myFriend;
    int idToDelete;
    char choice;
    bool foundOrNot = false;

    do {
        cout << "Wprowadz ID znajomego, ktorego chcesz usunac: ";
        cin >> idToDelete;

        for (int i = 0; i < friends.size(); i++) {
            if (idToDelete == friends[i].friendId) {
                foundOrNot = true;
                displayDataAboutFriend(friends, i);
            }
        }
        if (foundOrNot == false)
            cout << "Bledne dane. Sprobuj ponownie." << endl;

    } while (foundOrNot == false);

    cout << "Czy napewno chcesz usunac tego znajomego? t(tak)/n(nie): ";
    cin >> choice;
    if (choice == 't') {
        for (int i = 0; i < friends.size(); i++) {
            if (idToDelete == friends[i].friendId) {
                auto it = friends.begin() + i;
                friends.erase(it);
                deleteAllDataInFile();
                saveDataToFile(friends);
                cout << "Pomyslnie usunieto znajomego." << endl;
                Sleep(2000);
            }
        }
    }
    friends.shrink_to_fit();
}

void editData (vector <Friend> &friends, int idOfFriendToEdit, char dataToEdit) {

    string name, surname, address, mail;
    int phone;
    Friend myFriend;

    cout << "Wprowadz nowe dane: ";

    if (dataToEdit == '1') {

        cin >> name;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendName = name;
            }
        }
    } else if (dataToEdit == '2') {

        cin >> surname;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendSurname = surname;
            }
        }
    } else if (dataToEdit == '3') {

        cin >> phone;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].phoneNumber = phone;
            }
        }
    } else if (dataToEdit == '4') {

        cin >> mail;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendMail = mail;
            }
        }
    } else if (dataToEdit == '5') {

        cin.sync();
        getline(cin,address);

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                friends[i].friendAddress = address;
            }
        }
    }
    deleteAllDataInFile();
    saveDataToFile(friends);
    cout << "Pomyslanie zmieniono dane znajomego." << endl;
    Sleep(2000);
}

void editDataAboutFriend (vector<Friend> &friends) {

    char choice;
    int idOfFriendToEdit;
    bool foundOrNot = false;

    do {
        cout << "Wprowadz ID znajomego, ktorego dane chcesz edytowac: ";
        cin >> idOfFriendToEdit;

        for (int i = 0; i < friends.size(); i++) {
            if (idOfFriendToEdit == friends[i].friendId) {
                foundOrNot = true;
            }
        }
        if (foundOrNot == false)
            cout << "Bledne dane. Sprobuj ponownie." << endl;

    } while (foundOrNot == false);

    do {
        if(1) {
            system("cls");
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Numer telefonu" << endl;
            cout << "4. Email" << endl;
            cout << "5. Adres" << endl;
            cout << "6. Powrot do menu" << endl;
            cin >> choice;

            if (choice == '1') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '2') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '3') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '4') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '5') {
                editData(friends, idOfFriendToEdit, choice);
            } else if (choice == '6'){
            }
            friends.shrink_to_fit();
        }
    } while (0);
}


void displayFriendsList(vector<Friend> &friends) {

    for (int i = 0; i < friends.size(); i++) {
        displayDataAboutFriend(friends, i);
    }
    cout << "Aby kontynuowac nacisnij dowolny klawisz ... ";
    getch();
}

void readDataFromFile (vector <Friend> &friends) {

    Friend myFriend;

    fstream file;
    file.open("Ksiazka_adresowa.txt", ios::out | ios:: app);
    file.close();

    file.open("Ksiazka_adresowa.txt", ios::in);

    if(file.good() == false) {
        cout << "Plik nie istnieje!";
        exit(0);
    }

    string line;
    int item = 1;

    while (getline (file, line, '|')) {
        switch (item) {
        case 1:
            myFriend.friendId = atoi(line.c_str());
            break;
        case 2:
            myFriend.friendName = line;
            break;
        case 3:
            myFriend.friendSurname = line;
            break;
        case 4:
            myFriend.phoneNumber = atoi(line.c_str());
            break;
        case 5:
            myFriend.friendMail = line;
            break;
        case 6:
            myFriend.friendAddress = line;
            break;
        }
        if(item == 6) {
            item = 1;
            friends.push_back(myFriend);
        } else {
            item++;
        }
    }
    file << endl;
    file.close();
}

void addNewFriend (vector <Friend> &friends) {

    string name, surname, address, mail;
    int phone, id;
    Friend myFriend;

    cout << "Dodaj swojego znajomego! Wprowadz dane ponizej: " << endl;

    cout << "Imie: ";
    cin >> name;
    cout << "Nazwisko: ";
    cin >> surname;
    cout << "mail: ";
    cin >> mail;
    cout << "telefon: ";
    cin >> phone;
    cout << "Adres: ";
    cin.sync();
    getline(cin, address);

    if (friends.size() == 0) {
        id = 1;
    } else {
        id = friends[friends.size() - 1].friendId + 1;
    }

    myFriend.friendId = id;
    myFriend.friendName = name;
    myFriend.friendSurname = surname;
    myFriend.friendAddress = address;
    myFriend.friendMail = mail;
    myFriend.phoneNumber = phone;

    friends.push_back(myFriend);
    cout << "Pomyslnie dodano znajomego!";
    Sleep(2000);

    fstream file;
    file.open("Ksiazka_adresowa.txt",ios::out | ios:: app);


    file << id << "|";
    file << name << "|";
    file << surname<< "|";
    file << phone << "|";
    file << mail << "|";
    file << address<< "|" << endl;

    file.close();
}

int main() {
    char choice = 0;
    vector<Friend> friends;

    readDataFromFile(friends);

    while(1) {
        if(1) {
            system("cls");
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkich adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "9. Zakoncz program" << endl;
            cin >> choice;

            if (choice == '1') {
                addNewFriend(friends);
            } else if (choice == '2') {
                searchByName(friends);
            } else if (choice == '3') {
                searchBySurname(friends);
            } else if (choice == '4') {
                displayFriendsList(friends);
            } else if (choice == '5') {
                deleteFriendFromList(friends);
            } else if (choice == '6') {
                editDataAboutFriend(friends);
            } else if (choice == '9') {
                exit(0);
            }
        }
    }
    return 0;
}
