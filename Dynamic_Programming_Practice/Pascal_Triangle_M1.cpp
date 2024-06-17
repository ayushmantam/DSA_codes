#include <iostream>
#include <vector>
using namespace std;

int generatePascalsValue(int row, int col) {
    if (col == 0 || col == row) {  //we can see that every row start and ends with one
        return 1;  
    } else {
        return generatePascalsValue(row - 1, col - 1) + generatePascalsValue(row - 1, col);
    }
}

void generatePascalsTriangleRecursive(vector<vector<int>>& triangle, int numRows, int currentRow) {
    if (currentRow == numRows) {
        return;
    }

    vector<int> row;
    for (int col = 0; col <= currentRow; ++col) {
        row.push_back(generatePascalsValue(currentRow, col));
    }

    triangle.push_back(row);
    generatePascalsTriangleRecursive(triangle, numRows, currentRow + 1);
}

int main() {
    int numRows = 5;
    vector<vector<int>> result;

    generatePascalsTriangleRecursive(result, numRows, 0);

    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
