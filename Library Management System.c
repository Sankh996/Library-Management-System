#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int quantity;
};

void addBook();
void viewBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;
    while (1) {
        printf("\n\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void addBook() {
    struct Book b;
    FILE *fp = fopen("books.dat", "ab");

    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    getchar();
    fgets(b.name, 50, stdin);

    printf("Enter Author Name: ");
    fgets(b.author, 50, stdin);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book Added Successfully!\n");
}

void viewBooks() {
    struct Book b;
    FILE *fp = fopen("books.dat", "rb");

    if (!fp) {
        printf("No books found!\n");
        return;
    }

    printf("\n===== Book List =====\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("\nID: %d", b.id);
        printf("\nName: %s", b.name);
        printf("Author: %s", b.author);
        printf("Quantity: %d\n", b.quantity);
    }
    fclose(fp);
}

void searchBook() {
    struct Book b;
    FILE *fp = fopen("books.dat", "rb");
    int id, found = 0;

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found!");
            printf("\nID: %d", b.id);
            printf("\nName: %s", b.name);
            printf("Author: %s", b.author);
            printf("Quantity: %d\n", b.quantity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book Not Found!\n");

    fclose(fp);
}

void issueBook() {
    struct Book b;
    FILE *fp = fopen("books.dat", "rb+");
    int id, found = 0;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            if (b.quantity > 0) {
                b.quantity--;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book Issued Successfully!\n");
            } else {
                printf("Book Not Available!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) printf("Book Not Found!\n");

    fclose(fp);
}

void returnBook() {
    struct Book b;
    FILE *fp = fopen("books.dat", "rb+");
    int id, found = 0;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            b.quantity++;
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            printf("Book Returned Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Book Not Found!\n");

    fclose(fp);
}
