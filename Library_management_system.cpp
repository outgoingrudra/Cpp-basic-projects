// LibraryManagementSystem.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book() {}
    Book(int _id, string _title, string _author, bool _isIssued = false) {
        id = _id;
        title = _title;
        author = _author;
        isIssued = _isIssued;
    }
};

class Library {
private:
    vector<Book> books;
    string filename = "books.txt";

public:
    Library() {
        loadFromFile();
    }

    void loadFromFile() {
        ifstream inFile(filename);
        books.clear();
        int id;
        string title, author;
        bool issued;
        while (inFile >> id) {
            inFile.ignore();
            getline(inFile, title);
            getline(inFile, author);
            inFile >> issued;
            books.push_back(Book(id, title, author, issued));
        }
        inFile.close();
    }

    void saveToFile() {
        ofstream outFile(filename);
        for (Book b : books) {
            outFile << b.id << endl
                    << b.title << endl
                    << b.author << endl
                    << b.isIssued << endl;
        }
        outFile.close();
    }

    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: "; cin >> id; cin.ignore();
        cout << "Enter Book Title: "; getline(cin, title);
        cout << "Enter Author Name: "; getline(cin, author);

        books.push_back(Book(id, title, author));
        saveToFile();
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        cout << "\n--- All Books ---\n";
        for (Book b : books) {
            cout << "ID: " << b.id
                 << ", Title: " << b.title
                 << ", Author: " << b.author
                 << ", Issued: " << (b.isIssued ? "Yes" : "No") << endl;
        }
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: "; cin >> id;
        for (Book b : books) {
            if (b.id == id) {
                cout << "Found - Title: " << b.title << ", Author: " << b.author << ", Issued: " << (b.isIssued ? "Yes" : "No") << endl;
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: "; cin >> id;
        for (Book &b : books) {
            if (b.id == id && !b.isIssued) {
                b.isIssued = true;
                saveToFile();
                cout << "Book issued successfully!\n";
                return;
            } else if (b.id == id) {
                cout << "Book is already issued!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: "; cin >> id;
        for (Book &b : books) {
            if (b.id == id && b.isIssued) {
                b.isIssued = false;
                saveToFile();
                cout << "Book returned successfully!\n";
                return;
            } else if (b.id == id) {
                cout << "Book was not issued.\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: "; cin >> id;
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                saveToFile();
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    int choice;
    do {
        cout << "\n\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Display All Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Delete Book\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.issueBook(); break;
            case 5: lib.returnBook(); break;
            case 6: lib.deleteBook(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
