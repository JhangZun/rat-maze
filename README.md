# Rat Maze Solver

This project is a simple C++ program that implements a rat maze solver using a stack-based depth-first search (DFS) algorithm. The program visualizes the maze and updates the terminal in real-time as the rat explores the maze to find the cheese. The rat's path is displayed, and when it reaches the cheese, the solution is printed along with the number of steps it took to reach the destination.

## Features

- [x] **Real-time Maze Visualization**: The maze is updated in the terminal during the solving process.
- [x] **DFS Algorithm**: Depth-First Search (DFS) is used to explore the maze from the rat's starting position to the cheese.
- [x] **Path Highlighting**: The rat's movement is visualized using "R" for its position and "C" for the cheese.
- [x] **User Input**: The user can specify the starting position of the rat and the cheese's position (positions are validated).
- [ ] **Input Validation**: Not done yet.

## How to Use

1. **Download file or Clone the Repository**:
   Download the file or clone this repository to your local machine.

2. **Compile the Program**:
   If you're using a terminal or command line, navigate to the project directory and compile the code using a C++ compiler (e.g., `g++`).

   ```bash
   g++ -o rat rat.cpp
