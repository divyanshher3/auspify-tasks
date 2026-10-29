# Task 3: Student Management System

## Objective

A menu-driven C++ console program for maintaining student records during a session. It supports adding, viewing, searching, updating, and deleting records by student ID.

## Technologies Used

- C++
- Standard library headers: `<iostream>`, `<vector>`, and `<string>`
- A C++ compiler such as `g++`

## Features Implemented

- Add a student with an ID, name, age, and course.
- Prevent adding an ID that already exists.
- Display all records, or report when there are no records.
- Search, update, and delete records by ID.
- Show a menu with an option to exit.

## Program Logic

Each record is represented by a `student` struct. The program stores records in a `vector<student>` created in `main()`. A menu loop dispatches the selected action to `addstd`, `display`, `searchstd`, `updatestd`, or `deleteid`. Names and course names are read with `getline`, so they can contain spaces. Records exist only in memory for the current run.

## Source Files

- `studentManagementSystem.cpp` — defines the student record, menu, and record operations.
- `studentManagementSystem.exe` — Windows executable included in the task folder; rebuild it from the source if needed.
- `screenshort/` — contains the execution screenshots present in the task folder. The directory is named `screenshort` in the project.

## How to Compile and Run

From PowerShell, open the `task3` directory and compile with `g++`:

```powershell
cd path\to\auspify\task3
g++ studentManagementSystem.cpp -o studentManagementSystem.exe
.\studentManagementSystem.exe
```

No external libraries, data files, or configuration are required. A C++ compiler must be installed and available on `PATH`.

## Sample Input and Output

Illustrative example: select Add Student, enter the shown record, then select Display All Students. Menu text is abbreviated here for readability.

```text
Menu choice: 1
enter the Id of the srtudent
101
enter the name of the student
Anika Rao
enter the age
20
enter the course of the student
Computer Science
Student added successfully!

Menu choice: 2
Student id ->101
Student name ->Anika Rao
Student age ->20
Student course ->Computer Science
```

## Testing and Verification

**Performed:** No dedicated tests were run while preparing this README.

**Suggested checks:** Add and display a record; try adding a duplicate ID; search for existing and missing IDs; update an existing record; delete an existing and missing ID; display an empty list; and enter an out-of-range numeric menu choice.

## Limitations and Improvements

- Records are stored only in memory and are lost when the program exits.
- Input validation is limited. Non-numeric input where an integer is expected can put `cin` into a failed state, preventing the menu from working correctly; age values are not range-checked.
- The source has several spelling errors in prompt and status messages, but they do not change the record operations.

## Conclusion

The program provides basic student record management and demonstrates structs, vectors, functions, loops, conditionals, and console input/output in C++.
