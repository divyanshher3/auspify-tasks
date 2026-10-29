# Task 2: Number Guessing Game

## Objective

A console-based C++ game that asks the player to guess a randomly generated integer from 1 to 50. It gives a higher or lower hint after each valid guess.

## Technologies Used

- C++
- Standard library headers: `<iostream>`, `<cstdlib>`, and `<ctime>`
- A C++ compiler such as `g++`

## Features Implemented

- Generates a number in the range 1–50 using `rand()` seeded with the current time.
- Reads guesses from standard input and provides higher/lower hints.
- Rejects numeric guesses outside the allowed range and reports non-numeric input.
- Reports the number of valid guesses when the player wins.

## Program Logic

`main()` seeds the pseudo-random number generator with `time(0)` and selects the target with `rand() % 50 + 1`. It then repeatedly reads an integer guess. Values outside 1–50 are rejected; an input failure prints an error and ends the game. For an in-range guess, the program prints a hint or, if the guess matches, prints a success message and the guess count before exiting.

## Source Files

- `numberGuessingGame.cpp` — game implementation.
- `numberGuessingGame.exe` — Windows executable included in the task folder; rebuild it from the source if needed.
- `screenshots/` — execution screenshots included with this task.

## How to Compile and Run

From PowerShell, open the `task2` directory and compile with `g++`:

```powershell
cd path\to\auspify\task2
g++ numberGuessingGame.cpp -o numberGuessingGame.exe
.\numberGuessingGame.exe
```

No external libraries or additional data files are required. A C++ compiler must be installed and available on `PATH`.

## Sample Input and Output

Illustrative example only: suppose the randomly selected target is 27.

```text
Guess the number from 1 to 50
Enter your guess
12
HINT: Think of a higher number
Enter your guess
35
HINT: think of a lower number
Enter your guess
27
Yeah !! you guessed right number
Number of gusses :3
```

The target and hints depend on the random number generated in each run.

## Testing and Verification

**Performed:** The source compiled successfully with `g++`. A non-numeric input smoke check (`abc`) displayed the input error and ended the game.

**Suggested checks:** Try a low and high guess to confirm the hints, the correct guess to confirm the win message and count, numeric values below 1 and above 50 to check range validation, and non-numeric input to confirm the input-error path.

## Limitations and Improvements

- Non-numeric input ends the game instead of prompting again.
- The guess counter counts only in-range guesses; out-of-range guesses do not increase it.
- `rand()` is a basic pseudo-random generator and `% 50` can introduce slight distribution bias. A modern C++ random engine could avoid this.
- The displayed count contains a spelling error (“gusses”) in the source.

## Conclusion

The program demonstrates console input/output, loops, conditionals, basic input validation, pseudo-random number generation, and counting guesses in C++.
