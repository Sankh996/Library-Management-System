#include <iostream>
#include <string>
using namespace std;

// Structure 
struct Book {
    int id;
    string name;
    string author;
    int quantity;
};

Book books[100];   // Array (DSA concept)
int count = 0;

// Add Book
void addBook() {
    cout << "\nEnter Book ID: ";
    cin >> books[count].id;

    cin.ignore(); // clear buffer

    cout << "Enter Book Name: ";
    getline(cin, books[count].name);

    cout << "Enter Author Name: ";
    getline(cin, books[count].author);

    cout << "Enter Quantity: ";
    cin >> books[count].quantity;

    count++;

    cout << "✅ Book Added Successfully!\n";
}

// View Books
void viewBooks() {
    if (count == 0) {
        cout << "No books available!\n";
        return;
    }

    cout << "\n===== Book List =====\n";

    for (int i = 0; i < count; i++) {
        cout << "\nID: " << books[i].id;
        cout << "\nName: " << books[i].name;
        cout << "\nAuthor: " << books[i].author;
        cout << "\nQuantity: " << books[i].quantity << "\n";
    }
}

// Search Book (Linear Search)
void searchBook() {
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            cout << "\n✅ Book Found!";
            cout << "\nID: " << books[i].id;
            cout << "\nName: " << books[i].name;
            cout << "\nAuthor: " << books[i].author;
            cout << "\nQuantity: " << books[i].quantity << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "❌ Book Not Found!\n";
}

// Issue Book
void issueBook() {
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].quantity > 0) {
                books[i].quantity--;
                cout << "✅ Book Issued Successfully!\n";
            } else {
                cout << "❌ Book Not Available!\n";
            }
            found = true;
            break;
        }
    }

    if (!found)
        cout << "❌ Book Not Found!\n";
}

// Return Book
void returnBook() {
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            books[i].quantity++;
            cout << "✅ Book Returned Successfully!\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "❌ Book Not Found!\n";
}

// Main Function
int main() {
    int choice;

    while (true) {
        cout << "\n\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}