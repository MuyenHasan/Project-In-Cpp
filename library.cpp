#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <windows.h>
using namespace std;


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

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

    setColor(10);
    cout << "Book Added Successfully!\n";
    setColor(7);
}

// Show All Books
void showAll() {
    string id, name, author, status;
    ifstream file("bookData.txt");

    setColor(11);
    cout << "\n================= LIBRARY BOOK LIST =================\n";

    setColor(14);
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Author"
         << setw(12) << "Status" << endl;

    setColor(7);
    cout << "--------------------------------------------------------------\n";

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author, '*') &&
           getline(file, status)) {

        if (status == "Available")
            setColor(10); // Green
        else
            setColor(12); // Red

        cout << left << setw(10) << id
             << setw(25) << name
             << setw(20) << author
             << setw(12) << status << endl;

        setColor(7);
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
            setColor(11);
            cout << "\nBook Found:\n";

            setColor(14);
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Author: " << author << endl;
            cout << "Status: " << status << endl;

            setColor(7);
            found = true;
            break;
        }
    }

    if (!found) {
        setColor(12);
        cout << "Book not found!\n";
        setColor(7);
    }

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
                setColor(10);
                cout << "Book Issued Successfully!\n";
            } else {
                setColor(12);
                cout << "Book already issued!\n";
            }
            setColor(7);
        }

        temp << id << "*" << name << "*" << author << "*" << status << endl;
    }

    file.close();
    temp.close();

    remove("bookData.txt");
    rename("temp.txt", "bookData.txt");

    if (!found) {
        setColor(12);
        cout << "Book not found!\n";
        setColor(7);
    }
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
                setColor(10);
                cout << "Book Returned Successfully!\n";
            } else {
                setColor(12);
                cout << "Book was not issued!\n";
            }
            setColor(7);
        }

        temp << id << "*" << name << "*" << author << "*" << status << endl;
    }

    file.close();
    temp.close();

    remove("bookData.txt");
    rename("temp.txt", "bookData.txt");

    if (!found) {
        setColor(12);
        cout << "Book not found!\n";
        setColor(7);
    }
}

// Main Menu
int main() {
    char choice;

    do {
        setColor(11);
        cout << "\n====== LIBRARY MENU ======\n";

        setColor(14);
        cout << "1. Show All Books\n";
        cout << "2. Search Book\n";
        cout << "3. Add Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        setColor(7);
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