#include <iostream>
#include <vector>
#include <stack>
#include <thread>  // For sleep
#include <chrono>  // For time delays
#include <iomanip> // For formatting
#include <cstdlib> // For system("pause") on Windows

using namespace std;

struct Position {
    int x, y;
    vector<pair<int, int>> path; // Path taken to reach this position
    int steps;                   // Step count to reach this position
};

// Directions: up, down, left, right
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function to check if a position is within bounds and valid
bool isValid(int x, int y, const vector<vector<int>>& maze, const vector<vector<bool>>& visited) {
    int n = maze.size();
    return x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y];
}

// Function to clear the terminal screen
void clearScreen() {
    // Cross-platform terminal clear
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear");  // Linux/macOS
#endif
}

// Function to print the maze with the current path highlighted and rat/cheese symbols
void printMazeWithRealTimeUpdates(const vector<vector<int>>& maze, const vector<pair<int, int>>& path, const pair<int, int>& cheese) {
    vector<vector<char>> display(maze.size(), vector<char>(maze.size(), ' '));

    // Mark the maze with walls and valid paths
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze.size(); ++j) {
            display[i][j] = maze[i][j] ? '.' : '#';
        }
    }

    // Place the cheese in the maze (C)
    display[cheese.first][cheese.second] = 'C';

    // Highlight the path with 'R' for the rat's position
    for (const auto& pos : path) {
        if (display[pos.first][pos.second] != 'C') {
            display[pos.first][pos.second] = 'R';  // Mark the rat's current position with 'R'
        }
    }

    // Print the maze
    for (const auto& row : display) {
        for (const auto& cell : row) {
            cout << setw(3) << cell << ' ';
        }
        cout << endl;
    }
}

// Function to solve the maze with real-time updates and cheese
bool solveRatMazeWithUpdates(const vector<vector<int>>& maze, const pair<int, int>& cheese) {
    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    stack<Position> s;

    // Push starting position
    s.push({0, 0, {{0, 0}}, 0});
    visited[0][0] = true;

    while (!s.empty()) {
        Position current = s.top();
        s.pop();

        int x = current.x;
        int y = current.y;

        // Clear screen and display current maze state
        clearScreen();
        printMazeWithRealTimeUpdates(maze, current.path, cheese);
        this_thread::sleep_for(chrono::milliseconds(200)); // 200 ms delay

        // If destination is reached (the cheese)
        if (x == cheese.first && y == cheese.second) {
            clearScreen();
            printMazeWithRealTimeUpdates(maze, current.path, cheese);
            cout << "\nThe rat found the cheese in " << current.steps + 1 << " steps!\n";
            return true;
        }

        // Explore neighbors
        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (isValid(newX, newY, maze, visited)) {
                visited[newX][newY] = true;
                vector<pair<int, int>> newPath = current.path;
                newPath.emplace_back(newX, newY);
                s.push({newX, newY, newPath, current.steps + 1});
            }
        }
    }

    cout << "\nNo Path Found.\n";
    return false;
}

int main() {
    // Example Larger Maze with Cheese position
    vector<vector<int>> maze = {
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1},
    };

    // Define the position of the cheese (C)
    pair<int, int> cheese = {6, 6};  // Bottom-right corner (cheese location)

    bool found = solveRatMazeWithUpdates(maze, cheese);

    // Wait for user input before closing the program
    cout << "\nPress Enter to exit...";
    cin.ignore();
    return 0;
}
