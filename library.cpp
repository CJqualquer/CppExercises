#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Library {
public:
    std::string nameBook;
    std::string author;
    int publicationYear{};
    int numberOfPages{};
};

// Function declarations
int readInt(const std::string &prompt);
void displayBook(const Library &book);
void displayMenu(int &choice);
void switchCase(int choice, std::vector<Library> &books);

// ------------------------------------------------------------

int main() {
    int choice;
    std::vector<Library> books;

    do {
        displayMenu(choice);
        switchCase(choice, books);
    } while (choice != 3);

    return 0;
}

// ------------------------------------------------------------

int readInt(const std::string &prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else return value;
    }
}

// ------------------------------------------------------------

void displayBook(const Library &book) {
    std::cout << "\nName: " << book.nameBook
              << "\nAuthor: " << book.author
              << "\nYear: " << book.publicationYear
              << "\nPages: " << book.numberOfPages << "\n";
}

// ------------------------------------------------------------

void displayMenu(int &choice) {
    while (true) {

        std::cout << "\n********** Library Menu **********\n";
        std::cout << "1. Add a new book\n";
        std::cout << "2. View or search books\n";
        std::cout << "3. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 3) {
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

// ------------------------------------------------------------

void switchCase(int choice, std::vector<Library> &books) {
    switch (choice) {
        case 1: {
            Library newBook;
            std::cout << "\nAdding a new book...\n";

            std::cout << "Enter book name: ";
            std::getline(std::cin >> std::ws, newBook.nameBook);
            std::cout << "Enter author name: ";
            std::getline(std::cin >> std::ws, newBook.author);
            newBook.publicationYear = readInt("Enter publication year: ");
            newBook.numberOfPages = readInt("Enter number of pages: ");

            books.push_back(newBook);
            std::cout << "\nBook added successfully!\n";
            break;
        }

        case 2: {
            if (books.empty()) {
                std::cout << "\nNo books in the library yet.\n";
                break;
            }

            std::string searchType;
            std::cout << "\nSearch by (name / author / year / all): ";
            std::cin >> searchType;

            bool found = false;

            if (searchType == "all") {
                for (const auto &book : books) displayBook(book);
                break;
            } 
            else if (searchType == "name") {
                std::string name;
                std::cout << "Enter the book name: ";
                std::getline(std::cin >> std::ws, name);
                for (const auto &book : books)
                    if (book.nameBook == name) { displayBook(book); found = true; }
            } 
            else if (searchType == "author") {
                std::string author;
                std::cout << "Enter the author name: ";
                std::getline(std::cin >> std::ws, author);
                for (const auto &book : books)
                    if (book.author == author) { displayBook(book); found = true; }
            } 
            else if (searchType == "year") {
                int year = readInt("Enter the publication year: ");
                for (const auto &book : books)
                    if (book.publicationYear == year) { displayBook(book); found = true; }
            } 
            else {
                std::cout << "\nInvalid search type! Try 'name', 'author', 'year' or 'all'.\n";
            }

            if (!found && searchType != "all")
                std::cout << "\nNo matching books found.\n";

            break;
        }

        case 3:
            std::cout << "Exiting the program. Goodbye!\n";
            break;

        default:
            std::cout << "\nInvalid option!\n";
            break;
    }
}