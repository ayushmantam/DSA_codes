#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int l, m, n;
    // possible directions
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool find(vector<vector<char>> &board, int i, int j, string &word, int idx)
    {
        // we have found the word
        if (idx >= l)
            return true;

        // boundries
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;

        // for visited or not
        char temp = board[i][j];
        board[i][j] = '$';

        // going for all possible directions
        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (find(board, i_, j_, word, idx + 1))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        l = word.length();

        if (m * n < l)
            return false;

        // finding first charachter
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // if first ch found cheking for other characters of word
                if (board[i][j] == word[0] && find(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};