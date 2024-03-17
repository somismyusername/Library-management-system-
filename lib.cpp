//We have implemented library management system with following operations.
//Adding a book record.
//Searching for a book record.
//Updating a book record.
//Deleting a book record.
//Borrowing or returning book record.
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//#include <conio.h>
using namespace std;

struct Node
{
    string id;
    string name;
    string author;
    string publisher;
    bool borrowed;
    string borrower_id;
    Node *next;
};

struct User
{
    string id;
    string name;
    list<string> borrowed_books;
    double fine_amount;
};

class Library
{
private:
    list<User> users;
    set<string> hashSet;

public:
    Node *head = NULL;
    void menu()
    {
        while (true)
        {
            system("cls");
            int choice;
            cout << "\n\n\t\t\t====================================";
            cout << "\n\n\t\t\t=====LIBRARY MANAGEMENT SYSTEM======";
            cout << "\n\n\t\t\t====================================";
            cout << "\n\n 1. Insert New Record";
            cout << "\n\n 2. Search Record";
            cout << "\n\n 3. Update Record";
            cout << "\n\n 4. Delete Record";
            cout << "\n\n 5. Borrowing and Returning Books";
            cout << "\n\n 6. Exit";

            cout << "\n\n Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                insert_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                update_record();
                break;
            case 4:
                del_record();
                break;
            case 5:
                borrow_or_return_book();
                break;

            case 6:
                exit(0);
            default:
                cout << "Wrong choice! Please select a valid option: ";
            }
        }
    }

    void insert_record()
    {
        system("CLS");
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t=====LIBRARY MANAGEMENT SYSTEM======";
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t===========INSERT RECORD============";
        string inpID;
        Node *newNode = new Node;
        cout << "\n\n\nEnter the book ID: ";
        cin >> inpID;
        if (hashSet.find(inpID) != hashSet.end())
        {
            cout << "\n\nDuplicate ID issue: A book of the ID exits";
        }
        else
        {
            hashSet.insert(inpID);
            newNode->id = inpID;
            cout << "\nEnter the book name: ";
            cin >> newNode->name;
            cout << "\nEnter the author name: ";
            cin >> newNode->author;
            cout << "\nEnter the publisher name: ";
            cin >> newNode->publisher;
            newNode->next = NULL;
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }
            cout << "\n\nNew book is inserted succesfully......";
        }
        cout << "\n\nEnter 0 to exit or any other key to continue: ";
        string s;
        cin >> s;

        if (s != "0")
        {
            insert_record();
        }
    }

    void search_record()
    {
        string inpID;
        system("CLS");
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t=====LIBRARY MANAGEMENT SYSTEM======";
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t===========SEARCH RECORD============";
        if (head == NULL)
        {
            cout << "\n\nThere are no books to search: ";
        }
        else
        {
            cout << "\n\nBook ID: ";
            cin >> inpID;
            Node *ptr = head;
            while (ptr != NULL && ptr->id != inpID)
            {
                ptr = ptr->next;
            }
            if (ptr == NULL)
                cout << "\nBook not found.... ";
            else
            {
                cout << "\n\n Book ID   :" << ptr->id;
                cout << "\n\n Book Name :" << ptr->name;
                cout << "\n\n Author    :" << ptr->author;
                cout << "\n\n Publisher :" << ptr->publisher;
            }
        }
        cout << "\n\nEnter 0 to exit or any other key to continue: ";
        string s;
        cin >> s;

        if (s != "0")
        {
            search_record();
        }
    }

    void update_record()
    {
        system("CLS");
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t=====LIBRARY MANAGEMENT SYSTEM======";
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t===========UPDATE RECORD============";
        string inpID;
        if (head == NULL)
        {
            cout << "\n\nThere are no books to update: ";
        }
        else
        {
            cout << "\n\nBook ID: ";
            cin >> inpID;
            Node *ptr = head;
            while (ptr != NULL && ptr->id != inpID)
            {
                ptr = ptr->next;
            }
            if (ptr == NULL)
                cout << "\nBook not found.... ";
            else
            {
                cout << "\n\n Enter the updated book ID   :";
                cin >> ptr->id;
                cout << "\n\n Enter the updated book Name :";
                cin >> ptr->name;
                cout << "\n\n Enter the updated author    :";
                cin >> ptr->author;
                cout << "\n\n Enter the updated publisher :";
                cin >> ptr->publisher;

                cout << "\n\n \t\t Updated the book records succesfully.......";
            }
        }
        cout << "\n\nEnter 0 to exit or any other key to continue: ";
        string s;
        cin >> s;

        if (s != "0")
        {
            update_record();
        }
    }

    void del_record()
    {
        system("CLS");
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t=====LIBRARY MANAGEMENT SYSTEM======";
        cout << "\n\n\t\t\t====================================";
        cout << "\n\n\t\t\t===========DELETE RECORD============";
        if (head == nullptr)
        {
            cout << "\n\nThere are no books to delete.\n";
        }
        else
        {
            string inpID;
            cout << "\n\nEnter Book ID: ";
            cin >> inpID;

            bool found = false;
            Node *temp = head;
            Node *prev = nullptr;

            while (temp != nullptr)
            {
                if (temp->id == inpID)
                {
                    found = true;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if (!found)
            {
                cout << "\n\nBook ID \"" << inpID << "\" not found.\n";
            }
            else
            {
                if (prev == nullptr)
                {
                    head = head->next;
                    delete temp;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                }
                cout << "\n\nBook ID \"" << inpID << "\" deleted successfully.\n";
            }
        }
        cout << "\n\nEnter 0 to exit or any other key to continue: ";
        string s;
        cin >> s;

        if (s != "0")
        {
            del_record();
        }
    }

    void borrow_or_return_book()
    {
        int choice;
        cout << "\n1. Borrow a book ";
        cout << "\n2. Return a book ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            borrow_book();
            break;
        case 2:
            return_book();
            break;
        default:
            cout << "Invalid choice!";
        }
    }

    void borrow_book()
    {
        string book_id;
        cout << "Enter book ID: ";
        cin >> book_id;

        Node *book = find_book(book_id);
        if (book == nullptr)
        {
            cout << "Book not found!";
            cout << "\n\nEnter 0 to to return to main menu ";
            string s = "1";

            while (s != "0")
                cin >> s;
            return;
        }

        if (book->borrowed)
        {
            cout << "Book already borrowed!";
            cout << "\n\nEnter 0 to to return to main menu ";
            string s = "1";

            while (s != "0")
                cin >> s;
            return;
        }

        string user_id;
        cout << "Enter user ID: ";
        cin >> user_id;

        book->borrowed = true;
        book->borrower_id = user_id;

        cout << "Book borrowed successfully!";
        cout << "\n\nEnter 0 to to return to main menu ";
        string s = "1";

        while (s != "0")
            cin >> s;
    }

    void return_book()
    {
        string book_id;
        cout << "Enter book ID: ";
        cin >> book_id;

        Node *book = find_book(book_id);
        if (book == nullptr)
        {
            cout << "Book not found!";
            cout << "\n\nEnter 0 to to return to main menu ";
            string s = "1";

            while (s != "0")
                cin >> s;
            return;
        }

        if (!book->borrowed)
        {
            cout << "Book is not borrowed!";
            cout << "\n\nEnter 0 to to return to main menu ";
            string s = "1";

            while (s != "0")
                cin >> s;
            return;
        }

        cout << "Book returned successfully!";
        cout << "\n\nEnter 0 to to return to main menu ";
        string s = "1";

        while (s != "0")
            cin >> s;
    }
    Node *find_book(const string &book_id)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->id == book_id)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

int main()
{
    Library obj;
    obj.menu();
    return 0;
}