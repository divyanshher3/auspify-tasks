# Task 4: Library Management System

## Objective

A menu-driven C++ console program for managing a small book catalogue. It tracks each book by ID and records whether it is issued or available.

## Technologies Used

- C++
- Standard library headers: `<iostream>`, `<vector>`, `<string>`, and `<fstream>`
- A C++ compiler such as `g++`

## Features Implemented

- Add books with unique IDs and titles.
- Display all books or only available books.
- Search by ID or exact title.
- Issue and return books while preventing duplicate issue/return actions.
- Remove a book unless it is currently issued.
- Load records from and save records to `books.txt`.
- Validate non-numeric menu input and handle invalid menu choices.

## Program Logic

The `library` struct stores a book ID, title, and issued flag. A `vector<library>` holds the records while the program runs. `loadFromFile()` reads records at startup; the menu calls the relevant operation function, and changes from add, remove, issue, and return are written by `saveToFile()`. The text file stores one record per line as an ID, an integer issue flag (`0` or `1`), and the remaining line as the title.

## Source Files

- `libraryManagementSystem.cpp` — record structure, file handling, menu, and book operations.
- `books.txt` — sample persistent book data, read and written relative to the program's current working directory.
- `libraryManagementSystem.exe` — Windows executable included in the task folder; rebuild it from the source if needed.
- `screenshort/` — contains the execution screenshots present in the task folder. The directory is named `screenshort` in the project.

## How to Compile and Run

From PowerShell, run these commands from the `task4` directory so the program finds `books.txt` there:

```powershell
cd path\to\auspify\task4
g++ libraryManagementSystem.cpp -o libraryManagementSystem.exe
.\libraryManagementSystem.exe
```

No external libraries or configuration are required. A C++ compiler must be installed and available on `PATH`. If `books.txt` is absent, the program starts with an empty catalogue and creates the file when it saves.

## Sample Input and Output

Illustrative example using the existing `books.txt` entry with ID `101` and title `MCA`:

```text
Choice: 3
Enter the ID of the book: 101
Book ID   -> 101
Book name -> MCA
Issued    -> No
```

The displayed catalogue depends on the contents of `books.txt` in the working directory.

## Testing and Verification

**Performed:** No dedicated tests were run while preparing this README.

**Suggested checks:** Add a book and verify it persists after restarting; try a duplicate ID; display all and available books; search for existing and missing IDs and titles; issue an available book, try issuing it again, return it, and try returning it again; and confirm an issued book cannot be removed. Also try non-numeric and out-of-range menu choices.

## Limitations and Improvements

- Searches by title require an exact, case-sensitive match.
- Numeric inputs for book IDs are not validated; non-numeric input at these prompts can leave the input stream in a failed state.
- The program reports file-open failure when saving, but does not otherwise recover or confirm that changes were persisted.
- The file format uses whitespace separators for ID and issue status, with the rest of the line as the title; it has no escaping for embedded newlines.

## Conclusion

The program demonstrates structs, vectors, functions, menu-driven control flow, file input/output, and basic state management for a book catalogue in C++.
