/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool row_vaild = false;
        bool col_valid = false;
        bool box_valid = false;

        for (int i = 0; i < 9; i++) //check all rows
        {
            row_vaild = checkRow(board, i);
            if (!row_vaild)
                return false;
        }

        for (int i = 0; i < 9; i++) //check all columns
        {
            col_valid = checkCol(board, i);
            if (!col_valid)
                return false;
        }

        for (int i = 0; i < 9; i += 3)  //check all the boxes
        {
            for (int j = 0; j < 9; j += 3)
            {
                box_valid = checkBox(board, i, j);
                if (!box_valid)
                    return false;
            }
        }

        return true;    // all valid
    }

private:
    bool checkRow(vector<vector<char>>& board, int row)
    {
        vector<char> row_vec;
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] != '.')
            {
                if (find(row_vec.begin(), row_vec.end(), board[row][i]) != row_vec.end())
                    return false;
                else
                    row_vec.push_back(board[row][i]);
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int col)
    {
        vector<char> col_vec;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.')
            {
                if (find(col_vec.begin(), col_vec.end(), board[i][col]) != col_vec.end())
                    return false;
                else
                    col_vec.push_back(board[i][col]);
            }
        }
        return true;
    }

    bool checkBox(vector<vector<char>>& board, int row, int col)
    {
        vector<char> box_vec;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[row + i][col + j] != '.')
                {
                    if (find(box_vec.begin(), box_vec.end(), board[row + i][col + j]) != box_vec.end())
                        return false;
                    else
                        box_vec.push_back(board[row + i][col + j]);
                }
            }
        }
        return true;
    }
};
// @lc code=end

