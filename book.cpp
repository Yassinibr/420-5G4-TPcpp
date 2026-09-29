#include "book.h"

using namespace std;

Book::Book()
    : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {
}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerId() const {
    return borrowerId;
}

void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setISBN(const string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool available) {
    isAvailable = available;
}

void Book::setBorrowerId(const string& id) {
    borrowerId = id;
}

void Book::checkOut(const string& borrowerId) {
    if (isAvailable) {
        isAvailable = false;
        this->borrowerId = borrowerId;
    }
}

void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}

string Book::toString() const {
    string result = "Title: " + title +
                    ", Author: " + author +
                    ", ISBN: " + isbn +
                    ", Available: " + (isAvailable ? "Yes" : "No");

    if (!isAvailable) {
        result += ", Borrower ID: " + borrowerId;
    }

    return result;
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" +
           (isAvailable ? "1" : "0") + "|" + borrowerId;
}

void Book::fromFileFormat(const string& line) {
    size_t pos1 = line.find('|');
    size_t pos2 = line.find('|', pos1 + 1);
    size_t pos3 = line.find('|', pos2 + 1);
    size_t pos4 = line.find('|', pos3 + 1);

    title = line.substr(0, pos1);
    author = line.substr(pos1 + 1, pos2 - pos1 - 1);
    isbn = line.substr(pos2 + 1, pos3 - pos2 - 1);
    isAvailable = line.substr(pos3 + 1, pos4 - pos3 - 1) == "1";
    borrowerId = line.substr(pos4 + 1);
}