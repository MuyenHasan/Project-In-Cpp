#include <iostream>
#include <fstream>
#include <cstdio>   // for remove & rename
using namespace std;

// Add Book
void addBook() {
    string id, name, author;

    cout << "\nEnter Book ID: ";
    getline(cin, id);
    cout << "Enter Book Name: ";
    getline(cin, name);
    cout << "Enter Author Name: ";
    getline(cin, author);

    ofstream file("bookData.txt", ios::app);
    file << id << "*" << name << "*" << author << "*Available\n";
    file.close();

    cout << "Book Added Successfully!\n";
}

// Show All Books
void showAll() {
    string id, name, author, status;
    ifstream file("bookData.txt");

    cout << "\nID\tName\tAuthor\tStatus\n";
    cout << "----------------------------------------\n";

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author, '*') &&
           getline(file, status)) {

        cout << id << "\t" << name << "\t" << author << "\t" << status << endl;
    }

    file.close();
}

// Search Book
void searchBook() {
    string search, id, name, author, status;
    bool found = false;

    cout << "Enter Book ID: ";
    getline(cin, search);

    ifstream file("bookData.txt");

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author, '*') &&
           getline(file, status)) {

        if (id == search) {
            cout << "\nBook Found:\n";
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Author: " << author << endl;
            cout << "Status: " << status << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found!\n";

    file.close();
}

// Issue Book
void issueBook() {
    string search, id, name, author, status;
    bool found = false;

    cout << "Enter Book ID to Issue: ";
    getline(cin, search);

    ifstream file("bookData.txt");
    ofstream temp("temp.txt");

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author, '*') &&
           getline(file, status)) {

        if (id == search) {
            found = true;
            if (status == "Available") {
                status = "Issued";
                cout << "Book Issued Successfully!\n";
            } else {
                cout << "Book already issued!\n";
            }
        }

        temp << id << "*" << name << "*" << author << "*" << status << endl;
    }

    file.close();
    temp.close();

    remove("bookData.txt");
    rename("temp.txt", "bookData.txt");

    if (!found)
        cout << "Book not found!\n";
}

// Return Book
void returnBook() {
    string search, id, name, author, status;
    bool found = false;

    cout << "Enter Book ID to Return: ";
    getline(cin, search);

    ifstream file("bookData.txt");
    ofstream temp("temp.txt");

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author, '*') &&
           getline(file, status)) {

        if (id == search) {
            found = true;
            if (status == "Issued") {
                status = "Available";
                cout << "Book Returned Successfully!\n";
            } else {
                cout << "Book was not issued!\n";
            }
        }

        temp << id << "*" << name << "*" << author << "*" << status << endl;
    }

    file.close();
    temp.close();

    remove("bookData.txt");
    rename("temp.txt", "bookData.txt");

    if (!found)
        cout << "Book not found!\n";
}

// Main Menu
int main() {
    char choice;

    do {
        cout << "\n====== Library Menu ======\n";
        cout << "1. Show All Books\n";
        cout << "2. Search Book\n";
        cout << "3. Add Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': showAll(); break;
            case '2': searchBook(); break;
            case '3': addBook(); break;
            case '4': issueBook(); break;
            case '5': returnBook(); break;
            case '6': cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != '6');

    return 0;
}