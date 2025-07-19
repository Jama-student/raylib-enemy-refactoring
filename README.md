# Tutorial Refactoring Project: Raylib Tower Defense Enemies

This project is a simple example of spawning and moving enemies in a tower defense style game using Raylib in C. The original tutorial showed how to handle enemies with global variables and separate functions.  

I refactored the code to organize all enemy-related data and functions into an `EnemyManager` struct. This change makes the code easier to read and maintain by keeping related things together and reducing global variables.

---

## Original Tutorial Source

The original tutorial demonstrated spawning and updating enemies using a global array and procedural code style. I followed that structure but improved the code by applying clean code and basic design principles.

---

## Changes Made

- Created an `EnemyManager` struct to group enemy data.
- Renamed functions to clearly show they operate on the `EnemyManager`.
- Replaced “magic numbers” with named constants like `SCREEN_WIDTH` and `SCREEN_HEIGHT`.
- Moved away from global variables to improve modularity.

---

## How to Run

- Requires Raylib library installed.
- Compile with your C compiler and link Raylib.
- Run the executable, then press **SPACE** to spawn enemies that move across the screen.

---

## Why I Made These Changes

The refactor improves the organization and clarity of the code. It makes future changes easier because all enemy-related logic is in one place. It also reduces potential bugs caused by uncontrolled global variables.

---

## License

This project is licensed under the MIT License.
