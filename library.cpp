#include <bits/stdc++.h>
#define ll long long
#define rep(i, _size) for (int i = 0; i < _size; i++)
using namespace std;


class Date {
public:
    int day   = 1;
    int month = 1;
    int year  = 2000;

    // difference_in_days(other_date)
    // is_before(other_date)
    // display()
};


class Book {
public:
    string title   = "No title given";
    string author  = "No author given";
    bool   available = false;
    int    copies    = 0;

    // check_availability()
    // update_details(title, author, genre)
    // display_info()
};


class Member {
public:
    int    mID   = 1;
    string name  = "No name given";
    string email = "No email given";
    vector<Book> borrowed_books;

    // borrow_book(book, library)
    // return_book(book, library)
    // display_borrowed_books()
};


class Student : public Member {
    // inherits Member
    // different borrow limit
};


class Teacher : public Member {
    // inherits Member
    // different fine rules
};


class Password {
private:
    string pass;

public:
    // set_password(pass)
    // verify_password(input)
};


class Librarian {
public:
    string   name = "No name given";
    int      eID  = 1;
    Password password;

    // add_book(book, library)
    // remove_book(book_id, library)
    // update_book(book_id, new_details)
    // register_member(member, library)
    // remove_member(member_id, library)
};


class Transaction {
public:
    string  tID    = "No transaction ID";
    Member  member;
    Book    book;
    Date    issue_date;
    Date    due_date;
    Date    return_date;
    float   fine = 0.0;

    // calculate_fine()   → based on (return_date - due_date)
    // display_transaction()
};


class Library {
public:
    vector<Book>        books;
    vector<Member>      members;
    vector<Transaction> transactions;
    vector<Librarian>   employees;

    // search_book_by_title(title)
    // search_book_by_author(author)
    // issue_book(book_id, member_id)
    // return_book(book_id, member_id)
    // display_all_books()
    // display_all_members()
    // display_overdue_books()
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Welcome to our library 'Your second home'\n\n";

    return 0;
}
