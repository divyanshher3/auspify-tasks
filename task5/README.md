# Task 5: Banking Management System

## Objective

A menu-driven C++ console application for managing basic bank account records. It supports account lookup and PIN-verified balance operations, with account and transaction data stored in local text files.

## Technologies Used

- C++
- Standard library headers: `<iostream>`, `<vector>`, `<string>`, and `<fstream>`
- A C++ compiler such as `g++`

## Features Implemented

- Create accounts with a unique account number, holder name, non-negative opening balance, and four-digit PIN.
- Display account details and list account names and numbers.
- Search accounts by account number or exact holder name.
- Deposit and withdraw funds after PIN verification, with positive-amount and sufficient-balance checks.
- Check balance and view transaction history after PIN verification.
- Transfer funds between different existing accounts, recording sender and receiver entries.
- Close an account after PIN verification, only when its balance is zero.
- Load and save account data and transaction history in text files.

## Program Logic

An `account` struct stores the account number, holder name, balance, and PIN. A `Transaction` struct stores the account number, transaction type, and amount. `main()` loads both collections into vectors, then repeatedly displays a menu and calls the matching operation. Account changes are saved to `accountrecord`; transaction entries are appended to `TransactionRecord`. PIN checks are performed for deposits, withdrawals, balance inquiries, transaction history, transfers, and account closure. Account detail display and name/number searches do not require a PIN.

## Source Files

- `bankingManagementSystem.cpp` — account and transaction structures, file handling, menu, and banking operations.
- `accountrecord` — account data loaded and overwritten by the program. The current file contains sample records; PINs are stored as plain text.
- `TransactionRecord` — transaction history loaded by the program and appended to after successful deposits, withdrawals, and transfers.
- `TransectionRecord` — an additional misspelled file present in the folder; the source code does not reference it.
- `bankingManagementSystem.exe` — Windows executable included in the task folder; rebuild it from the source if needed.
- `screenshot/` — contains the execution screenshots present in the task folder.

## How to Compile and Run

From PowerShell, run the commands from the `task5` directory so the program reads and writes the expected data files there:

```powershell
cd path\to\auspify\task5
g++ bankingManagementSystem.cpp -o bankingManagementSystem.exe
.\bankingManagementSystem.exe
```

No external libraries or configuration are required. A C++ compiler must be installed and available on `PATH`. If the data files are missing, the program starts with empty collections; account data is written when saved, and transaction history is appended when transactions occur.

## Sample Input and Output

Illustrative example using the existing `accountrecord` entry for account `1001`. The PIN shown is present in the sample data file and is included here only to illustrate the program's input flow.

```text
Enter your choice: 5
Enter the account number
1001
Please enter the PIN for verification: 1234
Your current balance is :4000
```

## Testing and Verification

**Performed:** No dedicated tests were run while preparing this README.

**Suggested checks:** Create an account with valid fields, then try a duplicate number, negative initial balance, and PIN outside the four-digit range. Test successful and incorrect-PIN deposits and withdrawals, zero/negative amounts, and a withdrawal or transfer above the available balance. Also check missing accounts, transfers to self, transaction history, closure with non-zero and zero balances, and non-numeric menu input.

## Limitations and Improvements

- PINs are stored in plain text in `accountrecord`; this is not suitable for real financial use. Account numbers, names, and balances are also stored without encryption or access controls.
- Non-numeric input is handled at the main menu, but numeric prompts inside operations do not consistently recover from invalid input.
- Account names are written as the remainder of the line and loaded with `getline`, but the format has no escaping for embedded newlines.
- Transactions store only account number, type, and amount; they do not include a timestamp or transfer counterpart details.
- This is an educational, local-file program, not a production banking system.

## Conclusion

The program demonstrates structs, vectors, functions, menu-driven control flow, PIN checks, validation, and file input/output through a basic account management workflow.
