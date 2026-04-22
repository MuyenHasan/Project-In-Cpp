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