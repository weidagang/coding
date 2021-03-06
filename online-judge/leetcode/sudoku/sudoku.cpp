#include<cstdio>
#include<vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<int> > masks;
        _initMasks(masks, board);

        bool ok = _search(board, masks, 0, 0);
    }

private:
    void _initMasks(vector<vector<int> >& masks, const vector<vector<char> >& board) {
        for (int i = 0; i < 9; ++i) {
            masks.push_back(vector<int>());
            for (int j = 0; j < 9; ++j) {
                masks[i].push_back(_getMask(board, i, j));
                //printf("mask[%d][%d]=0x%x\n", i, j, masks[i][j]);
            }
        }
    }

    int _getMask(const vector<vector<char> >& board, int i, int j) {
        int mask = 0x000001ff;
        if ('.' != board[i][j]) {
            mask = 1 << (board[i][j] - '1');
        }
        else {
            for (int x = 0; x < 9; ++x) {
                if ('.' != board[x][j]) {
                    mask &= ~(1 << board[x][j] - '1');
                }
            }

            for (int y = 0; y < 9; ++y) {
                if ('.' != board[i][y]) {
                    mask &= ~(1 << board[i][y] - '1');
                }
            }

            for (int x = 3 * (i/3); x < 3 * (i/3 + 1); ++x) {
                for (int y = 3 * (j/3); y < 3 * (j/3 + 1); ++y) {
                    if ('.' != board[x][y]) {
                        mask &= ~(1 << board[x][y] - '1');
                    }
                }
            }
        }
        //printf("board[%d][%d]=%c, mask=0x%x\n", i, j, board[i][j], mask);
        return mask;
    }

    bool _search(vector<vector<char> >& board, vector<vector<int> >& masks, int i, int j) {
        if (9 == i) {
            return true;
        }

        if (9 == j) {
            return _search(board, masks, i + 1, 0);
        }

        if ('.' != board[i][j]) {
            return _search(board, masks, i, j + 1);
        }

        for (int v = 0; v < 9; ++v) {
            if ((masks[i][j] & (1 << v)) && _isValid(board, v, i, j)) {
                board[i][j] = v + '1';
                bool ok = _search(board, masks, i, j + 1);
                if (ok) {
                    return true;
                }
                board[i][j] = '.';
            }
        }

        return false;
    }

    bool _isValid(vector<vector<char> >& board, char v, int i, int j) {
        for (int x = 0; x < i; ++x) {
            if (board[x][j] == v + '1') {
                return false;
            }
        }

        for (int y = 0; y < j; ++y) {
            if (board[i][y] == v + '1') {
                return false;
            }
        }

        for (int x = 3 * (i/3); x < 3 * (i/3 + 1); ++x) {
            for (int y = 3 * (j/3); y < 3 * (j/3 + 1); ++y) {
                if (board[x][y] == v + '1') {
                    return false;
                }
            }
        }

        return true;
    }

private:
    vector<vector<char> > mSolution;
};

int main() {
    vector<vector<char> > board;
    for (int i = 0; i < 9; ++i) {
        board.push_back(vector<char>());
    }
    
    //1
    board[0].push_back('5'); board[0].push_back('3'); board[0].push_back('.');
    board[0].push_back('.'); board[0].push_back('7'); board[0].push_back('.');
    board[0].push_back('.'); board[0].push_back('.'); board[0].push_back('.');

    //2
    board[1].push_back('6'); board[1].push_back('.'); board[1].push_back('.'); 
    board[1].push_back('1'); board[1].push_back('9'); board[1].push_back('5');
    board[1].push_back('.'); board[1].push_back('.'); board[1].push_back('.');

    //3
    board[2].push_back('.'); board[2].push_back('9'); board[2].push_back('8');
    board[2].push_back('.'); board[2].push_back('.'); board[2].push_back('.');
    board[2].push_back('.'); board[2].push_back('6'); board[2].push_back('.');

    //4
    board[3].push_back('8'); board[3].push_back('.'); board[3].push_back('.');
    board[3].push_back('.'); board[3].push_back('6'); board[3].push_back('.');
    board[3].push_back('.'); board[3].push_back('.'); board[3].push_back('3');

    //5
    board[4].push_back('4'); board[4].push_back('.'); board[4].push_back('.');
    board[4].push_back('8'); board[4].push_back('.'); board[4].push_back('3');
    board[4].push_back('.'); board[4].push_back('.'); board[4].push_back('1');

    //6
    board[5].push_back('7'); board[5].push_back('.'); board[5].push_back('.');
    board[5].push_back('.'); board[5].push_back('2'); board[5].push_back('.');
    board[5].push_back('.'); board[5].push_back('.'); board[5].push_back('6');

    //7
    board[6].push_back('.'); board[6].push_back('6'); board[6].push_back('.');
    board[6].push_back('.'); board[6].push_back('.'); board[6].push_back('.');
    board[6].push_back('2'); board[6].push_back('8'); board[6].push_back('.');

    //8
    board[7].push_back('.'); board[7].push_back('.'); board[7].push_back('.');
    board[7].push_back('4'); board[7].push_back('1'); board[7].push_back('9');
    board[7].push_back('.'); board[7].push_back('.'); board[7].push_back('5');

    //9
    board[8].push_back('.'); board[8].push_back('.'); board[8].push_back('.');
    board[8].push_back('.'); board[8].push_back('8'); board[8].push_back('.');
    board[8].push_back('.'); board[8].push_back('7'); board[8].push_back('9');

    Solution s;
    s.solveSudoku(board);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] < '1' || board[i][j] > '9') {
                printf("INVALID\n");
            }

            for (int k = 0; k < j; ++k) {
                if (board[i][j] == board[i][k]) {
                    printf("INVALID\n");
                }
            }
        }
    }

    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < i; ++k) {
                if (board[i][j] == board[k][j]) {
                    printf("INVALID\n");
                }
            }
        }
    }

    return 0;
}
