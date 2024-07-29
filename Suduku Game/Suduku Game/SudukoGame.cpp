#include <iostream>
using namespace std;
//The Grid can be 9 or for higher level it can vary
//Setting Fix size to 9 for Sudoku Grid
#define SIZE 9

bool BackTracking(int sudoku[SIZE][SIZE]) {
    //r for Row and c for Column
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            //if Any row of column is = 0 than replace num and check its validity
            if (sudoku[r][c] == 0) {
                for (int n = 1; n <= SIZE; n++) {
                    // Check if placing n in grid[r][c] is valid
                    bool placement = true;
                    for (int x = 0; x < SIZE; x++) {
                        //Checking of Number in Horizontal and Vertical of Sudoku Grid row % 3 + num / 3 and vice versa for Column
                        // Checking if first Row is equal to NUMBER than Column = NUMBER and than down and right or left side of grid
                        if (sudoku[r][x] == n || sudoku[x][c] == n || sudoku[r - r % 3 + x / 3][c - c % 3 + x % 3] == n) {
                            //if Any of it is true than placement would be false checking another number
                            placement = false;
                            break;
                        }
                    }
                    if (placement) {
                        sudoku[r][c] = n;
                        if (BackTracking(sudoku)) {
                            return true;
                        }
                        sudoku[r][c] = 0;// num with 0
                    }
                }
                return false; // backtracking
            }
        }
    }
    return true; // If 0 are filled than sudoku solved
}

int main() {
    int sudoku[SIZE][SIZE] = {
        {0, 0, 7, 0, 0, 3, 4, 9, 6},
        {9, 3, 0, 0, 5, 0, 0, 1, 8},
        {8, 2, 0, 0, 0, 9, 7, 0, 0},
        {0, 0, 5, 3, 8, 7, 0, 0, 2},
        {6, 0, 0, 0, 9, 0, 0, 0, 0},
        {0, 9, 0, 5, 1, 6, 0, 0, 0},
        {4, 5, 9, 0, 0, 1, 0, 0, 7},
        {3, 0, 0, 2, 7, 0, 0, 0, 0},
        {0, 6, 2, 0, 4, 0, 0, 3, 1}
    };

    if (BackTracking(sudoku)) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                cout << sudoku[row][col] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "The Sudoku Grid is Invalid" << endl;
    }
}
