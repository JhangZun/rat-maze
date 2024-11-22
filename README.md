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

3. **Run the Program**:
   After compilation, run the program from the command line.

   ```bash
   ./rat

4. **Provide Input**:
   The program will prompt you to enter the starting position of the rat and the position of the cheese. Enter the row and column    coordinates for both, ensuring they are on open paths and are valid positions within the maze.

   Example:
   
   ```plaintext
   Enter the rat's starting position (row and column): 0 0
   Enter the cheese position (row and column): 4 4
5. **View the Output**:
   The maze will be displayed in real-time, showing the rat's path and its movement towards the cheese. Once the rat finds the cheese, the program will print the number of steps it took to reach the cheese.

   Example Output:

   ```plaintext
   The rat found the cheese in 10 steps!

   Press Enter to exit...
# Visualize the Process
   Here’s a GIF showing the rat solving the maze:

   ![Rat Maze Solver GIF](https://github.com/JhangZun/rat-maze/blob/main/rat_maze.gif)

# Code Overview
   - **DFS Algorithm**:
        The program uses a stack to explore the maze using a depth-first search strategy.
   - **Maze Representation**:
        The maze is represented by a 2D array of integers, where 1 represents open paths and 0 represents walls.
   - **Visualization**:
        The maze is visualized by printing it in the terminal, and the rat's position is updated as it moves.

# Dependencies
   - **No external libraries**: 
      The program is implemented using standard C++ libraries only.
   
> [!NOTE]
> Feel free to use my code as you want.
