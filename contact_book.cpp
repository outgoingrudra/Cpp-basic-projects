
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;

// Load contacts from file
void loadContacts() {
    ifstream file("contacts.txt");
    if (!file) return;

    Contact c;
    while (getline(file, c.name) && getline(file, c.phone) && getline(file, c.email)) {
        contacts.push_back(c);
    }
    file.close();
}

// Save contacts to file
void saveContacts() {
    ofstream file("contacts.txt");
    for (const auto& c : contacts) {
        file << c.name << '\n' << c.phone << '\n' << c.email << '\n';
    }
    file.close();
}

// Add new contact
void addContact() {
    Contact c;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter Phone: ";
    getline(cin, c.phone);
    cout << "Enter Email: ";
    getline(cin, c.email);
    contacts.push_back(c);
    cout << "Contact added.\n";
}

// Display all contacts
void displayContacts() {
    if (contacts.empty()) {
        cout << "No contacts found.\n";
        return;
    }
    for (const auto& c : contacts) {
        cout << "\nName: " << c.name << "\nPhone: " << c.phone << "\nEmail: " << c.email << '\n';
    }
}

// Search contact by name
void searchContact() {
    string keyword;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, keyword);
    bool found = false;
    for (const auto& c : contacts) {
        if (c.name.find(keyword) != string::npos) {
            cout << "\nName: " << c.name << "\nPhone: " << c.phone << "\nEmail: " << c.email << '\n';
            found = true;
        }
    }
    if (!found) cout << "No contact found with that name.\n";
}

// Delete contact by name
void deleteContact() {
    string keyword;
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, keyword);
    auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact& c) {
        return c.name == keyword;
    });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted.\n";
    } else {
        cout << "Contact not found.\n";
    }
}

int main() {
    loadContacts();
    int choice;
    do {
        cout << "\n--- Contact Book ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 0: saveContacts(); cout << "Contacts saved. Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
