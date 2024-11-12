#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if two characters are in the same row in a given grid
bool checkSameRow(int rows, int cols, char c1, char c2) {
    int startAscii = 33; // Starting ASCII character
    int pos1 = c1 - startAscii;
    int pos2 = c2 - startAscii;
    int row1 = pos1 % rows;
    int row2 = pos2 % rows;
    return row1 == row2;
}

int main() {
    int T;
    cin >> T;
    
    vector<pair<int, int>> possibleGrids;
    int totalChars = 94; // Characters from ASCII 33 to 126 (inclusive)

    // Generate possible (Row, Column) configurations for the 94 characters
    for (int rows = 1; rows <= totalChars; ++rows) {
        if (totalChars % rows == 0) {
            int cols = totalChars / rows;
            if (cols >= rows) { // Ensuring (Row, Column) where Column >= Row
                possibleGrids.push_back({rows, cols});
            }
        }
    }

    // Process each test case
    while (T--) {
        char c1, c2;
        cin >> c1 >> c2;

        vector<pair<int, int>> results;
        for (const auto& grid : possibleGrids) {
            int rows = grid.first;
            int cols = grid.second;

            if (checkSameRow(rows, cols, c1, c2)) {
                results.push_back(grid);
            }
        }

        // Output results for this test case
        for (const auto& result : results) {
            cout << result.first << " " << result.second << "\n";
        }
        cout << "\n"; // Blank line after each test case
    }

    return 0;
}
