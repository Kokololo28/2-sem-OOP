#include <iostream>
#include <map>
#include <string>
#define NL std::cout << '\n' 
using namespace std;


class Book 
{
public:
    string authorLastName;
    string authorInitials;
    string title;
    int year;

    Book(string _authorLastName, string _authorInitials, string _title, int _year) 
    {
        authorLastName = _authorLastName;
        authorInitials = _authorInitials;
        title = _title;
        year = _year;
    }
};

class Library 
{
private:
    multimap<string, Book> books;

public:
    void addBook(string authorLastName, string authorInitials, string title, int year) 
    {
        Book book(authorLastName, authorInitials, title, year);
        books.insert(pair<string, Book>(authorLastName, book));
    }

    void removeBook(string authorLastName, string title) 
    {
        auto range = books.equal_range(authorLastName);
        for (auto it = range.first; it != range.second; ++it) 
        {
            if (it->second.title == title) 
            {
                books.erase(it);
                break;
            }
        }
    }

    void printAllBooks() 
    {
        for (auto it = books.begin(); it != books.end(); ++it) 
        {
            cout << it->second.title << " by " << it->second.authorLastName << ", "
                << it->second.authorInitials << ", " << it->second.year << endl;
        }
    }

    void printBooksByAuthor(string authorLastName) 
    {
        auto range = books.equal_range(authorLastName);
        for (auto it = range.first; it != range.second; ++it) 
        {
            cout << it->second.title << " by " << it->second.authorLastName << ", "
                << it->second.authorInitials << ", " << it->second.year << endl;
        }
    }

    void printBooksByYear(int year) 
    {
        for (auto it = books.begin(); it != books.end(); ++it) 
        {
            if (it->second.year == year) 
            {
                cout << it->second.title << " by " << it->second.authorLastName << ", "
                    << it->second.authorInitials << ", " << it->second.year << endl;
            }
        }
    }
};

void main()
{
    Library library;

    // додавання книг до бібліотеки
    library.addBook("Hemingway", "E.", "The Old Man and the Sea", 1952);
    library.addBook("Hemingway", "E.", "For Whom the Bell Tolls", 1940);
    library.addBook("Fitzgerald", "F.", "The Great Gatsby", 1925);
    library.addBook("Fitzgerald", "F.", "Tender Is the Night", 1934);

    // виведення всіх книг у бібліотеці
    cout << "All books in the library: " << endl;
    library.printAllBooks();
    cout << endl;

    // видалення книги з бібліотеки
    cout << "Removing Tender Is the Night by Fitzgerald" << endl;
    library.removeBook("Fitzgerald", "Tender Is the Night");
    cout << endl;
    cout << "All books in the library: " << endl;
    library.printAllBooks();
    cout << endl;

    // виведення книг певного автора
    cout << "Books by Hemingway: " << endl;
    library.printBooksByAuthor("Hemingway");
    cout << endl;
            
    // виведення книг за певний рік
    cout << "Books published in 1940: " << endl;
    library.printBooksByYear(1940);
    system("pause");
}
