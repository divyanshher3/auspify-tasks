#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct library {
    int id;
    string Bookname;
    bool BookIssueed = false;
};

const string FILE_NAME = "books.txt";

//TO save thye file
void saveToFile(const vector<library>& librarys) {
    ofstream out(FILE_NAME);
    if (!out) {
        cout << "Error: could not open file for saving!" << endl;
        return;
    }
    for (const library& lb : librarys) {
        out << lb.id << " " << lb.BookIssueed << " " << lb.Bookname << "\n";
    }
}

// read the file
void loadFromFile(vector<library>& librarys) {
    ifstream in(FILE_NAME);
    if (!in) return;               // first run: file doesn't exist yet

    library l;
    int issued;
    while (in >> l.id >> issued) {
        l.BookIssueed = (issued == 1);
        getline(in >> ws, l.Bookname);  
        librarys.push_back(l);
    }
}

// ---------- LIBRARY OPERATIONS ----------

void addbook(vector<library>& librarys) {          // non-const: we modify it
    library l;
    cout << "Enter the ID: ";
    cin >> l.id;

    for (const library& lb : librarys) {
        if (lb.id == l.id) {
            cout << "ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter the name of the book: ";
    getline(cin >> ws, l.Bookname);

    librarys.push_back(l);
    cout << "Book added successfully!" << endl;
}

void Displaybook(const vector<library>& librarys) {
    if (librarys.empty()) {
        cout << "Library is empty!" << endl;
        return;
    }
    for (const library& lb : librarys) {
        cout << "Book ID   -> " << lb.id << endl;
        cout << "Book name -> " << lb.Bookname << endl;
        cout << "Issued    -> " << (lb.BookIssueed ? "Yes" : "No") << endl;
        cout << "-----------------------------------" << endl;
    }
}

// Step 5 of the task: show only books that are available
void DisplayAvailable(const vector<library>& librarys) {
    bool any = false;
    for (const library& lb : librarys) {
        if (!lb.BookIssueed) {
            cout << "Book ID   -> " << lb.id << endl;
            cout << "Book name -> " << lb.Bookname << endl;
            cout << "-----------------------------------" << endl;
            any = true;
        }
    }
    if (!any) cout << "No books available right now." << endl;
}

void Searchbookbyid(const vector<library>& librarys) {
    int id;
    cout << "Enter the ID of the book: ";
    cin >> id;
    for (const library& lb : librarys) {
        if (lb.id == id) {
            cout << "Book ID   -> " << lb.id << endl;
            cout << "Book name -> " << lb.Bookname << endl;
            cout << "Issued    -> " << (lb.BookIssueed ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Book ID not found" << endl;
}

void SearchByTitle(const vector<library>& librarys) {
    string title;
    cout << "Enter book title: ";
    getline(cin >> ws, title);

    bool found = false;
    for (const library& lb : librarys) {
        if (lb.Bookname == title) {
            cout << "Book ID   -> " << lb.id << endl;
            cout << "Book name -> " << lb.Bookname << endl;
            cout << "Issued    -> " << (lb.BookIssueed ? "Yes" : "No") << endl;
            found = true;
        }
    }
    if (!found) cout << "Book title not found!" << endl;
}

void Removebook(vector<library>& librarys) {
    int id;
    cout << "Enter the ID of the book: ";
    cin >> id;

    for (auto lb = librarys.begin(); lb != librarys.end(); lb++) {
        if (lb->id == id) {
            if (lb->BookIssueed) {
                cout << "Book is currently issued, can't remove it!" << endl;
                return;
            }
            librarys.erase(lb);
            cout << "Book removed successfully!" << endl;
            return;
        }
    }
    cout << "ID doesn't match any book" << endl;
}

void BookIssue(vector<library>& librarys) {
    int id;
    cout << "Enter the ID of the book: ";
    cin >> id;

    for (library& ls : librarys) {
        if (ls.id == id) {
            if (ls.BookIssueed) {
                cout << "Book already issued by someone!" << endl;
                return;
            }
            ls.BookIssueed = true;
            cout << "Book issued successfully!" << endl;
            return;
        }
    }
    cout << "ID doesn't exist" << endl;
}

void BookReturn(vector<library>& librarys) {
    int id;
    cout << "Enter the ID of the book: ";
    cin >> id;

    for (library& ls : librarys) {
        if (ls.id == id) {
            if (!ls.BookIssueed) {
                cout << "Book is already in the library!" << endl;
                return;
            }
            ls.BookIssueed = false;
            cout << "Book returned successfully!" << endl;
            return;
        }
    }
    cout << "ID doesn't exist" << endl;
}

int main() {
    vector<library> lib;
    loadFromFile(lib);                 // <-- load saved books at startup

    int n;
    while (true) {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Add Book" << endl
             << "2. Display All Books" << endl
             << "3. Search book by ID" << endl
             << "4. Remove book" << endl
             << "5. Book Issue" << endl
             << "6. Book Return" << endl
             << "7. Search book by title" << endl
             << "8. Display available books" << endl
             << "9. Exit" << endl
             << "Choice: ";

        if (!(cin >> n)) {             // user typed a non-number
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a number!" << endl;
            continue;
        }

        switch (n) {
        case 1: {
        addbook(lib);          
        saveToFile(lib); break;
        }
        case 2: 
        {Displaybook(lib);                       
        break;
        }
        case 3: 
        {Searchbookbyid(lib);                 
        break;
        }
        case 4: {
        Removebook(lib);       
        saveToFile(lib); break;
        }
        case 5:{ 
        BookIssue(lib);        
        saveToFile(lib); break;
         }
        case 6: {
        BookReturn(lib);       
        saveToFile(lib); break;
        }
        case 7: {
        SearchByTitle(lib);                     
        break;
        }
        case 8: {
        DisplayAvailable(lib);                  
        break;
        }
        case 9: {
        saveToFile(lib); 
        cout << "Goodbye!" << endl; 
        return 0;
        }
        default: {
        cout << "Invalid choice!" << endl;
    }
        }
    }
}