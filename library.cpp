#include <iostream>
#include <fstream>
#include <cstdio>
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