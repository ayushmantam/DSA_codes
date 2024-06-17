#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return {};
    int n = mat[0].size();

    map<int, vector<int>> diagonalMap;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            diagonalMap[i + j].push_back(mat[i][j]);
        }
    }

    vector<int> result;

    for (auto& it : diagonalMap) {
        if (it.first % 2 == 0) {  // If even diagonal, reverse the order
            result.insert(result.end(), it.second.rbegin(), it.second.rend());
        } else {
            result.insert(result.end(), it.second.begin(), it.second.end());
        }
    }

    return result;
}