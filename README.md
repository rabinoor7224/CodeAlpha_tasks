# Sudoku Solver (C++)

A Sudoku Solver implemented in C++ using Recursion and Backtracking.

## Overview

This project solves a standard 9×9 Sudoku puzzle. Empty cells are represented by `'.'`.

## Features

- Solves any valid 9×9 Sudoku puzzle.
- Uses Recursion and Backtracking.
- Validates every move using Sudoku constraints.

## Algorithm

1. Traverse the board row by row.
2. If the current cell is empty, try digits `1` to `9`.
3. Place digit only if it is safe.
4. If the current cell is already filled, move to the next cell.
5. Backtrack if no valid digit can be placed.

## Language

- C++

## Author

**Rabi un Noor**
